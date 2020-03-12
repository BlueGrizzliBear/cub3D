/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:20:09 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/25 11:31:04 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_count_characters_on_line(char *line, char *charset)
{
	int		i;
	int		k;
	int		size;

	i = 0;
	k = 0;
	size = 0;
	while (line[i])
	{
		while (charset[k] && charset[k] != line[i])
			k++;
		if (charset[k] == line[i])
			size++;
		k = 0;
		i++;
	}
	return (size);
}

char	*ft_get_map_characters_only(t_win *win, char *line, char *charset)
{
	char	*str;
	int		i;
	int		j;
	int		k;
	int		size;

	size = ft_count_characters_on_line(line, charset);
	if (!(str = malloc(sizeof(char) * (size + 1))))
		ft_error(-31, win);
	i = 0;
	j = 0;
	while (line[i])
	{
		i += ft_pass_spaces(&line[i]);
		k = 0;
		while (charset[k] && charset[k] != line[i])
			k++;
		if (charset[k] == line[i])
			str[j++] = line[i];
		else if (line[i] != ' ')
			ft_error(-11, win);
		i++;
	}
	str[j] = '\0';
	return (str);
}

int		ft_join_map_lines(char *line, t_win *win, t_input *in)
{
	char	*s1;
	char	*s2;

	if (!(s1 = ft_get_map_characters_only(win, line, in->charset)))
		ft_error(-11, win);
	s2 = ft_strjoinfree(in->map_lines, s1, 1);
	in->map_lines = ft_strjoinfree(s2, ft_strdup("\n"), 2);
	free(s1);
	free(s2);
	in->max.y++;
	return (1);
}
