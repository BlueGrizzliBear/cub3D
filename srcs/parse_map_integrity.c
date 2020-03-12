/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_integrity.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:33:04 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/25 11:46:32 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_map_perimeter(t_input *input)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < input->max.y)
		if (input->map_table[i++][j] != '1')
			return (-1);
	while (j < input->max.x)
		if (input->map_table[i - 1][j++] != '1')
			return (-1);
	while (i > 0)
		if (input->map_table[i-- - 1][j - 1] != '1')
			return (-1);
	while (j > 0)
		if (input->map_table[i][j-- - 1] != '1')
			return (-1);
	return (1);
}

int	ft_check_map_characters(t_input *input, char *charset)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (input->map_table[i])
	{
		while (input->map_table[i][j])
		{
			while (charset[k] && charset[k] != input->map_table[i][j])
				k++;
			if (!charset[k])
				return (-1);
			k = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	ft_check_single_player(t_input *input, char *charset)
{
	int i;
	int j;
	int k;
	int	count;

	i = -1;
	j = -1;
	k = 0;
	count = 0;
	while (input->map_table[++i])
	{
		while (input->map_table[i][++j])
		{
			while (charset[k] && charset[k] != input->map_table[i][j])
				k++;
			if (charset[k] == input->map_table[i][j])
				count++;
			k = 0;
		}
		j = 0;
	}
	if (count != 1)
		return (-1);
	return (1);
}

int	ft_check_map_line_size(t_input *input)
{
	int i;
	int	size;
	int	size2;

	i = 0;
	size = 0;
	size2 = 0;
	while (i < input->max.y)
	{
		if (input->max.x != (int)ft_strlen(input->map_table[i]))
			return (-1);
		i++;
	}
	return (1);
}

int	ft_check_map_integrity(t_win *win)
{
	if (ft_check_map_characters(win->mmap->input,
	win->mmap->input->charset) == -1)
		ft_error(-11, win);
	if (ft_check_single_player(win->mmap->input, "NSWE") == -1)
		ft_error(-11, win);
	if (win->mmap->input->reso.x > 2560)
		win->mmap->input->reso.x = 2560;
	if (win->mmap->input->reso.y > 1440)
		win->mmap->input->reso.y = 1440;
	if (ft_check_flood_fill(win, win->mmap->input->map_table) == -1)
		ft_error(-18, win);
	return (0);
}
