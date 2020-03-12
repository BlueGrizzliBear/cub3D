/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 21:53:04 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 10:20:22 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	return (0);
}
