/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 08:15:39 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/24 13:22:45 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*temp1;
	char	*temp2;
	int		i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	temp1 = (char*)dst;
	temp2 = (char*)src;
	if (temp1 == temp2)
		return (dst);
	if (temp1 < temp2)
		ft_memcpy(temp1, temp2, len);
	else
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			temp1[i] = temp2[i];
			i--;
		}
	}
	dst = temp1;
	return (dst);
}
