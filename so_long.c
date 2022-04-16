/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblin <ayblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:14:34 by ayblin            #+#    #+#             */
/*   Updated: 2022/04/16 10:11:43 by ayblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char * read_map(char **argv)
{
	char 	*str;
	char	*buff;
	char	*tmp;
	int		fd;

	buff = malloc(sizeof(char) * 2);
	str = malloc(sizeof(char) * 2);
	fd = open(argv[1],O_RDONLY);
	while (read(fd, buff, 1) > 0)
	{
		tmp = str;
		str = ft_strjoin(str, buff);
		free(tmp);
	}
	return(str);
}

void	get_image(t_long *m)
{
	int	x = 32;
	m->img_wall = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/wall.xpm",&x,&x);
	m->img_tile = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/tile.xpm",&x,&x);
	m->img_exit = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/exit.xpm",&x,&x);
	m->img_item = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/item.xpm",&x,&x);
	m->man[0] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/up_1.xpm",&x,&x);
	m->man[1] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/up_2.xpm",&x,&x);
	m->man[2] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/up_3.xpm",&x,&x);
	m->man[3] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/down_1.xpm",&x,&x);
	m->man[4] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/down_2.xpm",&x,&x);
	m->man[5] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/down_3.xpm",&x,&x);
	m->man[6] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/right_1.xpm",&x,&x);
	m->man[7] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/right_2.xpm",&x,&x);
	m->man[8] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/right_3.xpm",&x,&x);
	m->man[9] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/left_1.xpm",&x,&x);
	m->man[10] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/left_2.xpm",&x,&x);
	m->man[11] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/left_3.xpm",&x,&x);
	m->trap[0] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/trap1.xpm",&x,&x);
	m->trap[1] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/trap2.xpm",&x,&x);
	m->trap[2] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/trap3.xpm",&x,&x);
	m->trap[3] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/trap4.xpm",&x,&x);
	m->trap[4] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/trap5.xpm",&x,&x);
	m->trap[5] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/trap6.xpm",&x,&x);
	m->trap[6] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/trap7.xpm",&x,&x);
	m->trap[7] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/trap8.xpm",&x,&x);
	m->gob[0] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/gob1.xpm",&x,&x);
	m->gob[1] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/gob2.xpm",&x,&x);
	m->gob[2] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/gob3.xpm",&x,&x);
	m->gob[3] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/gob4.xpm",&x,&x);
	m->gob[4] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/gob5.xpm",&x,&x);
	m->gob[5] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/gob6.xpm",&x,&x);
	m->gob[6] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/gob7.xpm",&x,&x);
	m->gob[7] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/gob8.xpm",&x,&x);
	m->gob[8] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/gob9.xpm",&x,&x);
	m->gob[9] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/gob10.xpm",&x,&x);
	m->gob[10] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/gob11.xpm",&x,&x);
	m->gob[11] = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/gob12.xpm",&x,&x);
}

int	deal_key(int key, t_long *m)
{
	if (key == 'z')
		moove_up(m);
	if (key == 'q')
		moove_left(m);
	if (key == 's')
		moove_down(m);
	if (key == 'd')
		moove_right(m);
	return (1);
}

int	loop(t_long *m)
{
	(void)m;
	m->rate++;
	if (m->rate == FRAME_RATE)
	{
		gob_display(m);
		m->gob_rate++;
		m->rate = 0;
		m->frame++;
		trap(m);
		if (m->frame == FRAME)
			m->frame = 0;
		if(m->frame % 3 == 0)
		 	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr,m->man[0 + (m->ori * 3)], m->x * 32, m->y * 32);
		if(m->frame % 3 == 1)
			mlx_put_image_to_window(m->mlx_ptr, m->win_ptr,m->man[1 + (m->ori * 3)], m->x * 32, m->y * 32);
		if(m->frame % 3 == 2)
			mlx_put_image_to_window(m->mlx_ptr, m->win_ptr,m->man[2 + (m->ori * 3)], m->x * 32, m->y * 32);
		if (m->gob_rate == (TRAP_RATE / m->gob_nb))
		{
			m->gob_rate = 0;
			moove_trap(m);
		}
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_long	m;
	
	if (argc != 2)
		return (0);
	m.rate = 0;
	m.frame = 0;
	m.ori = 0;
	m.gob_ori = 0;
	m.gob_nb = 0;
	m.gob_rate = 0;
	m.map = read_map(argv);
	m.maptab = ft_split(m.map, '\n');
	if (!is_valid_map(m.map, m.maptab,  &m))
		return (ft_putstr("Error\n", 0));
    m.mlx_ptr = mlx_init();
    m.win_ptr = mlx_new_window(m.mlx_ptr, m.width, m.height, "test");
	get_image(&m);
	init_map(&m);
	mlx_key_hook(m.win_ptr, deal_key, &m);
	mlx_loop_hook(m.mlx_ptr, loop,&m);
	mlx_loop(m.mlx_ptr);
}