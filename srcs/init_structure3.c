/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 21:55:23 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 10:19:57 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_init_ray(t_win *win)
{
	win->player->ray->pos = win->player->pos;
	win->player->ray->tan_h_fov = ft_tan(win->f, win->player->fov / 2);
	return (0);
}

int	ft_init_screen(t_win *win)
{
	win->screen->pos.x = (double)win->bkg->img->reso.x;
	win->screen->c_color = win->mmap->input->c_color;
	win->screen->f_color = win->mmap->input->f_color;
	win->screen->half_len = SCREEN_DISTANCE * win->player->ray->tan_h_fov;
	win->screen->seg_len = win->screen->half_len / (win->bkg->img->reso.x / 2);
	return (0);
}

int	ft_init_bkg(t_win *win, t_img *img)
{
	img->img_ptr = mlx_new_image(win->mlx_ptr, img->reso.x, img->reso.y);
	img->img_data = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->s_l,
			&img->endian);
	return (0);
}

int	ft_init_hotkey(t_win *win)
{
	win->hotkey.key_w = 0;
	win->hotkey.key_s = 0;
	win->hotkey.key_a = 0;
	win->hotkey.key_d = 0;
	win->hotkey.key_lft_ar = 0;
	win->hotkey.key_rgt_ar = 0;
	win->hotkey.key_lft_mouse = 0;
	win->hotkey.key_rgt_mouse = 0;
	win->hotkey.key_shift = 2;
	return (0);
}
