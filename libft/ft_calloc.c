/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:17:01 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/24 13:26:54 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*c;
	size_t	i;

	i = 0;
	if (!(c = malloc(count * size)))
		return (NULL);
	while (i < (count * size))
	{
		c[i] = 0;
		i++;
	}
	return (c);
}
