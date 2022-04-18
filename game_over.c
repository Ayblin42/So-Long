/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblin <ayblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 22:23:50 by ayblin            #+#    #+#             */
/*   Updated: 2022/04/18 05:02:29 by ayblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_clean(t_long *m)
{
	free_tab(m->maptab);
	free(m->map);
}

void	game_over(t_long *m)
{
	mlx_clear_window(m->mlx_ptr, m->win_ptr);
	if (m->end == 1)
	{
		mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->over,
			(m->width / 2) - 80, (m->height / 2) - 80);
	}
	else if (m->end == 2)
	{
		mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->win,
			(m->width / 2) - 80, (m->height / 2) - 80);
	}
	m->end = 3;
	free_tab(m->maptab);
	free(m->map);
}
