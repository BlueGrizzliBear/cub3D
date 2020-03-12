/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:16:28 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/24 13:51:33 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static t_gnl	*lst;
	t_gnl			*current;
	char			buff[1];

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	current = gnl_scan_fd(lst, fd);
	if (current == 0)
	{
		if (!(current = gnl_lstnew_addfront("", fd, &lst)) ||
				!(read_line(current, fd, lst)))
			return (-1);
	}
	else if (current->fd == fd)
		if (gnl_scan(current->content) != -1)
			if (!(read_line(current, fd, lst)))
				return (-1);
	if (current->size != 0 && gnl_scan(current->content) != -1)
	{
		if ((write_line(current, line, lst)))
			return ((int)gnl_free(&lst, current));
	}
	else if ((write_line(current, line, lst)))
		return (1);
	return (-1);
}

char	*read_line(t_gnl *lst, int fd, t_gnl *alst)
{
	int		ret;

	while (gnl_scan(lst->content) != -1 && lst->size == 0)
	{
		ret = read(fd, lst->temp, BUFFER_SIZE);
		lst->temp[ret] = '\0';
		lst->size = BUFFER_SIZE - ret;
		lst->content = gnl_strjoin(lst->content, lst->temp, alst);
	}
	return (lst->content);
}

char	*write_line(t_gnl *lst, char **line, t_gnl *alst)
{
	char	*str_left;
	char	*str_temp;
	int		i;

	i = 0;
	while (((char*)lst->content)[i] != '\n' && ((char*)lst->content)[i] != '\0')
		i++;
	if (!(str_temp = malloc((i + 1) * sizeof(char))))
		return (gnl_abort(&alst));
	i = 0;
	while (((char*)lst->content)[i] != '\n' && ((char*)lst->content)[i] != '\0')
	{
		str_temp[i] = ((char*)lst->content)[i];
		i++;
	}
	str_temp[i] = '\0';
	*line = gnl_strdup(str_temp, alst);
	free(str_temp);
	str_temp = NULL;
	if (((char*)lst->content)[i] == '\n')
		i++;
	str_left = gnl_strdup(&((char*)lst->content)[i], alst);
	free(lst->content);
	lst->content = str_left;
	return (lst->content);
}

char	*gnl_strdup(const char *s1, t_gnl *alst)
{
	char	*c;
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (s1[size])
		size++;
	if ((c = malloc((size + 1) * sizeof(char))) == NULL)
		return (gnl_abort(&alst));
	i = -1;
	while (++i < size)
		c[i] = s1[i];
	c[i] = '\0';
	return (c);
}

char	*gnl_strjoin(const char *s1, const char *s2, t_gnl *alst)
{
	char	*c;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = -1;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	k = i + j;
	if (!((c = malloc((1 + k) * sizeof(char)))))
		return (gnl_abort(&alst));
	i = -1;
	while (s1[++i])
		c[i] = s1[i];
	j = -1;
	while (s2[++j])
		c[j + i] = s2[j];
	c[j + i] = '\0';
	free((char*)s1);
	s1 = NULL;
	return (c);
}
