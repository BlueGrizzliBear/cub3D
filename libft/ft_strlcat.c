/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:12:12 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/24 13:24:11 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lensrc;
	size_t	lendst;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	lensrc = ft_strlen((char*)src);
	lendst = ft_strlen((char*)dst);
	if (lendst > size)
		return (lensrc + size);
	if (lensrc == 0)
		return (lendst);
	while (dst[i])
		i++;
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (lendst + lensrc);
}
