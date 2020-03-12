/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:44:32 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/24 13:24:38 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strncmp((char*)needle, "", 1) == 0)
		return ((char*)haystack);
	if (ft_strncmp((char*)haystack, "", 1) == 0)
		return (NULL);
	while (i + ft_strlen((char*)needle) - 1 < len)
	{
		if (ft_strncmp(&(haystack)[i], (char*)needle,
					ft_strlen((char*)needle)) == 0)
			return (&((char*)haystack)[i]);
		i++;
	}
	return (NULL);
}
