/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:56:27 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/24 13:24:50 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*c;

	c = NULL;
	if (!(char*)s || ft_strlen((char*)s) < start)
		return (ft_calloc(sizeof(char), 1));
	if ((c = malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	if (!(ft_strlen((char*)s) == start || ft_strlen((char*)s) == 0))
		ft_memcpy(c, &((char*)s)[start], len);
	c[len] = '\0';
	return (c);
}
