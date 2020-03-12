/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:40:26 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/24 13:21:04 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n > 0)
	{
		while (((unsigned char*)s1)[i] == ((unsigned char*)s2)[i]
				&& i < n - 1)
			i++;
		return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
	}
	return (0);
}
