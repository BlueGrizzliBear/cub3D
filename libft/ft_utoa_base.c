/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:08:55 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/24 13:25:02 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(unsigned long long n, unsigned base)
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

char		*ft_utoa_base(unsigned long long n, unsigned base)
{
	int		size;
	char	*s;

	size = ft_size(n, base) + 2;
	if (!(s = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	s[size--] = '\0';
	while (n >= base)
	{
		if (n % base >= 10)
			s[size--] = n % base - 10 + 'a';
		else
			s[size--] = n % base + '0';
		n = n / base;
	}
	s[size--] = n >= 10 ? n - 10 + 'a' : n + '0';
	s[size--] = 'x';
	s[size--] = '0';
	return (s);
}
