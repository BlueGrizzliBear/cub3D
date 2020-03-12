/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:54:18 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 08:54:06 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		ft_color_mmap(t_reso pos, t_pos offset, t_win *win, t_input *input)
{
	char	map_index;
	t_reso	map_pos;
	t_img	*img;

	img = win->mmap->mm_img;
	map_pos.x = (int)((pos.x + offset.x) / win->cb_s);
	map_pos.y = (int)((pos.y + offset.y) / win->cb_s);
	if (map_pos.x >= 0 && map_pos.x < input->max.x &&
	map_pos.y >= 0 && map_pos.y < input->max.y)
		map_index = input->map_table[map_pos.y][map_pos.x];
	else
		map_index = (char)0;
	if (map_index == '2' || map_index == '0' || map_index == 'N'
					|| map_index == 'E' || map_index == 'W' || map_index == 'S')
		ft_chg_pxl_clr(img, pos.x, pos.y, img->b_color);
	else
		ft_chg_pxl_clr(img, pos.x, pos.y, win->mmap->w_color);
	return (0);
}

int		ft_set_mmap_image(t_win *win, t_mmap *mmap)
{
	t_reso	pos;

	mmap->offset.x = win->player->pos.x - mmap->mm_img->reso.x / 2;
	mmap->offset.y = win->player->pos.y - mmap->mm_img->reso.y / 2;
	mmap->max.x = mmap->offset.x + mmap->mm_img->reso.x;
	mmap->max.y = mmap->offset.y + mmap->mm_img->reso.y;
	pos.y = 0;
	while (pos.y < mmap->mm_img->reso.y)
	{
		pos.x = 0;
		while (pos.x < mmap->mm_img->reso.x)
		{
			ft_color_mmap(pos, mmap->offset, win, mmap->input);
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}
