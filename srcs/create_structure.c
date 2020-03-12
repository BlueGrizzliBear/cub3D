/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_structure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:25:54 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 10:19:08 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_npc		*ft_new_npc(t_win *win)
{
	t_npc *npc;

	if ((npc = malloc(sizeof(t_npc))) == NULL)
		ft_error(-31, win);
	npc->id = -1;
	npc->pos.x = 0;
	npc->pos.y = 0;
	npc->pos.ang = 0;
	npc->color = ft_new_clr(MM_S_ALPHA, MM_S_RED, MM_S_GREEN, MM_S_BLUE);
	npc->s_path = NULL;
	npc->s_img = NULL;
	npc->speed = MVT_SPEED;
	npc->next = NULL;
	return (npc);
}

t_func		*ft_new_func(t_win *win)
{
	t_func *func;

	if ((func = malloc(sizeof(t_func))) == NULL)
		ft_error(-31, win);
	func->prec = FUNC_PRECIS;
	if ((func->cos = malloc(sizeof(double) * (func->prec * 360 + 1))) == NULL)
		ft_error(-31, win);
	if ((func->sin = malloc(sizeof(double) * (func->prec * 360 + 1))) == NULL)
		ft_error(-31, win);
	if ((func->tan = malloc(sizeof(double) * (func->prec * 360 + 1))) == NULL)
		ft_error(-31, win);
	return (func);
}

t_screen	*ft_new_screen(t_win *win)
{
	t_screen	*screen;

	if ((screen = malloc(sizeof(t_screen))) == NULL)
		ft_error(-31, win);
	screen->offset = SCREEN_DISTANCE;
	screen->pos.x = 0;
	screen->pos.y = 0;
	screen->no_path = NULL;
	screen->so_path = NULL;
	screen->we_path = NULL;
	screen->ea_path = NULL;
	screen->no_img = ft_new_image(win);
	screen->so_img = ft_new_image(win);
	screen->we_img = ft_new_image(win);
	screen->ea_img = ft_new_image(win);
	screen->current = NULL;
	screen->orientation.d_x = 0;
	screen->orientation.d_y = 0;
	screen->t_offset.x = 0;
	screen->t_offset.y = 0;
	screen->real_size = 0;
	screen->real_pos_y = 0;
	screen->size = 0;
	screen->w_color = ft_new_clr(WALL_ALPHA, WALL_RED, WALL_GREEN, WALL_BLUE);
	return (screen);
}

t_win		*ft_new_window(void)
{
	t_win	*win;

	if ((win = malloc(sizeof(t_win))) == NULL)
		ft_error(-31, win);
	win->save = 0;
	win->fd = -1;
	win->bmp = NULL;
	win->dst.d_x = 0;
	win->dst.d_y = 0;
	win->src.d_x = 0;
	win->src.d_y = 0;
	win->mlx_ptr = NULL;
	win->win_ptr = NULL;
	win->mmap = ft_new_mmap(win);
	win->bkg = ft_new_bkg(win, win->mmap);
	win->player = ft_new_player(win);
	win->npc = ft_new_npc(win);
	win->screen = ft_new_screen(win);
	win->f = ft_new_func(win);
	win->cb_s = (double)CUBE_SIZE;
	return (win);
}
