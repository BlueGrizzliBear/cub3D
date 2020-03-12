/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identify_elements2_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:58:47 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 13:05:40 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	ft_check_reso(char *line, t_win *win)
{
	int i;

	i = 0;
	i += ft_pass_spaces(&line[i]);
	if (!(line[i] >= '0' && line[i] <= '9'))
		ft_error(-17, win);
	win->mmap->input->reso.x = ft_atoi(&line[i]);
	i += ft_pass_numbers(&line[i]);
	i += ft_pass_spaces(&line[i]);
	if (!(line[i] >= '0' && line[i] <= '9'))
		ft_error(-17, win);
	win->mmap->input->reso.y = ft_atoi(&line[i]);
	i += ft_pass_numbers(&line[i]);
	i += ft_pass_spaces(&line[i]);
	if (line[i] != '\0')
		ft_error(-17, win);
	win->mmap->input->r_r = 1;
	if (win->mmap->input->reso.x < 2 || win->mmap->input->reso.y < 2)
		ft_error(-17, win);
	return (1);
}

int	ft_check_path(t_win *win, char **path, int *ret, char *l)
{
	int i;
	int	j;
	int	fd;

	i = 0;
	while (l[i] && l[i + 1] && l[i + 2] && l[i + 3])
	{
		if ((l[i] == '.' && l[i + 1] == 'p' && l[i + 2] == 'n' &&
		l[i + 3] == 'g') || (l[i] == '.' && l[i + 1] == 'x' &&
		l[i + 2] == 'p' && l[i + 3] == 'm'))
		{
			j = ft_pass_spaces(&l[i + 4]);
			if (l[i + 4 + j] != '\0')
				ft_error(-14, win);
			*path = ft_substr(&l[0], 0, i + 4);
			if ((fd = open(*path, O_RDONLY)) == -1)
				ft_error(-15, win);
			close(fd);
			*ret = 1;
			return (1);
		}
		i++;
	}
	return (ft_error(-14, win));
}
