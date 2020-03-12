/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 22:03:11 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 08:54:06 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	ft_check_cursor_precision(t_hotkey h, t_cursor *c)
{
	int ret;

	if (h.key_lft_ar == 1 || h.key_rgt_ar == 1
			|| h.key_w == 1 || h.key_s == 1
			|| h.key_a == 1 || h.key_d == 1)
	{
		if (h.key_w == 1 && h.key_shift == 3)
			ret = 2 * c->step;
		else
			ret = 1 * c->step;
	}
	else
		ret = 0 * c->step;
	return (ret);
}

int	ft_set_cross(t_cursor *c, int prec, t_reso h_reso, t_reso incr)
{
	if ((incr.x >= (c->ring - prec) &&
	incr.x <= (c->img->reso.x - (c->ring - prec))) &&
	(incr.y >= (c->ring - prec) &&
	incr.y <= (c->img->reso.y - (c->ring - prec))) &&
	((incr.x >= h_reso.x && incr.x <= h_reso.x + (c->mid - 1) &&
	!(incr.y >= h_reso.y - prec - 1 && incr.y <= h_reso.y + prec + c->mid)) ||
	(incr.y >= h_reso.y - 0 && incr.y <= h_reso.y + (c->mid - 1) &&
	!(incr.x >= h_reso.x - prec - 1 && incr.x <= h_reso.x + prec + c->mid))))
		ft_chg_pxl_clr(c->img, incr.y, incr.x, c->color);
	else
	{
		ft_chg_pxl_clr(c->img, incr.y, incr.x, c->img->b_color);
	}
	return (0);
}

int	ft_set_cursor(t_cursor *c, t_hotkey hotkey)
{
	t_reso	incr;
	t_reso	half_reso;
	int		prec;

	half_reso.x = (int)c->img->reso.x / 2;
	half_reso.y = (int)c->img->reso.y / 2;
	prec = ft_check_cursor_precision(hotkey, c);
	incr.x = 0;
	incr.y = 0;
	while (incr.x < c->img->reso.x)
	{
		while (incr.y < c->img->reso.y)
		{
			ft_set_cross(c, prec, half_reso, incr);
			incr.y++;
		}
		incr.y = 0;
		incr.x++;
	}
	return (0);
}
