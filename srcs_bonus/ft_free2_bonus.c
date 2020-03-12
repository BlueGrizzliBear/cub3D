/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 21:08:31 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 08:54:06 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_player	*ft_free_player(t_player *player)
{
	if (player != NULL)
	{
		if (player->ray != NULL)
		{
			free(player->ray);
			player->ray = NULL;
		}
		free(player);
		player = NULL;
	}
	return (player);
}

t_npc		*ft_free_npc(t_win *win, t_npc *npc)
{
	t_npc	*iter;
	t_npc	*iter_next;
	int		i;

	i = 0;
	if (npc != NULL)
	{
		iter = npc;
		while (iter)
		{
			iter_next = iter->next;
			if (i == 0)
			{
				iter->s_path = ft_free_string(iter->s_path);
				iter->s_img = ft_free_image(win->mlx_ptr, iter->s_img);
				i = 1;
			}
			free(iter);
			iter = NULL;
			iter = iter_next;
		}
		npc = NULL;
	}
	return (npc);
}

t_screen	*ft_free_screen(t_win *win, t_screen *screen)
{
	if (screen != NULL)
	{
		screen->no_path = ft_free_string(screen->no_path);
		screen->so_path = ft_free_string(screen->so_path);
		screen->we_path = ft_free_string(screen->we_path);
		screen->ea_path = ft_free_string(screen->ea_path);
		screen->no_img = ft_free_image(win->mlx_ptr, screen->no_img);
		screen->so_img = ft_free_image(win->mlx_ptr, screen->so_img);
		screen->we_img = ft_free_image(win->mlx_ptr, screen->we_img);
		screen->ea_img = ft_free_image(win->mlx_ptr, screen->ea_img);
		free(screen);
		screen = NULL;
	}
	return (screen);
}

t_cursor	*ft_free_cursor(t_win *win, t_cursor *cursor)
{
	if (cursor != NULL)
	{
		cursor->img = ft_free_image(win->mlx_ptr, cursor->img);
		free(cursor);
		cursor = NULL;
	}
	return (cursor);
}

t_hud		*ft_free_hud(t_win *win, t_hud *hud)
{
	if (hud != NULL)
	{
		hud->red_img = ft_free_image(win->mlx_ptr, hud->red_img);
		hud->red_screen = ft_free_image(win->mlx_ptr, hud->red_screen);
		hud->white_img = ft_free_image(win->mlx_ptr, hud->white_img);
		hud->white_screen = ft_free_image(win->mlx_ptr, hud->white_screen);
		hud->blood_img = ft_free_image(win->mlx_ptr, hud->blood_img);
		hud->blood_screen = ft_free_image(win->mlx_ptr, hud->blood_screen);
		hud->dead_img = ft_free_image(win->mlx_ptr, hud->dead_img);
		hud->dead_screen = ft_free_image(win->mlx_ptr, hud->dead_screen);
		free(hud);
		hud = NULL;
	}
	return (hud);
}
