/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 22:17:14 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 08:54:06 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_convert_four_bytes(unsigned int nb, unsigned char *dst)
{
	dst[0] = (nb >> 0);
	dst[1] = (nb >> 8);
	dst[2] = (nb >> 16);
	dst[3] = (nb >> 24);
}

void	ft_convert_two_bytes(unsigned int nb, unsigned char *dst)
{
	dst[0] = (nb >> 0);
	dst[1] = (nb >> 8);
}

void	ft_flip_bytes(t_win *win, t_reso reso, int size, unsigned char *bmp)
{
	bmp[0] = 'B';
	bmp[1] = 'M';
	ft_convert_four_bytes(size, &bmp[2]);
	ft_convert_two_bytes(0, &bmp[6]);
	ft_convert_two_bytes(0, &bmp[8]);
	ft_convert_four_bytes(54, &bmp[10]);
	ft_convert_four_bytes(40, &bmp[14]);
	ft_convert_four_bytes(reso.x, &bmp[18]);
	ft_convert_four_bytes(reso.y, &bmp[22]);
	ft_convert_two_bytes(1, &bmp[26]);
	ft_convert_two_bytes(32, &bmp[28]);
	ft_convert_four_bytes(0, &bmp[30]);
	ft_convert_four_bytes(reso.x * reso.y * 4, &bmp[34]);
	ft_convert_four_bytes(0, &bmp[38]);
	ft_convert_four_bytes(0, &bmp[42]);
	ft_convert_four_bytes(0, &bmp[46]);
	ft_convert_four_bytes(0, &bmp[50]);
	ft_screenshot(win, &bmp[54]);
}

int		ft_create_bmp(t_win *win, unsigned char *bmp, int fd)
{
	t_reso	reso;
	int		size;

	reso.x = win->bkg->img->reso.x;
	reso.y = win->bkg->img->reso.y;
	size = 14 + 40 + reso.x * reso.y * 4;
	if ((bmp = malloc(sizeof(unsigned char) * size)) == NULL)
		ft_error(-31, win);
	ft_flip_bytes(win, reso, size, bmp);
	write(fd, &bmp[0], size);
	free(bmp);
	bmp = NULL;
	ft_quit(win);
	return (0);
}

int		ft_check_arg_save(char *save, t_win *win)
{
	int len;

	if (save)
	{
		len = ft_strlen(save);
		if (len != 6)
			return (ft_error(-1, win));
		if (save[0] == '-' && save[1] == '-' && save[2] == 's'
		&& save[3] == 'a' && save[4] == 'v' && save[5] == 'e')
		{
			if ((win->fd = open("./save.bmp",
			(O_TRUNC | O_RDWR | O_CREAT), S_IRWXU)) < 0)
				ft_error(-30, win);
			win->save = 1;
			return (0);
		}
		ft_error(-2, win);
		return (-1);
	}
	ft_error(-3, win);
	return (-1);
}
