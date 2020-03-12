/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:19:44 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/24 13:19:45 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	int i;
	int j;

	i = ft_isalpha(c);
	j = ft_isdigit(c);
	if (!(i == 0 && j == 0))
		return (1);
	return (0);
}
