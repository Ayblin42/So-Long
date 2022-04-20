/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gob_moove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblin <ayblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:08:42 by ayblin            #+#    #+#             */
/*   Updated: 2022/04/20 14:56:45 by ayblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	gob_up(t_long *m, int i, int j)
{
	if (i - 1 == m->y && j == m->x)
		m->end = 1;
	m->maptab[i - 1][j] = 'N';
	m->maptab[i][j] = '0';
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->gob[0],
		j * 32, (i - 1) * 32);
}

void	gob_down(t_long *m, int i, int j)
{
	if (i + 1 == m->y && j == m->x)
		m->end = 1;
	m->maptab[i + 1][j] = 'G';
	m->maptab[i][j] = '0';
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->gob[3],
		j * 32, (i + 1) * 32);
}

void	gob_right(t_long *m, int i, int j)
{
	if (i == m->y && j + 1 == m->x)
		m->end = 1;
	m->maptab[i][j + 1] = 'M';
	m->maptab[i][j] = '0';
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->gob[6],
		(j + 1) * 32, i * 32);
}

void	gob_left(t_long *m, int i, int j)
{
	if (i == m->y && j - 1 == m->x)
		m->end = 1;
	m->maptab[i][j - 1] = 'B';
	m->maptab[i][j] = '0';
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->gob[9],
		(j - 1) * 32, i * 32);
}
