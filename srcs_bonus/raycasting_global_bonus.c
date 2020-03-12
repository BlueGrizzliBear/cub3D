/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_global_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:23:03 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 08:54:06 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	ft_set_mtx_current_corner(t_ray *ray)
{
	ray->mtx_c.d_x = (ray->cos_ang > 0 ? 1 : -1);
	ray->mtx_c.d_y = (ray->sin_ang > 0 ? -1 : 1);
	return (0);
}

int	ft_pre_process_angles(t_ray *ray, double seg_ang)
{
	ray->pos.ang = seg_ang;
	ray->cos_ang = ft_cos(ray->f, seg_ang);
	ray->sin_ang = ft_sin(ray->f, seg_ang);
	ray->q_ang = ft_mod(seg_ang, M_PI / 2);
	ray->cos_q_ang = ft_cos(ray->f, ray->q_ang);
	ray->sin_q_ang = ft_sin(ray->f, ray->q_ang);
	return (0);
}

int	ft_pre_process_mod(t_ray *ray, int cb_s)
{
	ray->mod_x = fmod(ray->pos.x, cb_s);
	ray->mod_y = fmod(ray->pos.y, cb_s);
	return (0);
}

int	ft_set_2d(t_win *win, t_player *player, t_ray *ray, double seg_ang)
{
	int	ret;

	ray->pos = player->pos;
	ft_pre_process_angles(ray, seg_ang);
	ft_set_mtx_current_corner(ray);
	ft_pre_process_mod(ray, win->cb_s);
	ret = 0;
	while (ret == 0)
	{
		ft_get_ray_length(player, ray, win->cb_s);
		ft_pre_process_mod(ray, win->cb_s);
		ret = ft_check_impact(ray, win);
	}
	ft_check_npc_impact(win, ray);
	return (0);
}

int	ft_raycasting(t_win *win, t_player *player, t_ray *ray)
{
	double	seg_ang;

	win->screen->pos.x = 0;
	while (win->screen->pos.x < win->bkg->img->reso.x)
	{
		seg_ang = atan((win->screen->seg_len * -win->screen->pos.x
		+ win->screen->half_len) / SCREEN_DISTANCE);
		seg_ang = ft_mod(seg_ang + player->pos.ang, 2 * M_PI);
		ft_set_2d(win, player, ray, seg_ang);
		ft_draw_ray_pos(ray, ray->pos, win->mmap);
		ft_init_r_beam(player, ray);
		ft_draw_r_beam(ray, ray->d, ray->s, win->mmap);
		ft_set_3d_bkg(win, player, ray);
		ft_set_3d_npc(win, player, ray);
		ft_draw_3d_bkg(win, win->bkg, win->screen);
		ft_draw_3d_npc(win, win->bkg, win->screen);
		win->screen->pos.x++;
		win->player->ray->nb = -1;
	}
	return (0);
}
