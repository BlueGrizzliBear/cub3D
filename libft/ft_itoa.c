/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:34:44 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/24 13:20:41 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	count;

	count = 0;
	if (n < 0)
		count++;
	while (n / 10 != 0)
	{
		count++;
		n = n / 10;
	}
	count++;
	return (count);
}

static char	*ft_intmin(char *str)
{
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

static char	*ft_sort(int n, char *str, int i, int count)
{
	while (i > 0 || (i >= 0 && count == 1))
	{
		if (n <= 0)
		{
			if (n == 0)
				str[i--] = '0';
			else if (n < 0)
			{
				str[0] = '-';
				n = n / -1;
			}
		}
		if (n > 9)
		{
			str[i--] = n % 10 + '0';
			n = n / 10;
		}
		if (n <= 9 && n > 0)
			str[i--] = n + '0';
	}
	str[count] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	int		i;
	int		count;
	char	*str;

	i = 0;
	str = NULL;
	count = ft_count(n);
	if ((str = malloc((count + 1) * sizeof(char))) == NULL)
		return (NULL);
	i = count - 1;
	if (n == -2147483648)
	{
		str = ft_intmin(str);
		return (str);
	}
	str = ft_sort(n, str, i, count);
	return (str);
}
