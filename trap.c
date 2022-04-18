/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblin <ayblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 05:00:47 by ayblin            #+#    #+#             */
/*   Updated: 2022/04/17 14:13:07 by ayblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	trap_display(t_long *m)
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
			if (m->maptab[i][j] == 'X')
				mlx_put_image_to_window(m->mlx_ptr, m->win_ptr,
					m->trap[m->frame % 8], j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	man_display(t_long *m)
{
	if (m->frame % 3 == 0)
		mlx_put_image_to_window(m->mlx_ptr, m->win_ptr,
			m->man[0 + m->ori], m->x * 32, m->y * 32);
	if (m->frame % 3 == 1)
		mlx_put_image_to_window(m->mlx_ptr, m->win_ptr,
			m->man[1 + m->ori], m->x * 32, m->y * 32);
	if (m->frame % 3 == 2)
		mlx_put_image_to_window(m->mlx_ptr, m->win_ptr,
			m->man[2 + m->ori], m->x * 32, m->y * 32);
}
