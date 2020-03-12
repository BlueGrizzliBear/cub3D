/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_npc_impact.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:31:11 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 12:57:29 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int		ft_check_npc_impact(t_win *win, t_ray *ray)
{
	t_npc	*iter;

	iter = win->npc;
	while (iter)
	{
		iter->diff_ang = ray->pos.ang - iter->center.ang;
		if (ft_cos(ray->f, iter->diff_ang) > 0)
		{
			iter->cos_diff = ft_cos(ray->f, iter->diff_ang);
			iter->sin_diff = ft_sin(ray->f, iter->diff_ang);
			iter->dist = iter->center_dist / iter->cos_diff;
			iter->impact.x = win->player->pos.x + ray->cos_ang * iter->dist;
			iter->impact.y = win->player->pos.y - ray->sin_ang * iter->dist;
			if (iter->dist < ray->size
			&& fabs(iter->dist * iter->sin_diff) <= win->cb_s / 2)
			{
				win->player->ray->nb++;
				win->player->ray->npc[win->player->ray->nb] = *iter;
			}
		}
		iter = iter->next;
	}
	ft_sort_npc(win);
	return (0);
}
