/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblin <ayblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:14:34 by ayblin            #+#    #+#             */
/*   Updated: 2022/04/15 16:09:19 by ayblin           ###   ########.fr       */
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
	m->img_man = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/character.xpm",&x,&x);
	m->img_item = mlx_xpm_file_to_image(m->mlx_ptr,"sprites/32/item.xpm",&x,&x);
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
	(void)m;
	return (1);
}

int	loop(t_long *m)
{
	m->rate++;
	if (m->rate == FRAME_RATE)
	{
		m->rate = 0;
		m->frame++;
		if (m->frame == FRAME)
			m->frame = 0;
		write(1,"oui",3);
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
	m.map = read_map(argv);
	m.maptab = ft_split(m.map, '\n');
	if (!is_valid_map(m.map, m.maptab,  &m))
		return (ft_putstr("Error\n", 0));
	printf("%d,%d",m.height,m.width);
    m.mlx_ptr = mlx_init();
    m.win_ptr = mlx_new_window(m.mlx_ptr, m.width, m.height, "test");
	get_image(&m);
	init_map(&m);
	mlx_key_hook(m.win_ptr, deal_key, &m);
	mlx_loop_hook(m.mlx_ptr, loop,&m);
	mlx_loop(m.mlx_ptr);
}