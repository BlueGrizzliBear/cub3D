/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_integrity2_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 19:02:29 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 08:54:06 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		ft_check_character(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_case(int pos_x, int pos_y, char **t, int size)
{
	t_reso new_pos;

	if (ft_check_character(t[pos_y][pos_x], "02NSWE") == 1)
	{
		new_pos.x = pos_x;
		new_pos.y = pos_y;
		if (ft_check_around(t, new_pos, size) == -1)
			return (-1);
		return (1);
	}
	else if (ft_check_character(t[pos_y][pos_x], "31") == 1)
		return (0);
	return (-1);
}

int		ft_check_around(char **t, t_reso pos, int size)
{
	if (ft_check_character(t[pos.y][pos.x], "02NSWE") == 1)
		t[pos.y][pos.x] = '3';
	if (ft_check_outside(t, pos, size) == -1)
		return (-1);
	if (pos.x + 1 < (int)ft_strlen(t[pos.y]))
	{
		if (ft_case(pos.x + 1, pos.y, t, size) == -1)
			return (-1);
	}
	if (pos.x - 1 >= 0)
	{
		if (ft_case(pos.x - 1, pos.y, t, size) == -1)
			return (-1);
	}
	if (pos.y - 1 >= 0 && pos.x < (int)ft_strlen(t[pos.y - 1]))
	{
		if (ft_case(pos.x, pos.y - 1, t, size) == -1)
			return (-1);
	}
	if (pos.y + 1 < size && pos.x < (int)ft_strlen(t[pos.y + 1]))
	{
		if (ft_case(pos.x, pos.y + 1, t, size) == -1)
			return (-1);
	}
	return (1);
}

char	**ft_fill_with_ones(t_win *win, char **table, int size)
{
	int		i;
	int		j;
	char	**t;

	if ((t = malloc((size + 1) * sizeof(char*))) == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		if (!(t[i] = malloc(sizeof(char) * (win->mmap->input->max.x + 1))))
			return (NULL);
		j = -1;
		while (table[i][++j])
			t[i][j] = table[i][j];
		while (j < win->mmap->input->max.x)
			t[i][j++] = '1';
		t[i][j] = '\0';
		free(table[i]);
		table[i] = NULL;
	}
	t[i] = 0;
	free(table);
	table = NULL;
	return (t);
}

int		ft_check_flood_fill(t_win *win, char **table)
{
	t_reso	pos;
	int		i;
	int		j;
	char	c;

	win->mmap->input->t = ft_copy_map_table(table);
	i = -1;
	while (win->mmap->input->t[++i] != NULL)
	{
		j = -1;
		while (++j < (int)ft_strlen(win->mmap->input->t[i]))
		{
			c = win->mmap->input->t[i][j];
			if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
			{
				pos.y = i;
				pos.x = j;
				win->mmap->input->t[i][j] = '3';
			}
		}
	}
	if (ft_check_around(win->mmap->input->t, pos, i) == -1)
		return (-1);
	win->mmap->input->map_table = ft_fill_with_ones(win, table, i);
	return (0);
}
