/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 21:09:27 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/24 13:53:51 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_free_tables(char **table)
{
	int i;

	i = -1;
	if (table != NULL)
	{
		while (table[++i])
		{
			free(table[i]);
			table[i] = NULL;
		}
		free(table);
		table = NULL;
	}
	return (table);
}

t_input	*ft_free_input(t_input *input)
{
	int i;

	i = -1;
	if (input != NULL)
	{
		input->file_name = ft_free_string(input->file_name);
		input->line = ft_free_string(input->line);
		input->map_lines = ft_free_string(input->map_lines);
		input->map_table = ft_free_tables(input->map_table);
		input->t = ft_free_tables(input->t);
		free(input);
		input = NULL;
	}
	return (input);
}

t_mmap	*ft_free_mmap(t_win *win, t_mmap *mmap)
{
	if (mmap != NULL)
	{
		mmap->mm_img = ft_free_image(win->mlx_ptr, mmap->mm_img);
		mmap->input = ft_free_input(win->mmap->input);
		free(mmap);
		mmap = NULL;
	}
	return (mmap);
}

t_bkg	*ft_free_bkg(t_win *win, t_bkg *bkg)
{
	if (bkg != NULL)
	{
		bkg->img = ft_free_image(win->mlx_ptr, bkg->img);
		free(bkg);
		bkg = NULL;
	}
	return (bkg);
}

t_func	*ft_free_func(t_func *func)
{
	if (func != NULL)
	{
		if (func->cos != NULL)
		{
			free(func->cos);
			func->cos = NULL;
		}
		if (func->sin != NULL)
		{
			free(func->sin);
			func->sin = NULL;
		}
		if (func->tan != NULL)
		{
			free(func->tan);
			func->tan = NULL;
		}
		free(func);
		func = NULL;
	}
	return (func);
}
