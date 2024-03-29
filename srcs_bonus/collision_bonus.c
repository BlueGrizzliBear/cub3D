/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 17:00:26 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 08:54:06 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	ft_prep_coll_x(t_win *win, t_player *player, t_pos new_pos)
{
	t_pos test_pos;

	test_pos = player->pos;
	test_pos.x = new_pos.x;
	test_pos.ang = get_angle(test_pos, player->pos);
	player->ray->pos = test_pos;
	ft_pre_process_angles(player->ray, player->ray->pos.ang);
	ft_pre_process_mod(player->ray, win->cb_s);
	return (0);
}

int	ft_check_coll_x(t_ray *ray, t_win *win)
{
	ray->mtx_one_sqr = ft_set_one_sqr_mtx(ray, win);
	ray->sqr_pos = ft_get_sqr_pos(ray, win->cb_s, ray->mtx_one_sqr);
	if (ft_compare(ray->sqr_pos, win->mmap, win->cb_s) == 1)
		return (1);
	return (0);
}

int	ft_prep_coll_y(t_win *win, t_player *player, t_pos new_pos)
{
	t_pos test_pos;

	test_pos.x = player->pos.x;
	test_pos.y = new_pos.y;
	test_pos.ang = get_angle(test_pos, player->pos);
	player->ray->pos = test_pos;
	ft_pre_process_angles(player->ray, player->ray->pos.ang);
	ft_pre_process_mod(player->ray, win->cb_s);
	return (0);
}

int	ft_check_coll_y(t_ray *ray, t_win *win)
{
	ray->mtx_one_sqr = ft_set_one_sqr_mtx(ray, win);
	ray->sqr_pos = ft_get_sqr_pos(ray, win->cb_s, ray->mtx_one_sqr);
	if (ft_compare(ray->sqr_pos, win->mmap, win->cb_s) == 1)
		return (1);
	return (0);
}
