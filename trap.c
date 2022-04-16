/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblin <ayblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 05:00:47 by ayblin            #+#    #+#             */
/*   Updated: 2022/04/16 09:38:17 by ayblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	trap(t_long *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(m->maptab[i])
	{
		j = 0;
		while(m->maptab[i][j])
		{
			if (m->maptab[i][j] == 'X')
				mlx_put_image_to_window(m->mlx_ptr, m->win_ptr,m->trap[m->frame % 8], j * 32, i * 32);
			j++;
		}
		i++;
	}
}

