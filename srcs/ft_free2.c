/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 21:08:31 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 14:25:02 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
