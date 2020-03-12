/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_npc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:14:14 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/24 13:53:05 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_get_x_offset_npc(t_win *win, t_npc npc, t_img *s_img)
{
	npc.t_offset.x = (win->cb_s / 2) - npc.sin_diff * npc.dist;
	npc.t_offset.x = (npc.t_offset.x <= 0 ? 0 : npc.t_offset.x);
	npc.t_offset.x = (npc.t_offset.x >= win->cb_s ? win->cb_s : npc.t_offset.x);
	npc.t_offset.x = (npc.t_offset.x / win->cb_s) * s_img->reso.x;
	return (npc.t_offset.x);
}

int	ft_get_y_offset_npc(int y, t_npc npc, t_img *s_img)
{
	npc.t_offset.y = ((y - npc.real_pos_y) / npc.real_size) * s_img->reso.y;
	return (npc.t_offset.y);
}

int	ft_draw_3d_npc(t_win *win, t_bkg *bkg, t_screen *screen)
{
	t_mtx	dst;
	t_mtx	src;
	t_npc	npc;

	dst.d_x = screen->pos.x;
	if (win->player->ray->nb > -1)
	{
		while (win->player->ray->nb >= 0)
		{
			npc = win->player->ray->npc[win->player->ray->nb];
			dst.d_y = npc.pos_y;
			while (dst.d_y < npc.pos_y + npc.size)
			{
				src.d_x = ft_get_x_offset_npc(win, npc, npc.s_img);
				src.d_y = ft_get_y_offset_npc(dst.d_y, npc, npc.s_img);
				ft_chg_pxl(bkg->img, dst, npc.s_img, src);
				dst.d_y++;
			}
			win->player->ray->nb--;
		}
	}
	return (0);
}

int	ft_set_3d_npc(t_win *win, t_player *player, t_ray *r)
{
	int		i;
	t_reso	reso;

	reso.x = win->bkg->img->reso.x;
	reso.y = win->bkg->img->reso.y;
	i = r->nb;
	while (i >= 0)
	{
		r->npc[i].real_size = round(win->cb_s * (reso.x / 2) /
				(r->npc[i].dist * ft_cos(r->f, player->pos.ang
				- r->pos.ang) * r->tan_h_fov));
		r->npc[i].size = (r->npc[i].real_size < 0 ? 0 : r->npc[i].real_size);
		r->npc[i].size = (r->npc[i].real_size >= reso.y ?
		reso.y : r->npc[i].real_size);
		r->npc[i].real_pos_y = (reso.y / 2) - (r->npc[i].real_size / 2);
		r->npc[i].pos_y = round((reso.y / 2) - (r->npc[i].size / 2));
		i--;
	}
	return (0);
}
