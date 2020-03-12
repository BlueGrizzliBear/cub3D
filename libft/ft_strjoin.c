/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:17:37 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/24 13:23:40 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*c;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = -1;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	k = i + j;
	if (!((c = malloc((1 + k) * sizeof(char)))))
		return (NULL);
	i = -1;
	while (s1[++i])
		c[i] = s1[i];
	j = -1;
	while (s2[++j])
		c[j + i] = s2[j];
	c[j + i] = '\0';
	return (c);
}
