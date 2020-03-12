/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 22:05:18 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 08:54:06 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		ft_change_hb(int start, t_img *img)
{
	int x;
	int y;

	y = -1;
	while (++y < img->reso.y)
	{
		x = -1;
		while (++x < img->reso.x)
		{
			if (x > start)
			{
				img->img_data[4 * x + img->s_l * y + 3] = (unsigned)255;
			}
			else
			{
				if ((unsigned)img->img_data[4 * x + img->s_l * y + 2]
				> (unsigned)0)
					img->img_data[4 * x + img->s_l * y + 3] = (unsigned)0;
			}
		}
	}
	return (1);
}

int		ft_change_blood_hud(t_hud *hud, t_img *img)
{
	int x;
	int y;

	y = -1;
	while (++y < img->reso.y)
	{
		x = -1;
		while (++x < img->reso.x)
		{
			img->img_data[4 * x + img->s_l * y + 3] =
			(1 - (0.4 * hud->transp)) * (unsigned)255;
		}
	}
	return (1);
}

int		ft_set_hud(t_win *win, t_player *player, t_hud *hud)
{
	int start;

	start = 0;
	hud->transp = (double)(100 - player->hp) / 100;
	start += hud->red_screen->reso.x * hud->transp;
	hud->red_screen->offset.x = (win->bkg->img->reso.x / 2)
		- (hud->red_screen->reso.x / 2) + (hud->red_screen->reso.x
		- hud->transp * hud->red_screen->reso.x) + 3;
	ft_change_hb(start, hud->red_screen);
	ft_change_blood_hud(hud, hud->blood_screen);
	return (1);
}
