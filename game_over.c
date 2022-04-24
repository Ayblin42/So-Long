/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblin <ayblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 22:23:50 by ayblin            #+#    #+#             */
/*   Updated: 2022/04/23 09:41:41 by ayblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}

void	destroy_image(t_long *m, int i)
{
	(void)i;
	mlx_destroy_image(m->mlx_ptr, m->img_wall);
	mlx_destroy_image(m->mlx_ptr, m->img_tile);
	mlx_destroy_image(m->mlx_ptr, m->img_exit);
	mlx_destroy_image(m->mlx_ptr, m->img_item);
	mlx_destroy_image(m->mlx_ptr, m->over);
	mlx_destroy_image(m->mlx_ptr, m->win);
	mlx_destroy_image(m->mlx_ptr, m->img_count);
	while (i < 12)
		mlx_destroy_image(m->mlx_ptr, m->man[i++]);
	i = 0;
	while (i < 12)
		mlx_destroy_image(m->mlx_ptr, m->gob[i++]);
	i = 0;
	while (i < 8)
		mlx_destroy_image(m->mlx_ptr, m->trap[i++]);
}

int	close_window(t_long *m)
{
	free_tab(m->maptab);
	free(m->map);
	destroy_image(m, 0);
	mlx_loop_end(m->mlx_ptr);
	mlx_clear_window(m->mlx_ptr, m->win_ptr);
	mlx_destroy_window(m->mlx_ptr, m->win_ptr);
	mlx_destroy_display(m->mlx_ptr);
	free(m->mlx_ptr);
	exit(0);
}

int	close_window2(t_long *m)
{
	free_tab(m->maptab);
	free(m->map);
	mlx_destroy_window(m->mlx_ptr, m->win_ptr);
	mlx_destroy_display(m->mlx_ptr);
	free(m->mlx_ptr);
	ft_putstr("Error: size of map too big .\n", 0);
	exit(0);
}

int	close_window3(t_long *m)
{
	free(m->map);
	return (0);
}

int	close_window4(t_long *m)
{
	free(m->map);
	free_tab(m->maptab);
	return (0);
}
