/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 22:11:13 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/24 11:43:50 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_set_mmap_player(t_win *win)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < win->cb_s / 2)
	{
		while (j < win->cb_s / 2)
		{
			ft_chg_pxl_clr(win->mmap->mm_img,
			win->mmap->mm_img->reso.x / 2 - (win->cb_s / 4) + j,
			win->mmap->mm_img->reso.y / 2 - (win->cb_s / 4) + i,
			win->player->color);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
