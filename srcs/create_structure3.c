/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_structure3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:34:32 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 10:18:57 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_mmap		*ft_new_mmap(t_win *win)
{
	t_mmap	*newmmap;

	if ((newmmap = malloc(sizeof(t_mmap))) == NULL)
		ft_error(-31, win);
	newmmap->mm_img = ft_new_image(win);
	newmmap->mm_img->b_color =
	ft_new_clr(MM_F_ALPHA, MM_F_RED, MM_F_GREEN, MM_F_BLUE);
	newmmap->mm_img->offset.x = MM_OFFSET_X;
	newmmap->mm_img->offset.y = MM_OFFSET_Y;
	newmmap->w_color =
	ft_new_clr(MM_W_ALPHA, MM_W_RED, MM_W_GREEN, MM_W_BLUE);
	newmmap->input = ft_new_input(win);
	return (newmmap);
}

t_bkg		*ft_new_bkg(t_win *win, t_mmap *mmap)
{
	t_bkg	*newbkg;

	if ((newbkg = malloc(sizeof(t_bkg))) == NULL)
		ft_error(-31, win);
	newbkg->img = ft_new_image(win);
	newbkg->img->b_color =
	ft_new_clr(BKG_ALPHA, BKG_RED, BKG_GREEN, BKG_BLUE);
	newbkg->img->reso.x = mmap->input->reso.x;
	newbkg->img->reso.y = mmap->input->reso.y;
	return (newbkg);
}

void		ft_preinit_ray(t_ray *ray)
{
	ray->pos.x = 0;
	ray->pos.y = 0;
	ray->pos.ang = 0;
	ray->size = 0;
	ray->sqr_pos.x = 0;
	ray->sqr_pos.y = 0;
	ray->sqr_pos.ang = 0;
	ray->mtx_c.d_x = 0;
	ray->mtx_c.d_y = 0;
	ray->mtx_one_sqr.d_x = 0;
	ray->mtx_one_sqr.d_y = 0;
	ray->mtx_two_sqr.d_x = 0;
	ray->mtx_two_sqr.d_y = 0;
	ray->mtx_three_sqr.d_x = 0;
	ray->mtx_three_sqr.d_y = 0;
	ray->line.x = 0;
	ray->line.y = 0;
	ray->d.x = 0;
	ray->d.y = 0;
	ray->s.x = 0;
	ray->s.y = 0;
	ray->err = 0;
	ray->e2 = 0;
	ray->color = ft_new_clr(MM_R_ALPHA, MM_R_RED, MM_R_GREEN, MM_R_BLUE);
	ray->nb = -1;
}

t_ray		*ft_new_ray(t_win *win)
{
	t_ray *newray;

	if ((newray = malloc(sizeof(t_ray))) == NULL)
		ft_error(-31, win);
	ft_preinit_ray(newray);
	return (newray);
}
