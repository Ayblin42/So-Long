/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gob_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblin <ayblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 09:55:47 by ayblin            #+#    #+#             */
/*   Updated: 2022/04/20 14:57:07 by ayblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	gob_display_up(t_long *m, int i, int j)
{
	if (m->frame % 3 == 0)
		mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->gob[0],
			j * 32, i * 32);
	if (m->frame % 3 == 1)
		mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->gob[1],
			j * 32, i * 32);
	if (m->frame % 3 == 2)
		mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->gob[2],
			j * 32, i * 32);
}

void	gob_display_down(t_long *m, int i, int j)
{
	if (m->frame % 3 == 0)
		mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->gob[3],
			j * 32, i * 32);
	if (m->frame % 3 == 1)
		mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->gob[4],
			j * 32, i * 32);
	if (m->frame % 3 == 2)
		mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->gob[5],
			j * 32, i * 32);
}

void	gob_display_right(t_long *m, int i, int j)
{
	if (m->frame % 3 == 0)
		mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->gob[6],
			j * 32, i * 32);
	if (m->frame % 3 == 1)
		mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->gob[7],
			j * 32, i * 32);
	if (m->frame % 3 == 2)
		mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->gob[8],
			j * 32, i * 32);
}

void	gob_display_left(t_long *m, int i, int j)
{
	if (m->frame % 3 == 0)
		mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->gob[9],
			j * 32, i * 32);
	if (m->frame % 3 == 1)
		mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->gob[10],
			j * 32, i * 32);
	if (m->frame % 3 == 2)
		mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->gob[11],
			j * 32, i * 32);
}
