/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 15:53:07 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/24 13:20:34 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n, int base)
{
	int	size;

	size = 0;
	while (n >= base)
	{
		size++;
		n = n / base;
	}
	return (size + 1);
}

char		*ft_itoa_base(int n, int base, char index)
{
	int		size;
	char	*s;

	size = ft_size(n, base);
	if (!(s = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	s[size--] = '\0';
	while (n >= base)
	{
		if (n % base >= 10)
			s[size--] = (index == 'x' ? (n % base - 10) + 'a' :
									(n % base - 10) + 'A');
		else
			s[size--] = n % base + '0';
		n = n / base;
	}
	if (n >= 10)
		s[size--] = (index == 'x' ? (n - 10) + 'a' : (n - 10) + 'A');
	else
		s[size--] = n + '0';
	return (s);
}
