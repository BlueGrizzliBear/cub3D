/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:18:57 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/24 13:18:58 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int k;
	int res;

	i = 0;
	k = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			k++;
		i++;
	}
	res = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		res = res * 10;
		res = res + str[i] - 48;
		i++;
	}
	if (k % 2 != 0)
		res = res * -1;
	return (res);
}
