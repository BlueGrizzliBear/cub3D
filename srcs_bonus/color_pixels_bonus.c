/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_pixels_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 22:01:58 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 08:54:06 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	ft_chg_pxl_clr(t_img *img, int x, int y, t_color color)
{
	int k;

	k = -1;
	while (++k < 4)
	{
		if (k == 0)
			img->img_data[4 * x + img->s_l * y + k] = color.blue;
		else if (k == 1)
			img->img_data[4 * x + img->s_l * y + k] = color.green;
		else if (k == 2)
			img->img_data[4 * x + img->s_l * y + k] = color.red;
		else if (k == 3)
			img->img_data[4 * x + img->s_l * y + k] = color.alpha;
	}
	return (1);
}

int	ft_chg_pxl(t_img *d_img, t_mtx dst, t_img *s_img, t_mtx src)
{
	int				k;
	unsigned char	tr;
	float			transp_ratio;

	k = -1;
	tr = s_img->img_data[4 * src.d_x + s_img->s_l * src.d_y + 3];
	transp_ratio = 1 - (float)tr / 255;
	while (++k < 4)
	{
		d_img->img_data[4 * dst.d_x + d_img->s_l * dst.d_y + k] =
		(unsigned char)d_img->img_data[4 * dst.d_x + d_img->s_l * dst.d_y + k] +
		(int)(((unsigned char)s_img->img_data[
			4 * src.d_x + s_img->s_l * src.d_y + k] -
			(unsigned char)d_img->img_data[4 * dst.d_x + d_img->s_l *
			dst.d_y + k]) * transp_ratio);
	}
	return (1);
}
