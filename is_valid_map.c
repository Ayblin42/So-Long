/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblin <ayblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:16:55 by ayblin            #+#    #+#             */
/*   Updated: 2022/04/23 07:53:00 by ayblin           ###   ########.fr       */
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
	if (!min_map(m, 0, len))
		return (0);
	if (!iter(m, 0, 0, len))
		return (0);
	m->item = 0;
	m->width = len * 32;
	if (!wall_check(m->maptab, len, m))
		return (ft_putstr("Map is not square\n", 0));
	return (1);
}

int	iter(t_long *m, int p, int i, int len)
{
	int	e;

	e = 0;
	m->item_nb = 0;
	while (m->map[i])
	{
		if (!is_charset(m->map[i], "01CEPXG\n"))
			return (ft_putstr("invalid character in the map\n", 0));
		if (m->map[i] == 'P')
		{
			m->x = i % (len + 1);
			m->y = i / (len + 1);
			p++;
		}
		if (m->map[i] == 'E')
			e++;
		if (m->map[i] == 'G')
			m->gob_nb++;
		if (m->map[i] == 'C')
			m->item_nb++;
		i++;
	}
	if (p != 1|| e < 1)
		return (ft_putstr("invalid Player or exit number\n", 0));
	return (1);
}

int	min_map(t_long *m, int i, int len)
{
	int	nb;
	int lentab;

	lentab = 0;
	nb = 0;
	while (m->map[i])
	{
		if(is_charset(m->map[i], "01CEPXG"))
			nb++;
		i++;
	}
	while (m->maptab[lentab])
		lentab++;
	if (nb < 16 || len < 3 ||  lentab < 3)
		return(ft_putstr("Empty or too small map\n", 0));
	return (1);
}