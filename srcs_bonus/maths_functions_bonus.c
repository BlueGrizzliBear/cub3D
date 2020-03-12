/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_functions_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:18:36 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 08:54:06 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

double	ft_mod(double ang, double prec)
{
	while (!(ang >= 0 && ang < prec))
	{
		if (ang >= prec)
			ang = ang - prec;
		if (ang < 0)
			ang = ang + prec;
	}
	return (ang);
}

double	ft_cos(t_func *func, double ang)
{
	int		i;
	double	test_ang;
	double	res;

	i = 0;
	ang = ft_mod(ang, 2 * M_PI);
	res = 0;
	while (((2 * M_PI) * i / (360 * func->prec)) < ang)
		i++;
	test_ang = (2 * M_PI) * i / (360 * func->prec);
	if (test_ang == ang)
		return (func->cos[i]);
	else
	{
		res = (func->cos[i] - func->cos[i - 1]) *
		((ang - (2 * M_PI * (i - 1) / (360 * func->prec)))
		/ (test_ang - (2 * M_PI * (i - 1) / (360 * func->prec))))
		+ func->cos[i - 1];
		return (res);
	}
	return (res);
}

double	ft_sin(t_func *func, double ang)
{
	int		i;
	double	test_ang;
	double	res;

	i = 0;
	ang = ft_mod(ang, 2 * M_PI);
	res = 0;
	while (((2 * M_PI) * i / (360 * func->prec)) < ang)
		i++;
	test_ang = (2 * M_PI) * i / (360 * func->prec);
	if (test_ang == ang)
		return (func->sin[i]);
	else
	{
		res = (func->sin[i] - func->sin[i - 1]) *
		((ang - (2 * M_PI * (i - 1) / (360 * func->prec)))
		/ (test_ang - (2 * M_PI * (i - 1) / (360 * func->prec))))
		+ func->sin[i - 1];
		return (res);
	}
	return (res);
}

double	ft_tan(t_func *func, double ang)
{
	int		i;
	double	test_ang;
	double	res;

	i = 0;
	ang = ft_mod(ang, 2 * M_PI);
	res = 0;
	while (((2 * M_PI) * i / (360 * func->prec)) < ang)
		i++;
	test_ang = (2 * M_PI) * i / (360 * func->prec);
	if (test_ang == ang)
		return (func->tan[i]);
	else
	{
		res = (func->tan[i] - func->tan[i - 1]) *
		((ang - (2 * M_PI * (i - 1) / (360 * func->prec)))
		/ (test_ang - (2 * M_PI * (i - 1) / (360 * func->prec))))
		+ func->tan[i - 1];
		return (res);
	}
	return (res);
}
