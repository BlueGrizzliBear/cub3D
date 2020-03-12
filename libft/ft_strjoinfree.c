/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:22:57 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/24 13:45:15 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(const char *s1, const char *s2, int choice)
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
	(choice == 1 ? free((char*)s1) : free((char*)s2));
	return (c);
}
