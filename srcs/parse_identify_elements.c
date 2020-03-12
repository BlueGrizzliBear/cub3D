/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identify_elements.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:45:46 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 14:17:03 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_texture(char id, char *line, t_win *win)
{
	int i;

	i = 0;
	i += ft_pass_spaces(&line[i]);
	if (ft_strlen(line) < 5)
		ft_error(-14, win);
	if (id == 'N' && ft_check_path(win, &win->screen->no_path,
	&win->mmap->input->r_no, &line[i]) == 1)
		return (1);
	else if (id == 'S' && ft_check_path(win, &win->screen->so_path,
	&win->mmap->input->r_so, &line[i]) == 1)
		return (1);
	else if (id == 'W' && ft_check_path(win, &win->screen->we_path,
	&win->mmap->input->r_we, &line[i]) == 1)
		return (1);
	else if (id == 'E' && ft_check_path(win, &win->screen->ea_path,
	&win->mmap->input->r_ea, &line[i]) == 1)
		return (1);
	return (ft_error(-16, win));
}

int	ft_check_sprite(char *line, t_win *win)
{
	int i;

	i = 0;
	i += ft_pass_spaces(&line[i]);
	if (ft_check_path(win, &win->npc->s_path,
	&win->mmap->input->r_s, &line[i]) == 1)
	{
		if (!(win->npc->s_path))
			ft_error(-31, win);
	}
	else
		ft_error(-16, win);
	win->mmap->input->r_s = 1;
	return (1);
}

int	ft_check_before(t_win *win)
{
	if (win->mmap->input->r_r != 1 || win->mmap->input->r_no != 1
	|| win->mmap->input->r_so != 1 || win->mmap->input->r_we != 1
	|| win->mmap->input->r_ea != 1 || win->mmap->input->r_s != 1
	|| win->mmap->input->r_f != 1 || win->mmap->input->r_c != 1)
		ft_error(-13, win);
	return (1);
}

int	ft_check_texture_name(char *l, t_input *in, int i)
{
	if ((l[i] == 'N' && l[i + 1] == 'O' && in->r_no != 1) ||
	(l[i] == 'S' && l[i + 1] == 'O' && in->r_so != 1) ||
	(l[i] == 'W' && l[i + 1] == 'E' && in->r_we != 1) ||
	(l[i] == 'E' && l[i + 1] == 'A' && in->r_ea != 1))
		return (1);
	return (0);
}

int	ft_identify(char *l, t_win *win, t_input *in)
{
	int i;

	i = ft_pass_spaces(l);
	if (l[i] == 'R' && (in->r_r != 1))
		return (ft_check_reso(&l[i + 1], win));
	else if (ft_check_texture_name(l, in, i) == 1)
		return (ft_check_texture(l[i], &l[i + 2], win));
	else if (l[i] == 'S' && in->r_s != 1)
		return (ft_check_sprite(&l[i + 1], win));
	else if ((l[i] == 'F' && in->r_f != 1) || (l[i] == 'C' && in->r_c != 1))
		return (ft_check_f_c(win, l[i], &l[i + 1]));
	else if (l[i] == '\0')
	{
		if (in->r_other == 1)
			in->r_other = in->r_other - 2;
		return (1);
	}
	else if ((l[i] == '0' || l[i] == '1' || l[i] == '2') &&
	ft_check_before(win) == 1 && ft_join_map_lines(l, win, in) == 1
	&& (in->r_other >= 0))
	{
		in->r_other = 1;
		return (1);
	}
	return (ft_error(-16, win));
}
