/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblin <ayblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:16:55 by ayblin            #+#    #+#             */
/*   Updated: 2022/04/20 14:53:02 by ayblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_charset(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	wall_check(char **maptab, int len, t_long *m)
{
	int	i;
	int	y;

	i = 0;
	while (maptab[i])
	{
		if (ft_strlen(maptab[i]) != len)
			return (0);
		if (maptab[i][0] != '1' || maptab[i][len - 1] != '1')
			return (0);
		i++;
	}
	m->height = i * 32;
	i--;
	y = 0;
	while (maptab[0][y])
	{
		if (maptab[0][y] != '1' || maptab[i][y] != '1' )
			return (0);
		y++;
	}
	return (1);
}

int	is_valid_map(t_long *m)
{
	int	len;

	len = ft_strlen(m->maptab[0]);
	if (!iter(m, 0, 0, len))
		return (0);
	m->item = 0;
	m->width = len * 32;
	if (!wall_check(m->maptab, len, m))
		return (0);
	return (1);
}

int	iter(t_long *m, int p, int i, int len)
{
	m->item_nb = 0;
	while (m->map[i])
	{
		if (!is_charset(m->map[i], "01CEPXG\n"))
			return (0);
		if (m->map[i] == 'P')
		{
			m->x = i % (len + 1);
			m->y = i / (len + 1);
			p++;
		}
		if (m->map[i] == 'G')
			m->gob_nb++;
		if (m->map[i] == 'C')
			m->item_nb++;
		i++;
	}
	if (p != 1)
		return (0);
	return (1);
}
