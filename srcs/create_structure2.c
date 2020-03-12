/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_structure2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:33:07 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/25 11:28:48 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color		ft_new_clr(unsigned a, unsigned r, unsigned g, unsigned b)
{
	t_color	newcolor;

	newcolor.alpha = a;
	newcolor.red = r;
	newcolor.green = g;
	newcolor.blue = b;
	newcolor.color = (255 * 255 * 255 * a + 255 * 255 * r + 255 * g + b);
	return (newcolor);
}

void		ft_init_returns(t_input *input)
{
	input->r_r = 0;
	input->r_no = 0;
	input->r_so = 0;
	input->r_we = 0;
	input->r_ea = 0;
	input->r_s = 0;
	input->r_f = 0;
	input->r_c = 0;
	input->r_other = 0;
}

t_input		*ft_new_input(t_win *win)
{
	t_input *input;

	if ((input = malloc(sizeof(t_input))) == NULL)
		ft_error(-31, win);
	input->file_name = NULL;
	input->charset = "012NSWE";
	input->line = NULL;
	ft_init_returns(input);
	input->reso.x = 0;
	input->reso.y = 0;
	input->f_color = ft_new_clr(0, 0, 0, 0);
	input->c_color = ft_new_clr(0, 0, 0, 0);
	input->map_lines = ft_strdup("");
	input->map_table = NULL;
	input->t = NULL;
	input->max.x = 0;
	input->max.y = 0;
	return (input);
}

t_img		*ft_new_image(t_win *win)
{
	t_img	*img;

	if ((img = malloc(sizeof(t_img))) == NULL)
		ft_error(-31, win);
	img->img_ptr = NULL;
	img->img_data = NULL;
	img->offset.x = 0;
	img->offset.y = 0;
	img->reso.x = 0;
	img->reso.y = 0;
	img->bpp = 0;
	img->s_l = 0;
	img->endian = 0;
	return (img);
}

t_player	*ft_new_player(t_win *win)
{
	t_player *newplayer;

	if ((newplayer = malloc(sizeof(t_player))) == NULL)
		ft_error(-31, win);
	newplayer->pos.x = 0;
	newplayer->pos.y = 0;
	newplayer->pos.ang = 0;
	newplayer->hp = 100;
	newplayer->fov = FOV * (M_PI / 180);
	newplayer->ang_speed = ANG_SPEED * (M_PI / 180);
	newplayer->mvt_speed = MVT_SPEED;
	newplayer->color =
	ft_new_clr(MM_P_ALPHA, MM_P_RED, MM_P_GREEN, MM_P_BLUE);
	newplayer->ray = ft_new_ray(win);
	return (newplayer);
}
