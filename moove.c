/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblin <ayblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 04:50:40 by ayblin            #+#    #+#             */
/*   Updated: 2022/04/16 09:08:36 by ayblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moove_up(t_long *m)
{
	if (m->maptab[m->y - 1][m->x] != '1')
	{
		if (m->maptab[m->y - 1][m->x] == 'C')
			m->item += 1;
		if (m->maptab[m->y - 1][m->x] == 'X' || m->maptab[m->y - 1][m->x] == 'G')
			mlx_destroy_window(m->mlx_ptr, m->win_ptr);
		if (m->maptab[m->y][m->x] == 'C')
			m->maptab[m->y][m->x] = '0';
		mlx_put_image_to_window(m->mlx_ptr, m->win_ptr,m->man[0], m->x * 32, (m->y - 1) * 32);
		put_image(m->maptab[m->y][m->x], m->y, m->x, m);
		 m->y -= 1;
		if (m->maptab[m->y][m->x] == 'E' && m->item == m->item_nb)
			mlx_destroy_window(m->mlx_ptr, m->win_ptr);
	}
	m->ori = 0;
}

void	moove_down(t_long *m)
{
	if (m->maptab[m->y + 1][m->x] != '1')
	{
		if (m->maptab[m->y + 1][m->x] == 'C')
			m->item += 1;
		if (m->maptab[m->y + 1][m->x] == 'X' || m->maptab[m->y + 1][m->x] == 'G')
			mlx_destroy_window(m->mlx_ptr, m->win_ptr);
		if (m->maptab[m->y][m->x] == 'C')
			m->maptab[m->y][m->x] = '0';
		mlx_put_image_to_window(m->mlx_ptr, m->win_ptr,m->man[3], m->x * 32, (m->y + 1) * 32);
		put_image(m->maptab[m->y][m->x], m->y, m->x, m);
		 m->y += 1;
		if (m->maptab[m->y][m->x] == 'E' && m->item == m->item_nb)
			mlx_destroy_window(m->mlx_ptr, m->win_ptr);
	}
	m->ori = 1;
}

void	moove_right(t_long *m)
{
	if (m->maptab[m->y][m->x + 1] != '1')
	{
		if (m->maptab[m->y][m->x + 1] == 'C')
			m->item += 1;
		if (m->maptab[m->y][m->x + 1] == 'X' || m->maptab[m->y][m->x + 1] == 'G')
			mlx_destroy_window(m->mlx_ptr, m->win_ptr);
		if (m->maptab[m->y][m->x] == 'C')
			m->maptab[m->y][m->x] = '0';
		mlx_put_image_to_window(m->mlx_ptr, m->win_ptr,m->man[6], (m->x + 1) * 32, m->y * 32);
		put_image(m->maptab[m->y][m->x], m->y, m->x, m);
		 m->x += 1;
		if (m->maptab[m->y][m->x] == 'E' && m->item == m->item_nb)
			mlx_destroy_window(m->mlx_ptr, m->win_ptr);
	}
	m->ori = 2;
}

void	moove_left(t_long *m)
{
	if (m->maptab[m->y][m->x - 1] != '1')
	{
		if (m->maptab[m->y][m->x - 1] == 'C')
			m->item += 1;
		if (m->maptab[m->y][m->x - 1] == 'X' || m->maptab[m->y][m->x - 1] == 'G')
			mlx_destroy_window(m->mlx_ptr, m->win_ptr);
		if (m->maptab[m->y][m->x] == 'C')
			m->maptab[m->y][m->x] = '0';
		mlx_put_image_to_window(m->mlx_ptr, m->win_ptr,m->man[9], (m->x - 1) * 32, m->y * 32);
		put_image(m->maptab[m->y][m->x], m->y, m->x, m);
		 m->x -= 1;
		if (m->maptab[m->y][m->x] == 'E' && m->item == m->item_nb)
			mlx_destroy_window(m->mlx_ptr, m->win_ptr);
	}
	m->ori = 3;
}