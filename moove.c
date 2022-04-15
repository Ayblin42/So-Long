/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblin <ayblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 04:50:40 by ayblin            #+#    #+#             */
/*   Updated: 2022/04/15 14:03:04 by ayblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moove_up(t_long *m)
{
	if (m->maptab[m->y - 1][m->x] != '1')
	{
		if (m->maptab[m->y - 1][m->x] == 'C')
			m->item += 1;
		if (m->maptab[m->y][m->x] == 'C')
			m->maptab[m->y][m->x] = '0';
		put_image(m->maptab[m->y][m->x], m->y, m->x, m);
 		mlx_put_image_to_window(m->mlx_ptr, m->win_ptr,m->img_man, m->x * 32, (m->y - 1) * 32);
		 m->y -= 1;
		if (m->maptab[m->y][m->x] == 'E' && m->item == m->item_nb)
			mlx_destroy_window(m->mlx_ptr, m->win_ptr);
	}
}

void	moove_down(t_long *m)
{
	if (m->maptab[m->y + 1][m->x] != '1')
	{
		if (m->maptab[m->y + 1][m->x] == 'C')
			m->item += 1;
		if (m->maptab[m->y][m->x] == 'C')
			m->maptab[m->y][m->x] = '0';
		put_image(m->maptab[m->y][m->x], m->y, m->x, m);
 		mlx_put_image_to_window(m->mlx_ptr, m->win_ptr,m->img_man, m->x * 32, (m->y + 1) * 32);
		 m->y += 1;
		if (m->maptab[m->y][m->x] == 'E' && m->item == m->item_nb)
			mlx_destroy_window(m->mlx_ptr, m->win_ptr);
	}
}

void	moove_right(t_long *m)
{
	if (m->maptab[m->y][m->x + 1] != '1')
	{
		if (m->maptab[m->y][m->x + 1] == 'C')
			m->item += 1;
		if (m->maptab[m->y][m->x] == 'C')
			m->maptab[m->y][m->x] = '0';
		put_image(m->maptab[m->y][m->x], m->y, m->x, m);
 		mlx_put_image_to_window(m->mlx_ptr, m->win_ptr,m->img_man, (m->x + 1) * 32, m->y * 32);
		 m->x += 1;
		if (m->maptab[m->y][m->x] == 'E' && m->item == m->item_nb)
			mlx_destroy_window(m->mlx_ptr, m->win_ptr);

	}
}

void	moove_left(t_long *m)
{
	if (m->maptab[m->y][m->x - 1] != '1')
	{
		if (m->maptab[m->y][m->x - 1] == 'C')
			m->item += 1;
		if (m->maptab[m->y][m->x] == 'C')
			m->maptab[m->y][m->x] = '0';
		put_image(m->maptab[m->y][m->x], m->y, m->x, m);
 		mlx_put_image_to_window(m->mlx_ptr, m->win_ptr,m->img_man, (m->x - 1) * 32, m->y * 32);
		 m->x -= 1;
		if (m->maptab[m->y][m->x] == 'E' && m->item == m->item_nb)
			mlx_destroy_window(m->mlx_ptr, m->win_ptr);
	}
}