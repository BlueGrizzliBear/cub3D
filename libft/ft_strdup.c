/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:24:06 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/24 13:23:32 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*c;
	int		size;

	size = ft_strlen((char*)s1);
	if ((c = malloc(size * sizeof(char) + 1)) == NULL)
		return (NULL);
	ft_memcpy(c, s1, size);
	c[size] = '\0';
	return (c);
}
