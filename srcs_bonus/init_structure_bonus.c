/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 21:15:19 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 08:54:06 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	ft_init_mmap(t_win *win, t_input *input, t_mmap *mmap)
{
	win->bkg->img->reso.x = input->reso.x;
	win->bkg->img->reso.y = input->reso.y;
	mmap->mm_img->reso.x = win->bkg->img->reso.x / CUBE_SIZE;
	mmap->mm_img->reso.y = win->bkg->img->reso.x / CUBE_SIZE;
	if (!(mmap->mm_img->img_ptr = mlx_new_image(win->mlx_ptr,
	mmap->mm_img->reso.x, mmap->mm_img->reso.y)))
		ft_error(-22, win);
	if (!(mmap->mm_img->img_data = mlx_get_data_addr(mmap->mm_img->img_ptr,
		&mmap->mm_img->bpp, &mmap->mm_img->s_l, &mmap->mm_img->endian)))
		ft_error(-23, win);
	return (0);
}

int	ft_get_extension(char *path)
{
	int i;

	i = 0;
	while (path[i])
		i++;
	if (i > 4 && path[i - 4] == '.')
	{
		if (path[i - 1] == 'm' && path[i - 2] == 'p' && path[i - 3] == 'x')
			return (1);
		else if (path[i - 1] == 'g' && path[i - 2] == 'n' && path[i - 3] == 'p')
			return (2);
	}
	return (0);
}

int	ft_create_texture_img(t_win *win, t_img *img, char *path)
{
	if (ft_get_extension(path) == 1)
	{
		img->img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, path,
				&img->reso.x, &img->reso.y);
		if (img->img_ptr == NULL)
			return (ft_error(-25, win));
	}
	else if (ft_get_extension(path) == 2)
	{
		img->img_ptr = mlx_png_file_to_image(win->mlx_ptr, path,
				&img->reso.x, &img->reso.y);
		if (img->img_ptr == NULL)
			return (ft_error(-26, win));
	}
	else
		return (-1);
	if (!(img->img_data = mlx_get_data_addr(img->img_ptr,
			&img->bpp, &img->s_l, &img->endian)))
		return (ft_error(-24, win));
	return (0);
}

int	ft_init_struct(t_win *win)
{
	if (!(win->mlx_ptr = mlx_init()))
		ft_error(-20, win);
	if (win->save == 0)
	{
		if (!(win->win_ptr = mlx_new_window(win->mlx_ptr,
		win->mmap->input->reso.x, win->mmap->input->reso.y,
		win->mmap->input->file_name)))
			ft_error(-21, win);
	}
	win->cb_s = CUBE_SIZE;
	ft_init_func(win, win->f);
	ft_init_mmap(win, win->mmap->input, win->mmap);
	ft_init_pos(win, win->mmap->input);
	ft_init_ray(win);
	ft_init_bkg(win, win->bkg->img);
	ft_init_screen(win);
	ft_init_cursor(win, win->cursor);
	ft_init_hotkey(win);
	ft_init_textures(win, win->screen, win->npc);
	return (1);
}
