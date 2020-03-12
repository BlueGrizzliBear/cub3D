/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_bkg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:16:48 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 10:04:34 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_get_side(t_screen *screen, t_mtx mtx)
{
	if (mtx.d_x == 1 && (mtx.d_y == 0 || mtx.d_y == -1))
		screen->current = screen->we_img;
	else if ((mtx.d_x == 0 || mtx.d_x == 1) && mtx.d_y == 1)
		screen->current = screen->so_img;
	else if (mtx.d_x == -1 && (mtx.d_y == 0 || mtx.d_y == 1))
		screen->current = screen->ea_img;
	else if ((mtx.d_x == 0 || mtx.d_x == -1) && mtx.d_y == -1)
		screen->current = screen->no_img;
	else
		screen->current = NULL;
	return (1);
}

int	ft_get_x_offset(t_win *win, t_screen *s, t_img *src_img)
{
	t_pos	mod;

	mod.x = fmod(win->player->ray->pos.x, win->cb_s);
	mod.y = fmod(win->player->ray->pos.y, win->cb_s);
	if (mod.x == 0 && mod.y == 0)
		s->t_offset.x = 0;
	else if (s->orientation.d_x == -1)
		s->t_offset.x = (src_img->reso.x * (win->cb_s - mod.y)) / win->cb_s;
	else if (s->orientation.d_x == 1)
		s->t_offset.x = (src_img->reso.x * (mod.y)) / win->cb_s;
	else if (s->orientation.d_x == 0 && s->orientation.d_y == 1)
		s->t_offset.x = (src_img->reso.x * (mod.x)) / win->cb_s;
	else if (s->orientation.d_x == 0 && s->orientation.d_y == -1)
		s->t_offset.x = (src_img->reso.x * (win->cb_s - mod.x)) / win->cb_s;
	else
		s->t_offset.x = 0;
	return (round(s->t_offset.x));
}

int	ft_draw_3d_bkg(t_win *win, t_bkg *bkg, t_screen *screen)
{
	int		y;
	t_mtx	dst;
	t_mtx	src;

	y = -1;
	dst.d_x = screen->pos.x;
	ft_get_side(screen, screen->orientation);
	src.d_x = ft_get_x_offset(win, screen, screen->current);
	while (++y < bkg->img->reso.y)
	{
		dst.d_y = y;
		if (y < screen->pos.y)
			ft_chg_pxl_clr(bkg->img, dst.d_x, dst.d_y, screen->c_color);
		else if (y >= screen->pos.y && y < screen->pos.y + screen->size)
		{
			screen->t_offset.y = ((y - screen->real_pos_y) / screen->real_size)
			* screen->current->reso.y;
			src.d_y = screen->t_offset.y;
			ft_chg_pxl(bkg->img, dst, screen->current, src);
		}
		else if (y >= screen->pos.y + screen->size)
			ft_chg_pxl_clr(bkg->img, dst.d_x, dst.d_y, screen->f_color);
	}
	return (0);
}

int	ft_set_3d_bkg(t_win *win, t_player *player, t_ray *ray)
{
	double	fixed_ray;
	double	fixed_ang;
	t_reso	reso;

	reso.x = win->bkg->img->reso.x;
	reso.y = win->bkg->img->reso.y;
	fixed_ang = ft_mod(fabs(player->pos.ang - ray->pos.ang), 2 * M_PI);
	fixed_ray = ft_cos(win->f, fixed_ang) * ray->size;
	win->screen->real_size = round(((win->cb_s) * (reso.x / 2) /
	(fixed_ray * ray->tan_h_fov)));
	win->screen->size = (win->screen->real_size <= 0 ?
	0 : win->screen->real_size);
	win->screen->size = (win->screen->real_size >= reso.y ?
	reso.y : win->screen->real_size);
	win->screen->real_pos_y = (reso.y / 2) - (win->screen->real_size / 2);
	win->screen->pos.y = round((reso.y / 2) - (win->screen->size / 2));
	return (0);
}
