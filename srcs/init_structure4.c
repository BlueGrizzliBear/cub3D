/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 21:57:06 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 14:14:14 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_set_angle(char map_index, t_win *win)
{
	if (map_index == 'E')
		win->player->pos.ang = 0;
	if (map_index == 'N')
		win->player->pos.ang = M_PI / 2;
	if (map_index == 'W')
		win->player->pos.ang = M_PI;
	if (map_index == 'S')
		win->player->pos.ang = (3 * M_PI) / 2;
	return (0);
}

int	ft_get_player_position(char map_index, t_win *win, int x, int y)
{
	if (map_index == 'N' || map_index == 'E' || map_index == 'W'
			|| map_index == 'S')
	{
		win->player->pos.x = x * win->cb_s + win->cb_s / 2;
		win->player->pos.y = y * win->cb_s + win->cb_s / 2;
		ft_set_angle(map_index, win);
	}
	return (0);
}

int	ft_set_npc_param(t_win *win, t_npc *npc)
{
	npc->center.x = npc->pos.x + win->cb_s / 2;
	npc->center.y = npc->pos.y + win->cb_s / 2;
	npc->center.ang = get_angle(npc->center, win->player->pos);
	npc->center_dist = sqrt(pow((npc->center.x - win->player->pos.x), 2)
	+ pow((npc->center.y - win->player->pos.y), 2));
	return (0);
}

int	ft_get_npc_positions(t_win *win, int x, int y)
{
	int		a;
	t_npc	*last;
	t_npc	*iter_cpy;

	a = -1;
	last = win->npc;
	while (last->next)
	{
		a = last->id;
		last = last->next;
	}
	if (last->id >= 0)
	{
		last->next = ft_new_npc(win);
		iter_cpy = last->next;
		a++;
		iter_cpy->s_path = last->s_path;
	}
	else
		iter_cpy = last;
	iter_cpy->id = a + 1;
	iter_cpy->pos.x = x * win->cb_s;
	iter_cpy->pos.y = y * win->cb_s;
	ft_set_npc_param(win, iter_cpy);
	return (0);
}

int	ft_init_pos(t_win *win, t_input *input)
{
	int	i;
	int	j;

	i = -1;
	while (++i < input->max.y)
	{
		j = -1;
		while (++j < input->max.x)
		{
			if (input->map_table[i][j] == '2')
				ft_get_npc_positions(win, j, i);
			else
				ft_get_player_position(input->map_table[i][j], win, j, i);
		}
	}
	return (1);
}
