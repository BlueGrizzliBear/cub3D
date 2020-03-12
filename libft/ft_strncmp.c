/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:42:23 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/24 13:24:31 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n > 0)
	{
		while (((unsigned char*)s1)[i] == ((unsigned char*)s2)[i]
				&& s2[i] != '\0' && s1[i] != '\0' && i < n - 1)
			i++;
		return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
	}
	return (0);
}
