/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:05:58 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/24 13:23:25 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != (char)c && s[i] != 0)
		i++;
	if (s[i] == (char)c)
	{
		return ((char*)&s[i]);
	}
	return (NULL);
}
