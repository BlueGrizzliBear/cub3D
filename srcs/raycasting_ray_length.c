/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_ray_length.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:25:33 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/24 11:42:35 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_get_ang(t_pos p_pos, t_pos r_pos, t_ray *ray, double q_ang)
{
	double calc_ang;
	double calc;

	if (ray->mtx_c.d_y * ray->mtx_c.d_x == -1)
		calc = (ray->mtx_c.d_y * (r_pos.y - p_pos.y)) /
			(ray->mtx_c.d_x * (r_pos.x - p_pos.x));
	else
		calc = (ray->mtx_c.d_y * (r_pos.x - p_pos.x)) /
			(ray->mtx_c.d_x * (r_pos.y - p_pos.y));
	calc_ang = atan(calc);
	if (q_ang > calc_ang)
		return (1);
	return (0);
}

t_pos	ft_get_current_corner(t_ray *ray, int cb_s, t_mtx mtx_sqr)
{
	if (ray->mod_x != (double)0)
	{
		if (mtx_sqr.d_x == -1)
			ray->pos.x = ray->pos.x + mtx_sqr.d_x * (ray->mod_x);
		else
			ray->pos.x = ray->pos.x + mtx_sqr.d_x * (cb_s - ray->mod_x);
	}
	else
		ray->pos.x = ray->pos.x - ray->mod_x + mtx_sqr.d_x * cb_s;
	if (ray->mod_y != (double)0)
	{
		if (mtx_sqr.d_y == -1)
			ray->pos.y = ray->pos.y + mtx_sqr.d_y * (ray->mod_y);
		else
			ray->pos.y = ray->pos.y + mtx_sqr.d_y * (cb_s - ray->mod_y);
	}
	else
		ray->pos.y = ray->pos.y - ray->mod_y + mtx_sqr.d_y * cb_s;
	return (ray->pos);
}

int		ft_for_special_angle(t_player *player, t_ray *ray)
{
	if (ray->sin_ang == (double)1 || ray->sin_ang == (double)-1)
	{
		ray->size = ray->mtx_c.d_y * (ray->pos.y - player->pos.y);
		ray->pos.x = player->pos.x;
	}
	else
	{
		ray->size = ray->mtx_c.d_x * (ray->pos.x - player->pos.x);
		ray->pos.y = player->pos.y;
	}
	return (0);
}

int		ft_for_normal_angle(t_player *p, t_ray *r, int status)
{
	if (status == -1)
	{
		if (ft_get_ang(p->pos, r->pos, r, r->q_ang) == 1)
		{
			r->size = r->mtx_c.d_y * (r->pos.y - p->pos.y) / r->sin_q_ang;
			r->pos.x = r->mtx_c.d_x * r->cos_q_ang * r->size + p->pos.x;
		}
		else
		{
			r->size = r->mtx_c.d_x * (r->pos.x - p->pos.x) / r->cos_q_ang;
			r->pos.y = r->mtx_c.d_y * r->sin_q_ang * r->size + p->pos.y;
		}
		return (0);
	}
	if (ft_get_ang(p->pos, r->pos, r, r->q_ang) == 1)
	{
		r->size = r->mtx_c.d_y * (r->pos.x - p->pos.x) / r->sin_q_ang;
		r->pos.y = r->mtx_c.d_y * r->cos_q_ang * r->size + p->pos.y;
	}
	else
	{
		r->size = r->mtx_c.d_x * (r->pos.y - p->pos.y) / r->cos_q_ang;
		r->pos.x = r->mtx_c.d_x * r->sin_q_ang * r->size + p->pos.x;
	}
	return (0);
}

int		ft_get_ray_length(t_player *player, t_ray *ray, int cb_s)
{
	int status;

	status = 0;
	ray->pos = ft_get_current_corner(ray, cb_s, ray->mtx_c);
	status = ray->mtx_c.d_x * ray->mtx_c.d_y;
	if (ray->sin_ang == (double)1 || ray->cos_ang == (double)1
	|| ray->sin_ang == (double)-1 || ray->cos_ang == (double)-1)
		ft_for_special_angle(player, ray);
	else
		ft_for_normal_angle(player, ray, status);
	return (0);
}
