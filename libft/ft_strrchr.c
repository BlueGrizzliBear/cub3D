/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:05:58 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/24 13:24:43 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	i = ft_strlen((char*)s);
	while (s[i] != c && i != 0)
		i--;
	if (s[i] == c)
		return ((char*)&s[i]);
	return (NULL);
}
