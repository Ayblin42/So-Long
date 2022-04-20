/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gob.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblin <ayblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 09:37:44 by ayblin            #+#    #+#             */
/*   Updated: 2022/04/20 15:00:24 by ayblin           ###   ########.fr       */
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
					gob_display_down(m, i, j);
				if (m->maptab[i][j] == 'M')
					gob_display_right(m, i, j);
				if (m->maptab[i][j] == 'N')
					gob_display_up(m, i, j);
				if (m->maptab[i][j] == 'B')
					gob_display_left(m, i, j);
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
		gob_up(m, i, j);
	else if (m->gob_ori == 1 && m->maptab[i + 1][j] == '0')
		gob_down(m, i, j);
	else if (m->gob_ori == 2 && m->maptab[i][j + 1] == '0')
		gob_right(m, i, j);
	else if (m->gob_ori == 3 && m->maptab[i][j - 1] == '0')
		gob_left(m, i, j);
	put_image('0', i, j, m);
}

void	moove_trap(t_long *m, int i, int j, int g)
{
	int	mooved;

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
