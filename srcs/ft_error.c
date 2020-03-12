/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 09:36:36 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/25 11:59:53 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error_argument(int id)
{
	write(1, "Arguments not valid : ", 22);
	if (id == -1)
		write(1, "length\n", 7);
	else if (id == -2)
		write(1, "characters\n", 11);
	else if (id == -3)
		write(1, "doesn't exist\n", 14);
	else if (id == -4)
		write(1, "file not valid\n", 15);
	else if (id == -5)
		write(1, "wrong number of arguments\n", 26);
}

void	ft_error_map(int id)
{
	write(1, "File is not valid : ", 20);
	if (id == -10)
		write(1, "Color element not valid\n", 24);
	else if (id == -11)
		write(1, "elements in file not valid\n", 27);
	else if (id == -12)
		write(1, "problem encountered while reading\n", 34);
	else if (id == -13)
		write(1, "missing elements in file\n", 25);
	else if (id == -14)
		write(1, "path of texture not valid\n", 26);
	else if (id == -15)
		write(1, "texture file not valid\n", 23);
	else if (id == -16)
		write(1, "xenos element found\n", 20);
	else if (id == -17)
		write(1, "R element not valid\n", 20);
	else if (id == -18)
		write(1, "map not properly closed\n", 24);
}

void	ft_error_mlx(int id)
{
	write(1, "Mlx error : ", 12);
	if (id == -20)
		write(1, "could not create mlx_ptr\n", 25);
	else if (id == -21)
		write(1, "could not create win_ptr\n", 25);
	else if (id == -22)
		write(1, "could not create minimap image pointer\n", 39);
	else if (id == -23)
		write(1, "could not create minimap image\n", 31);
	else if (id == -24)
		write(1, "could not create mlx image\n", 27);
	else if (id == -25)
		write(1, "could not create mlx pointer to xpm image\n", 42);
	else if (id == -26)
		write(1, "could not create mlx pointer to png image\n", 42);
}

void	ft_error_basic(int id)
{
	write(1, "Program error : ", 16);
	if (id == -30)
		write(1, "problem closing file\n", 21);
	else if (id == -31)
		write(1, "problem allocating memory\n", 28);
}

int		ft_error(int id, t_win *win)
{
	write(1, "Error\n", 6);
	if (id == 0)
		write(1, "Could not create base structure\n", 32);
	else if (id <= -1 && id >= -9)
		ft_error_argument(id);
	else if (id <= -10 && id >= -19)
		ft_error_map(id);
	else if (id <= -20 && id >= -29)
		ft_error_mlx(id);
	else if (id <= -30 && id >= -39)
		ft_error_basic(id);
	ft_quit(win);
	return (-1);
}
