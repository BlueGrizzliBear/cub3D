/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npc_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 22:09:20 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 12:59:26 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_sort_npc2(t_win *win, t_npc *iter, t_npc *iter_n, t_npc *iter_b)
{
	iter->next = iter_n->next;
	iter_n->next = iter;
	if (iter_b != NULL)
		iter_b->next = iter_n;
	else
		win->npc = iter_n;
}

int		ft_sort_npc(t_win *win)
{
	t_npc	*iter_before;
	t_npc	*iter;
	t_npc	*iter_next;

	iter_before = NULL;
	iter = win->npc;
	iter_next = win->npc->next;
	while (iter->next)
	{
		if (iter->center_dist > iter_next->center_dist)
		{
			ft_sort_npc2(win, iter, iter_next, iter_before);
			iter_before = NULL;
			iter = win->npc;
			iter_next = win->npc->next;
		}
		else
		{
			iter_before = iter;
			iter = iter_next;
			iter_next = iter_next->next;
		}
	}
	return (0);
}

int		ft_check_skull_form(int j, int i)
{
	if (!(
		(j == 0 && i == 0) || (j == 0 && i == 1) || (j == 0 && i == 5)
		|| (j == 0 && i == 6) || (j == 1 && i == 0)
		|| (j == 1 && i == 6) || (j == 3 && i == 1)
		|| (j == 3 && i == 2) || (j == 3 && i == 4)
		|| (j == 3 && i == 5) || (j == 4 && i == 3)
		|| (j == 6 && i == 0) || (j == 6 && i == 3)
		|| (j == 6 && i == 6) || (j == 7 && i == 0)
		|| (j == 7 && i == 2) || (j == 7 && i == 3)
		|| (j == 7 && i == 4) || (j == 7 && i == 6)
		|| (j == 7 && i == 7)))
		return (1);
	return (0);
}

void	ft_color_skull(int x, int y, t_win *win, t_color color)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < win->cb_s - 2)
	{
		while (i < win->cb_s - 3)
		{
			if (ft_check_skull_form(j, i) == 1)
				ft_chg_pxl_clr(win->mmap->mm_img,
				x - win->mmap->offset.x - win->cb_s / 4 + i,
				y - win->mmap->offset.y - win->cb_s / 4 + j, color);
			i++;
		}
		i = 0;
		j++;
	}
}

int		ft_set_mmap_npc(t_win *win)
{
	t_npc	*it;
	t_mmap	*mmap;

	mmap = win->mmap;
	it = win->npc;
	if (it->id != -1)
	{
		while (it)
		{
			if (it->center.x >= mmap->offset.x && it->center.x < mmap->max.x
			&& it->center.y >= mmap->offset.y && it->center.y < mmap->max.y)
				ft_color_skull(it->center.x, it->center.y, win, it->color);
			it = it->next;
		}
	}
	return (1);
}
