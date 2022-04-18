/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblin <ayblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 09:11:13 by ayblin            #+#    #+#             */
/*   Updated: 2022/04/17 15:03:31 by ayblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_image2(t_long *m, int x, int h, int l)
{
	m->trap[0] = mlx_xpm_file_to_image(m->mlx_ptr, "32/trap1.xpm", &x, &x);
	m->trap[1] = mlx_xpm_file_to_image(m->mlx_ptr, "32/trap2.xpm", &x, &x);
	m->trap[2] = mlx_xpm_file_to_image(m->mlx_ptr, "32/trap3.xpm", &x, &x);
	m->trap[3] = mlx_xpm_file_to_image(m->mlx_ptr, "32/trap4.xpm", &x, &x);
	m->trap[4] = mlx_xpm_file_to_image(m->mlx_ptr, "32/trap5.xpm", &x, &x);
	m->trap[5] = mlx_xpm_file_to_image(m->mlx_ptr, "32/trap6.xpm", &x, &x);
	m->trap[6] = mlx_xpm_file_to_image(m->mlx_ptr, "32/trap7.xpm", &x, &x);
	m->trap[7] = mlx_xpm_file_to_image(m->mlx_ptr, "32/trap8.xpm", &x, &x);
	m->gob[0] = mlx_xpm_file_to_image(m->mlx_ptr, "32/gob1.xpm", &x, &x);
	m->gob[1] = mlx_xpm_file_to_image(m->mlx_ptr, "32/gob2.xpm", &x, &x);
	m->gob[2] = mlx_xpm_file_to_image(m->mlx_ptr, "32/gob3.xpm", &x, &x);
	m->gob[3] = mlx_xpm_file_to_image(m->mlx_ptr, "32/gob4.xpm", &x, &x);
	m->gob[4] = mlx_xpm_file_to_image(m->mlx_ptr, "32/gob5.xpm", &x, &x);
	m->gob[5] = mlx_xpm_file_to_image(m->mlx_ptr, "32/gob6.xpm", &x, &x);
	m->gob[6] = mlx_xpm_file_to_image(m->mlx_ptr, "32/gob7.xpm", &x, &x);
	m->gob[7] = mlx_xpm_file_to_image(m->mlx_ptr, "32/gob8.xpm", &x, &x);
	m->gob[8] = mlx_xpm_file_to_image(m->mlx_ptr, "32/gob9.xpm", &x, &x);
	m->gob[9] = mlx_xpm_file_to_image(m->mlx_ptr, "32/gob10.xpm", &x, &x);
	m->gob[10] = mlx_xpm_file_to_image(m->mlx_ptr, "32/gob11.xpm", &x, &x);
	m->gob[11] = mlx_xpm_file_to_image(m->mlx_ptr, "32/gob12.xpm", &x, &x);
	m->over = mlx_xpm_file_to_image(m->mlx_ptr, "32/over.xpm", &l, &l);
	m->win = mlx_xpm_file_to_image(m->mlx_ptr, "32/win.xpm", &l, &h);
	m->img_count = mlx_xpm_file_to_image(m->mlx_ptr, "32/count.xpm", &x, &x);
}

void	get_image(t_long *m)
{
	int	x;

	x = 32;
	m->img_wall = mlx_xpm_file_to_image(m->mlx_ptr, "32/wall.xpm", &x, &x);
	m->img_tile = mlx_xpm_file_to_image(m->mlx_ptr, "32/tile.xpm", &x, &x);
	m->img_exit = mlx_xpm_file_to_image(m->mlx_ptr, "32/exit.xpm", &x, &x);
	m->img_item = mlx_xpm_file_to_image(m->mlx_ptr, "32/item.xpm", &x, &x);
	m->man[0] = mlx_xpm_file_to_image(m->mlx_ptr, "32/up_1.xpm", &x, &x);
	m->man[1] = mlx_xpm_file_to_image(m->mlx_ptr, "32/up_2.xpm", &x, &x);
	m->man[2] = mlx_xpm_file_to_image(m->mlx_ptr, "32/up_3.xpm", &x, &x);
	m->man[3] = mlx_xpm_file_to_image(m->mlx_ptr, "32/down_1.xpm", &x, &x);
	m->man[4] = mlx_xpm_file_to_image(m->mlx_ptr, "32/down_2.xpm", &x, &x);
	m->man[5] = mlx_xpm_file_to_image(m->mlx_ptr, "32/down_3.xpm", &x, &x);
	m->man[6] = mlx_xpm_file_to_image(m->mlx_ptr, "32/right_1.xpm", &x, &x);
	m->man[7] = mlx_xpm_file_to_image(m->mlx_ptr, "32/right_2.xpm", &x, &x);
	m->man[8] = mlx_xpm_file_to_image(m->mlx_ptr, "32/right_3.xpm", &x, &x);
	m->man[9] = mlx_xpm_file_to_image(m->mlx_ptr, "32/left_1.xpm", &x, &x);
	m->man[10] = mlx_xpm_file_to_image(m->mlx_ptr, "32/left_2.xpm", &x, &x);
	m->man[11] = mlx_xpm_file_to_image(m->mlx_ptr, "32/left_3.xpm", &x, &x);
	get_image2(m, 32, 128, 160);
}
