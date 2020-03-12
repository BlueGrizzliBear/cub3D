/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 22:32:45 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 08:54:06 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_screenshot_bkg(t_win *win, unsigned char *dst)
{
	int x;
	int y;
	int temp;
	int	k;

	y = 0;
	while (y < win->bkg->img->reso.y)
	{
		x = 0;
		while (x < win->bkg->img->reso.x)
		{
			k = -1;
			temp = win->bkg->img->reso.y - 1 - y;
			while (++k < 4)
			{
				dst[4 * x + win->bkg->img->s_l * temp + k] =
				win->bkg->img->img_data[4 * x + win->bkg->img->s_l * y + k];
			}
			x++;
		}
		y++;
	}
}

int		ft_chg_screensh_pixel(t_win *win, unsigned char *dst, t_img *src)
{
	int				k;
	unsigned char	tr;
	float			transp_ratio;
	int				s_l;

	s_l = win->bkg->img->s_l;
	k = -1;
	tr = src->img_data[4 * win->src.d_x + src->s_l * win->src.d_y + 3];
	transp_ratio = 1 - (float)tr / 255;
	while (++k < 4)
	{
		dst[4 * win->dst.d_x + s_l * win->dst.d_y + k] =
		(unsigned char)dst[4 * win->dst.d_x + s_l * win->dst.d_y + k] +
		(int)(((unsigned char)src->img_data[4 * win->src.d_x +
		src->s_l * win->src.d_y + k] - (unsigned char)dst[
			4 * win->dst.d_x + s_l * win->dst.d_y + k]) * transp_ratio);
	}
	return (1);
}

void	ft_other_screensh(t_win *win, unsigned char *dst_img, t_img *src_img)
{
	int x;
	int y;

	y = 0;
	while (y < src_img->reso.y)
	{
		x = 0;
		while (x < src_img->reso.x)
		{
			win->src.d_x = x;
			win->src.d_y = y;
			win->dst.d_x = x + src_img->offset.x;
			win->dst.d_y = (src_img->reso.y - y) +
			(win->bkg->img->reso.y - src_img->reso.y - src_img->offset.y);
			ft_chg_screensh_pixel(win, dst_img, src_img);
			x++;
		}
		y++;
	}
}

void	ft_screenshot(t_win *win, unsigned char *dst)
{
	ft_screenshot_bkg(win, dst);
	ft_other_screensh(win, dst, win->mmap->mm_img);
	ft_other_screensh(win, dst, win->hud->white_screen);
	ft_other_screensh(win, dst, win->hud->red_screen);
	ft_other_screensh(win, dst, win->cursor->img);
}
