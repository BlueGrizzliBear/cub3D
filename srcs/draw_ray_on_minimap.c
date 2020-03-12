/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray_on_minimap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:53:23 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/24 13:53:24 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_draw_ray_pos(t_ray *ray, t_pos pos, t_mmap *mmap)
{
	t_reso	map_pos;

	map_pos.x = round(pos.x - mmap->offset.x);
	map_pos.y = round(pos.y - mmap->offset.y);
	if (map_pos.x >= 0 && map_pos.x <= mmap->mm_img->reso.x
			&& map_pos.y >= 0 && map_pos.y <= mmap->mm_img->reso.y)
		ft_chg_pxl_clr(mmap->mm_img, map_pos.x, map_pos.y, ray->color);
	return (0);
}

int		ft_init_r_beam(t_player *player, t_ray *ray)
{
	ray->line.x = round(player->pos.x);
	ray->line.y = round(player->pos.y);
	ray->d.x = fabs(ray->pos.x - ray->line.x);
	ray->d.y = fabs(ray->pos.y - ray->line.y);
	ray->s.x = ray->mtx_c.d_x;
	ray->s.y = ray->mtx_c.d_y;
	ray->err = -ray->d.y / 2;
	if (ray->d.x > ray->d.y)
		ray->err = ray->d.x / 2;
	return (0);
}

int		ft_draw_r_beam(t_ray *r, t_pos d, t_reso s, t_mmap *m)
{
	t_pos	diff;

	while (r->line.x != round(r->pos.x) || r->line.y != round(r->pos.y))
	{
		diff.x = round(r->line.x - m->offset.x);
		diff.y = round(r->line.y - m->offset.y);
		if (diff.x >= 0 && diff.x < m->mm_img->reso.x &&
		diff.y >= 0 && diff.y < m->mm_img->reso.y)
			ft_chg_pxl_clr(m->mm_img, diff.x, diff.y, r->color);
		r->e2 = r->err;
		if (r->e2 > -d.x)
		{
			r->err -= d.y;
			r->line.x += s.x;
		}
		if (r->e2 < d.y)
		{
			r->err += d.x;
			r->line.y += s.y;
		}
	}
	return (0);
}
