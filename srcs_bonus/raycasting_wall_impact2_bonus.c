/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_wall_impact2_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:38:54 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 08:54:06 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_pos	ft_get_sqr_pos(t_ray *ray, int cb_s, t_mtx ext)
{
	if (ray->mod_x == (double)0)
		ray->sqr_pos.x = ray->pos.x + ext.d_x * cb_s;
	else
		ray->sqr_pos.x = ray->pos.x + ext.d_x * (ray->mod_x);
	if (ray->mod_y == (double)0)
		ray->sqr_pos.y = ray->pos.y + ext.d_y * cb_s;
	else
		ray->sqr_pos.y = ray->pos.y + ext.d_y * (ray->mod_y);
	return (ray->sqr_pos);
}

int		ft_compare(t_pos sqr_pos, t_mmap *mmap, int cb_s)
{
	int int_pos_x;
	int int_pos_y;

	int_pos_x = sqr_pos.x / cb_s;
	int_pos_y = sqr_pos.y / cb_s;
	if (mmap->input->map_table[int_pos_y][int_pos_x] == '1')
		return (1);
	else if (mmap->input->map_table[int_pos_y][int_pos_x] == '2')
		return (2);
	return (0);
}

t_mtx	ft_set_two_sqr_mtx(t_ray *ray)
{
	t_mtx side;

	side.d_x = (fabs(ray->cos_ang) == (double)1 ? 0 : -1);
	side.d_y = (fabs(ray->sin_ang) == (double)1 ? 0 : 1);
	return (side);
}

t_mtx	ft_set_three_sqr_mtx(t_ray *ray)
{
	t_mtx side;

	side.d_x = (-1 * ray->cos_ang > 0 ? 1 : -1);
	side.d_y = (ray->sin_ang > 0 ? 1 : -1);
	return (side);
}

int		ft_check_other_cases(t_ray *ray, t_win *win)
{
	t_pos sqr_cpy;

	sqr_cpy = ray->sqr_pos;
	if (ray->cos_ang == 1 || ray->sin_ang == 1
	|| ray->cos_ang == -1 || ray->sin_ang == -1)
	{
		ray->mtx_two_sqr = ft_set_two_sqr_mtx(ray);
		sqr_cpy.x += ray->mtx_two_sqr.d_x * win->cb_s;
		sqr_cpy.y += ray->mtx_two_sqr.d_y * win->cb_s;
		if (ft_compare(sqr_cpy, win->mmap, win->cb_s) == 1)
			return (1);
	}
	else
	{
		ray->mtx_three_sqr = ft_set_three_sqr_mtx(ray);
		sqr_cpy.x += ray->mtx_three_sqr.d_x * win->cb_s;
		if (ft_compare(sqr_cpy, win->mmap, win->cb_s) == 1)
			return (1);
		sqr_cpy.x = ray->sqr_pos.x;
		sqr_cpy.y += ray->mtx_three_sqr.d_y * win->cb_s;
		if (ft_compare(sqr_cpy, win->mmap, win->cb_s) == 1)
			return (1);
	}
	return (0);
}
