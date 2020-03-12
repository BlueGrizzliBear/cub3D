/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 21:14:19 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 08:54:06 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	ft_pass_numbers(char *str)
{
	int i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

int	ft_pass_spaces(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (i);
}
