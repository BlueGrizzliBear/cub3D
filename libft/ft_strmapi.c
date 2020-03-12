/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:32:43 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/24 13:24:26 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*c;
	int		i;

	i = 0;
	if (!(char*)s)
		return (ft_calloc(sizeof(char), 1));
	if (!(c = ft_strdup((char*)s)))
		return (NULL);
	while (c[i])
	{
		c[i] = f(i, c[i]);
		i++;
	}
	return (c);
}
