/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:40:37 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 08:54:06 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		ft_key_press(int keycode, t_win *win)
{
	if (keycode == KEY_ESC)
		ft_quit(win);
	if (keycode == KEY_W)
		win->hotkey.key_w = 1;
	if (keycode == KEY_S)
		win->hotkey.key_s = 1;
	if (keycode == KEY_A)
		win->hotkey.key_a = 1;
	if (keycode == KEY_D)
		win->hotkey.key_d = 1;
	if (keycode == KEY_LFT_AR)
		win->hotkey.key_lft_ar = 1;
	if (keycode == KEY_RGT_AR)
		win->hotkey.key_rgt_ar = 1;
	if (keycode == SHIFT)
		win->hotkey.key_shift = 3;
	return (0);
}

int		ft_key_release(int keycode, t_win *win)
{
	if (keycode == KEY_W)
		win->hotkey.key_w = 0;
	if (keycode == KEY_S)
		win->hotkey.key_s = 0;
	if (keycode == KEY_A)
		win->hotkey.key_a = 0;
	if (keycode == KEY_D)
		win->hotkey.key_d = 0;
	if (keycode == KEY_LFT_AR)
		win->hotkey.key_lft_ar = 0;
	if (keycode == KEY_RGT_AR)
		win->hotkey.key_rgt_ar = 0;
	if (keycode == SHIFT)
		win->hotkey.key_shift = 2;
	return (0);
}

void	ft_display_image(t_win *win, t_img *img)
{
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
		img->img_ptr, img->offset.x, img->offset.y);
}

int		ft_game_loop(t_win *win)
{
	ft_analyse_move(win, win->player, win->hotkey);
	ft_move_npc(win, win->player);
	ft_set_mmap_image(win, win->mmap);
	ft_raycasting(win, win->player, win->player->ray);
	ft_set_mmap_player(win);
	ft_set_mmap_npc(win);
	ft_set_hud(win, win->player, win->hud);
	ft_set_cursor(win->cursor, win->hotkey);
	if (win->save == 0)
	{
		if (win->player->hp != 0)
		{
			ft_display_image(win, win->bkg->img);
			ft_display_image(win, win->mmap->mm_img);
			ft_display_image(win, win->hud->white_screen);
			ft_display_image(win, win->hud->red_screen);
			ft_display_image(win, win->cursor->img);
			ft_display_image(win, win->hud->blood_screen);
		}
		else
			ft_display_image(win, win->hud->dead_screen);
	}
	else
		ft_create_bmp(win, win->bmp, win->fd);
	return (0);
}

int		main(int argc, char **argv)
{
	t_win	*win;

	win = NULL;
	if (argc == 2 || argc == 3)
	{
		if (!(win = ft_new_window()))
			ft_error(0, NULL);
		if (argc == 3)
		{
			if (ft_check_arg_save(argv[2], win) == -1)
				return (-1);
		}
		ft_parsing(argv[1], win);
		ft_init_struct(win);
		if (win->save != 1)
		{
			mlx_hook(win->win_ptr, 17, 0, ft_quit, win);
			mlx_hook(win->win_ptr, 2, 0, ft_key_press, win);
			mlx_hook(win->win_ptr, 3, 0, ft_key_release, win);
		}
		mlx_loop_hook(win->mlx_ptr, ft_game_loop, win);
		mlx_loop(win->mlx_ptr);
	}
	ft_error(-5, NULL);
	return (0);
}
