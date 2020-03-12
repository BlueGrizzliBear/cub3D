/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_general.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:43:55 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/25 11:31:11 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_extension(char *map_file, t_input *input)
{
	int i;

	i = ft_strlen(map_file) - 1;
	if (map_file[i] == 'b' && i > 0)
	{
		if (map_file[i - 1] == 'u' && i - 1 > 0)
		{
			if (map_file[i - 2] == 'c' && i - 2 > 0)
			{
				if (map_file[i - 3] == '.' && i - 3 > 0)
				{
					input->file_name = ft_strdup(map_file);
					return (1);
				}
			}
		}
	}
	return (-1);
}

int	ft_create_map_table(t_win *win, t_input *input)
{
	int i;

	i = 0;
	if (!(input->map_table = ft_split(input->map_lines, '\n')))
		ft_error(-31, win);
	free(input->map_lines);
	input->map_lines = NULL;
	while (input->map_table[i])
	{
		if (input->max.x < (int)ft_strlen(input->map_table[i]))
			input->max.x = ft_strlen(input->map_table[i]);
		i++;
	}
	return (1);
}

int	ft_parsing(char *map_file, t_win *win)
{
	int		ret;
	int		fd;

	fd = -1;
	if ((ft_check_extension(map_file, win->mmap->input) == -1) ||
			((fd = open(map_file, O_RDONLY)) == -1))
		ft_error(-4, win);
	while ((ret = get_next_line(fd, &win->mmap->input->line)) >= 0)
	{
		if (ft_identify(win->mmap->input->line, win, win->mmap->input) == -1)
			ft_error(-11, win);
		if (ret == 0)
		{
			if (close(fd) != 0)
				ft_error(-30, win);
			ft_create_map_table(win, win->mmap->input);
			ft_check_map_integrity(win);
			return (1);
		}
		free(win->mmap->input->line);
		win->mmap->input->line = NULL;
	}
	return (ft_error(-12, win));
}
