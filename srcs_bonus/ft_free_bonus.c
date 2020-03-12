/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 09:39:44 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 14:33:49 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_img		*ft_free_image(void *mlx_ptr, t_img *img)
{
	if (img != NULL)
	{
		if (img->img_ptr != NULL && mlx_ptr != NULL)
			mlx_destroy_image(mlx_ptr, img->img_ptr);
		free(img);
		img = NULL;
	}
	return (img);
}

char		*ft_free_string(char *str)
{
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	return (str);
}

void		ft_free_main_pointers(t_win *win)
{
	if (win->win_ptr != NULL)
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	win->win_ptr = NULL;
	if (win->mlx_ptr != NULL)
	{
		mlx_free_ptr(win->mlx_ptr);
		win->mlx_ptr = NULL;
	}
}

t_win		*ft_free(t_win *win)
{
	if (win->bmp != NULL)
	{
		free(win->bmp);
		win->bmp = NULL;
	}
	win->f = ft_free_func(win->f);
	win->mmap = ft_free_mmap(win, win->mmap);
	win->bkg = ft_free_bkg(win, win->bkg);
	win->npc = ft_free_npc(win, win->npc);
	win->player = ft_free_player(win->player);
	win->screen = ft_free_screen(win, win->screen);
	win->cursor = ft_free_cursor(win, win->cursor);
	win->hud = ft_free_hud(win, win->hud);
	ft_free_main_pointers(win);
	free(win);
	win = NULL;
	return (win);
}

int			ft_quit(t_win *win)
{
	if (win != NULL)
		win = ft_free(win);
	exit(EXIT_SUCCESS);
	return (0);
}
