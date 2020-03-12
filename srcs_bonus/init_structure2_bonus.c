/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 21:53:04 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 08:54:06 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	ft_resize_image(t_img *src, t_img *dst)
{
	int		k;
	t_reso	s;
	t_reso	d;

	d.y = 0;
	while (d.y < dst->reso.y)
	{
		d.x = 0;
		while (d.x < dst->reso.x)
		{
			s.x = ((double)d.x / (double)dst->reso.x) * src->reso.x;
			s.y = ((double)d.y / (double)dst->reso.y) * src->reso.y;
			k = -1;
			while (++k < 4)
			{
				dst->img_data[4 * d.x + dst->s_l * d.y + k] =
				src->img_data[4 * s.x + src->s_l * s.y + k];
			}
			d.x++;
		}
		d.y++;
	}
	return (0);
}

int	ft_create_screen(t_win *win, t_img *src, t_img *dst)
{
	dst->reso.x = win->bkg->img->reso.x;
	dst->reso.y = win->bkg->img->reso.y;
	dst->offset.x = 0;
	dst->offset.y = 0;
	dst->img_ptr = mlx_new_image(win->mlx_ptr, dst->reso.x, dst->reso.y);
	dst->img_data = mlx_get_data_addr(dst->img_ptr,
	&dst->bpp, &dst->s_l, &dst->endian);
	ft_resize_image(src, dst);
	return (0);
}

int	ft_create_hp_screen(t_win *win, t_img *src, t_img *dst)
{
	dst->reso.x = (double)win->bkg->img->reso.x / (double)3;
	dst->reso.y = (double)win->bkg->img->reso.y / (double)6;
	dst->offset.x = trunc((win->bkg->img->reso.x / 2) - (dst->reso.x / 2));
	dst->offset.y = trunc((win->bkg->img->reso.y) - dst->reso.y - 10);
	dst->img_ptr = mlx_new_image(win->mlx_ptr, dst->reso.x, dst->reso.y);
	dst->img_data = mlx_get_data_addr(dst->img_ptr,
			&dst->bpp, &dst->s_l, &dst->endian);
	ft_resize_image(src, dst);
	return (0);
}

int	ft_init_textures(t_win *win, t_screen *screen, t_npc *npc)
{
	t_npc	*iter;

	ft_create_texture_img(win, screen->no_img, screen->no_path);
	ft_create_texture_img(win, screen->so_img, screen->so_path);
	ft_create_texture_img(win, screen->we_img, screen->we_path);
	ft_create_texture_img(win, screen->ea_img, screen->ea_path);
	npc->s_img = ft_new_image(win);
	ft_create_texture_img(win, npc->s_img, npc->s_path);
	iter = npc->next;
	while (iter)
	{
		iter->s_img = npc->s_img;
		iter = iter->next;
	}
	ft_create_texture_img(win, win->hud->red_img, win->hud->red_path);
	ft_create_texture_img(win, win->hud->white_img, win->hud->white_path);
	ft_create_texture_img(win, win->hud->blood_img, win->hud->blood_path);
	ft_create_texture_img(win, win->hud->dead_img, win->hud->dead_path);
	ft_create_hp_screen(win, win->hud->red_img, win->hud->red_screen);
	ft_create_hp_screen(win, win->hud->white_img, win->hud->white_screen);
	ft_create_screen(win, win->hud->blood_img, win->hud->blood_screen);
	ft_create_screen(win, win->hud->dead_img, win->hud->dead_screen);
	return (0);
}

int	ft_init_func(t_win *win, t_func *func)
{
	int i;

	i = 0;
	while (i <= func->prec * 360)
	{
		func->cos[i] = cos((i * 2 * M_PI) / (360 * func->prec));
		func->sin[i] = sin((i * 2 * M_PI) / (360 * func->prec));
		func->tan[i] = func->sin[i] / func->cos[i];
		i++;
	}
	win->player->f = func;
	win->mmap->f = func;
	win->player->ray->f = func;
	win->screen->f = func;
	win->cursor->f = func;
	return (0);
}
