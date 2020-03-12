/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:38:15 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 10:18:14 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_angle(t_pos new_pos, t_pos p_pos)
{
	double d_x;
	double d_y;

	d_x = new_pos.x - p_pos.x;
	d_y = new_pos.y - p_pos.y;
	if (d_x == 0)
		new_pos.ang = (d_y > 0 ? -M_PI / 2 : M_PI / 2);
	else
	{
		if (d_x > 0)
			new_pos.ang = -1 * atan((d_y) / (d_x));
		else
			new_pos.ang = (d_y > 0 ? -1 * (M_PI + atan((d_y) / (d_x))) :
			(M_PI - atan((d_y) / (d_x))));
	}
	new_pos.ang = ft_mod(new_pos.ang, 2 * M_PI);
	return (new_pos.ang);
}

t_pos	ft_get_new_pos(t_win *win, t_pos p_pos, t_hotkey h)
{
	t_pos	new_pos;

	new_pos.x = p_pos.x + win->player->mvt_speed * (
			ft_cos(win->f, p_pos.ang) * h.key_w
			+ ft_cos(win->f, p_pos.ang + M_PI) * h.key_s
			+ ft_cos(win->f, p_pos.ang + (M_PI / 2)) * h.key_a
			+ ft_cos(win->f, p_pos.ang + 3 * (M_PI / 2)) * h.key_d);
	new_pos.y = p_pos.y - win->player->mvt_speed * (
			ft_sin(win->f, p_pos.ang) * h.key_w
			+ ft_sin(win->f, p_pos.ang + M_PI) * h.key_s
			+ ft_sin(win->f, p_pos.ang + (M_PI / 2)) * h.key_a
			+ ft_sin(win->f, p_pos.ang + 3 * (M_PI / 2)) * h.key_d);
	new_pos.ang = get_angle(new_pos, p_pos);
	return (new_pos);
}

int		ft_analyse_move(t_win *win, t_player *player, t_hotkey h)
{
	t_pos	new_pos;

	if (h.key_lft_ar == 1 || h.key_rgt_ar == 1)
		player->pos.ang = ft_mod(player->pos.ang +
		(h.key_lft_ar - h.key_rgt_ar) * player->ang_speed, 2 * M_PI);
	if (h.key_w == 1 || h.key_s == 1 || h.key_a == 1 || h.key_d == 1)
	{
		new_pos = ft_get_new_pos(win, player->pos, h);
		new_pos.ang = player->pos.ang;
		player->pos = new_pos;
	}
	return (0);
}

int		ft_move_npc(t_win *win, t_player *p)
{
	t_npc	*i;
	int		offset;
	double	new_d;

	offset = 0;
	i = win->npc;
	while (i && i->id != -1)
	{
		i->center.ang = get_angle(i->center, p->pos);
		new_d = sqrt(pow((i->center.x - p->pos.x), 2)
		+ pow((i->center.y - p->pos.y), 2));
		i->center_dist = new_d;
		i = i->next;
	}
	return (0);
}
