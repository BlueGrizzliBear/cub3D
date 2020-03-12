/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_wall_impact.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:28:04 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/24 13:54:37 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_mtx	ft_set_mtx_horiz(t_ray *ray, t_win *win)
{
	t_mtx side;

	if (ray->sin_ang == (double)0)
	{
		side.d_x = (ray->cos_ang == 1 ? 1 : -1);
		side.d_y = 0;
		win->screen->orientation.d_x = (ray->cos_ang == 1 ? 1 : -1);
		win->screen->orientation.d_y = 0;
	}
	else
	{
		side.d_x = -1;
		side.d_y = (ray->sin_ang > 0 ? -1 : 0);
		win->screen->orientation.d_x = 0;
		win->screen->orientation.d_y = (ray->sin_ang > 0 ? 1 : -1);
	}
	return (side);
}

t_mtx	ft_set_mtx_verti(t_ray *ray, t_win *win)
{
	t_mtx side;

	if (ray->cos_ang == (double)0)
	{
		side.d_x = 0;
		side.d_y = (ray->sin_ang == 1 ? -1 : 1);
		win->screen->orientation.d_x = 0;
		win->screen->orientation.d_y = (ray->sin_ang == 1 ? -1 : 1);
	}
	else
	{
		side.d_x = (ray->cos_ang > 0 ? 0 : -1);
		side.d_y = -1;
		win->screen->orientation.d_x = (ray->cos_ang > 0 ? 1 : -1);
		win->screen->orientation.d_y = 0;
	}
	return (side);
}

t_mtx	ft_set_mtx_corners(t_ray *ray, t_win *win)
{
	t_mtx side;

	side.d_x = (ray->cos_ang >= 0 ? 0 : -1);
	side.d_y = (ray->sin_ang >= 0 ? -1 : 0);
	win->screen->orientation.d_x =
		(ft_cos(win->f, ray->pos.ang - M_PI / 4) >= 0 ? 1 : -1);
	win->screen->orientation.d_y =
		(ft_sin(win->f, ray->pos.ang - M_PI / 4) >= 0 ? 1 : -1);
	return (side);
}

t_mtx	ft_set_one_sqr_mtx(t_ray *ray, t_win *win)
{
	t_mtx side;

	if (ray->mod_x == (double)0 && ray->mod_y != (double)0)
		side = ft_set_mtx_verti(ray, win);
	else if (ray->mod_x != (double)0 && ray->mod_y == (double)0)
		side = ft_set_mtx_horiz(ray, win);
	else
		side = ft_set_mtx_corners(ray, win);
	return (side);
}

int		ft_check_impact(t_ray *ray, t_win *win)
{
	ray->mtx_one_sqr = ft_set_one_sqr_mtx(ray, win);
	ray->sqr_pos = ft_get_sqr_pos(ray, win->cb_s, ray->mtx_one_sqr);
	if (ft_compare(ray->sqr_pos, win->mmap, win->cb_s) == 1)
		return (1);
	if (ray->mod_x == (double)0 && ray->mod_y == (double)0)
		if (ft_check_other_cases(ray, win) == 1)
			return (1);
	return (0);
}
