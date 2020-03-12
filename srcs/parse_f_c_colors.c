/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_f_c_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:43:21 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 12:00:56 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_convert_color(t_win *win, char *color, int count, t_color *clr)
{
	int res;

	res = ft_atoi(color);
	if (res >= 0 && res <= 255)
	{
		if (count == 1)
			clr->red = (unsigned)ft_atoi(color);
		else if (count == 2)
			clr->green = (unsigned)ft_atoi(color);
		else if (count == 3)
			clr->blue = (unsigned)ft_atoi(color);
		else
			ft_error(-10, win);
		clr->color = (255 * 255 * clr->red + 255 * clr->green + clr->blue);
	}
	else
		ft_error(-10, win);
	return (1);
}

int	ft_get_color(t_win *win, char *color, t_color *clr, int count)
{
	int i;

	i = 0;
	ft_convert_color(win, &color[i], count, clr);
	i += ft_pass_numbers(&color[i]);
	i += ft_pass_spaces(&color[i]);
	if (color[i] == ',' && count < 3)
		i++;
	else if (count < 3)
	{
		if (color[i] != ',')
			ft_error(-10, win);
		i++;
	}
	return (i);
}

int	ft_scan_color(t_win *win, char *color, t_color *clr)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (color[i] && count < 3)
	{
		i += ft_pass_spaces(&color[i]);
		if (color[i] >= '0' && color[i] <= '9')
		{
			count++;
			i += ft_get_color(win, &color[i], clr, count);
		}
		else
			ft_error(-10, win);
	}
	i += ft_pass_spaces(&color[i]);
	if (color[i] != '\0' || (color[i] == '\0' && count != 3))
		ft_error(-10, win);
	return (1);
}

int	ft_check_f_c(t_win *win, char id, char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (id == 'F')
	{
		ft_scan_color(win, &line[i], &win->mmap->input->f_color);
		win->mmap->input->r_f = 1;
		return (1);
	}
	else if (id == 'C')
	{
		ft_scan_color(win, &line[i], &win->mmap->input->c_color);
		win->mmap->input->r_c = 1;
		return (1);
	}
	return (ft_error(-10, win));
}
