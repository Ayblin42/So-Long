/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gob.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblin <ayblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 09:37:44 by ayblin            #+#    #+#             */
/*   Updated: 2022/04/17 14:28:11 by ayblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	gob_display(t_long *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (m->maptab[i])
	{
		j = 0;
		while (m->maptab[i][j])
		{
			if (is_charset(m->maptab[i][j], "GMNB"))
			{
				if (m->maptab[i][j] == 'G')
					gob_moove_down(m, i, j);
				if (m->maptab[i][j] == 'M')
					gob_moove_right(m, i, j);
				if (m->maptab[i][j] == 'N')
					gob_moove_up(m, i, j);
				if (m->maptab[i][j] == 'B')
					gob_moove_left(m, i, j);
			}
			j++;
		}
		i++;
	}
}

void	rand_moove(t_long *m, int i, int j)
{
	m->gob_ori = rand() % 4;
	if (m->gob_ori == 0 && m->maptab[i - 1][j] == '0')
	{
		if (i - 1 == m->y && j == m->x)
			m->end = 1;
		m->maptab[i - 1][j] = 'N';
		m->maptab[i][j] = '0';
	}
	else if (m->gob_ori == 1 && m->maptab[i + 1][j] == '0')
	{
		if (i + 1 == m->y && j == m->x)
			m->end = 1;
		m->maptab[i + 1][j] = 'G';
		m->maptab[i][j] = '0';
	}
	else if (m->gob_ori == 2 && m->maptab[i][j + 1] == '0')
	{
		if (i == m->y && j + 1 == m->x)
			m->end = 1;
		m->maptab[i][j + 1] = 'M';
		m->maptab[i][j] = '0';
	}
	else if (m->gob_ori == 3 && m->maptab[i][j - 1] == '0')
	{
		if (i == m->y && j - 1 == m->x)
			m->end = 1;
		m->maptab[i][j - 1] = 'B';
		m->maptab[i][j] = '0';
	}
	put_image('0', i, j, m);
}

void	moove_trap(t_long *m)
{
	int	i;
	int	j;
	int	mooved;
	int	g;

	i = 0;
	j = 0;
	g = 0;
	mooved = (rand() % m->gob_nb) + 1;
	while (m->maptab[i])
	{
		j = 0;
		while (m->maptab[i][j])
		{
			if (is_charset(m->maptab[i][j], "GMNB"))
			{
				g++;
				if (g == mooved)
				{
					rand_moove(m, i, j);
					break ;
				}
			}
			j++;
		}
		i++;
	}
}
