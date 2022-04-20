/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblin <ayblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 05:58:24 by ayblin            #+#    #+#             */
/*   Updated: 2022/04/20 14:30:29 by ayblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(char c, int i, int j, t_long *m)
{
	if (c == '1')
		mlx_put_image_to_window(m->mlx_ptr,
			m->win_ptr, m->img_wall, j * 32, i * 32);
	if (c == '0')
		mlx_put_image_to_window(m->mlx_ptr,
			m->win_ptr, m->img_tile, j * 32, i * 32);
	if (c == 'E')
		mlx_put_image_to_window(m->mlx_ptr,
			m->win_ptr, m->img_exit, j * 32, i * 32);
	if (c == 'C')
		mlx_put_image_to_window(m->mlx_ptr,
			m->win_ptr, m->img_item, j * 32, i * 32);
}

void	init_map(t_long *m)
{
	int	i;
	int	j;

	i = 0;
	while (m->maptab[i])
	{
		j = 0;
		while (m->maptab[i][j])
		{
			put_image(m->maptab[i][j], i, j, m);
			j++;
		}
		i++;
	}
	m->maptab[m->y][m->x] = '0';
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->img_count, 0, 0);
}

void	init_value(t_long *m)
{
	m->rate = 0;
	m->frame = 0;
	m->ori = 0;
	m->gob_ori = 0;
	m->gob_nb = 0;
	m->gob_rate = 0;
	m->end = 0;
	m->mv_count = 1;
}
