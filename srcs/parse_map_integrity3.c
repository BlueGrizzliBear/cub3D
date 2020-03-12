/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_integrity3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 19:06:49 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/25 14:10:21 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_copy_map_table(char **table)
{
	char	**t;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = 0;
	while (table[size] != NULL)
		size++;
	if ((t = malloc((size + 1) * sizeof(char*))) == NULL)
		return (NULL);
	while (i < size)
	{
		t[i] = ft_strdup(table[i]);
		i++;
	}
	t[i] = 0;
	return (t);
}

int		ft_check_outside(char **t, t_reso pos, int size)
{
	if (!(pos.x + 1 < (int)ft_strlen(t[pos.y])) || !(pos.x - 1 >= 0) ||
	!(pos.y - 1 >= 0 && pos.x < (int)ft_strlen(t[pos.y - 1])) ||
	!(pos.y + 1 < size && pos.x < (int)ft_strlen(t[pos.y + 1])))
		return (-1);
	return (0);
}
