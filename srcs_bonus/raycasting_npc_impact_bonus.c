/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_npc_impact_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:31:11 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 14:20:09 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
				ray->npc[ray->nb] = *iter;
			}
		}
		iter = iter->next;
	}
	ft_sort_npc(win);
	return (0);
}
