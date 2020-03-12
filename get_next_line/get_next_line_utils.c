/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:14:01 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/24 13:51:04 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_abort(t_gnl **lst)
{
	t_gnl *iterator;

	if (*lst)
	{
		iterator = *lst;
		while (*lst)
		{
			iterator = iterator->next;
			free((*lst)->content);
			free(*lst);
			*lst = iterator;
		}
		*lst = NULL;
	}
	return (NULL);
}

int		gnl_free(t_gnl **lst, t_gnl *current)
{
	if (*lst && gnl_scan(current->content) == 0)
	{
		if (current->before && current->next)
		{
			(current->before)->next = (current->next);
			(current->next)->before = (current->before);
		}
		else if (current->next == NULL && current->before)
			(current->before)->next = NULL;
		else if (current->before == NULL && current->next)
		{
			(current->next)->before = NULL;
			*lst = current->next;
		}
		if (current->before || current->next)
		{
			free(current->content);
			free(current);
		}
		else
			gnl_abort(lst);
	}
	return (0);
}

int		gnl_scan(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (-1);
	return (i);
}

t_gnl	*gnl_scan_fd(t_gnl *lst, int fd)
{
	t_gnl	*iterator;

	iterator = lst;
	while (iterator)
	{
		if (iterator->fd == fd)
			return (iterator);
		iterator = iterator->next;
	}
	return (0);
}

t_gnl	*gnl_lstnew_addfront(void *content, int fd, t_gnl **alst)
{
	t_gnl *mylist;

	if ((mylist = malloc(sizeof(t_gnl))) == NULL)
		return (NULL);
	mylist->content = gnl_strdup(content, *alst);
	mylist->fd = fd;
	mylist->size = 0;
	mylist->before = NULL;
	mylist->next = NULL;
	if ((*alst))
	{
		mylist->next = (*alst);
		(*alst)->before = mylist;
		*alst = mylist;
	}
	else
		*alst = mylist;
	return (mylist);
}
