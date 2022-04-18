/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblin <ayblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:14:34 by ayblin            #+#    #+#             */
/*   Updated: 2022/04/18 05:07:38 by ayblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(char **argv)
{
	char	*str;
	char	*buff;
	char	*tmp;
	int		fd;

	buff = malloc(sizeof(char) * 2);
	str = malloc(sizeof(char) * 2);
	fd = open(argv[1], O_RDONLY);
	while (read(fd, buff, 1) > 0)
	{
		tmp = str;
		str = ft_strjoin(str, buff);
		free(tmp);
	}
	return (str);
}

int	deal_key(int key, t_long *m)
{
	char	*str;

	str = ft_itoa(m->mv_count);
	if (m->end == 0 && is_charset(key, "zqsd"))
	{
		m->mv_count++;
		mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->img_count, 0, 0);
		mlx_string_put(m->mlx_ptr, m->win_ptr, 10, 15, 0x00FBFF, str);
		mlx_string_put(m->mlx_ptr, m->win_ptr, 11, 15, 0xFFFF16, str);
		if (key == 'z')
			moove_up(m);
		if (key == 'q')
			moove_left(m);
		if (key == 's')
			moove_down(m);
		if (key == 'd')
			moove_right(m);
		//if (key == '\')
		//	write(1, "oui", 1);
	}
	else if (m->end == 1 || m->end == 2)
		game_over(m);
	free(str);
	return (1);
}

int	loop(t_long *m)
{
	if (m->end == 0)
	{
		m->rate++;
		if (m->rate == FRAME_RATE)
		{
			gob_display(m);
			m->gob_rate++;
			m->rate = 0;
			m->frame++;
			trap_display(m);
			if (m->frame == FRAME)
				m->frame = 0;
			man_display(m);
			if (m->gob_nb && m->gob_rate == (TRAP_RATE / m->gob_nb))
			{
				m->gob_rate = 0;
				moove_trap(m);
			}
		}
	}
	else if (m->end == 1 || m->end == 2)
		game_over(m);
	return (1);
}

int	main(int argc, char **argv)
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
	m.end = 0;
	m.mv_count = 1;
	m.map = read_map(argv);
	m.maptab = ft_split(m.map, '\n');
	if (!is_valid_map(m.map, m.maptab, &m))
		return (ft_putstr("Error\n", 0));
	m.mlx_ptr = mlx_init();
	m.win_ptr = mlx_new_window(m.mlx_ptr, m.width, m.height, "test");
	get_image(&m);
	init_map(&m);
	mlx_key_hook(m.win_ptr, deal_key, &m);
	mlx_loop_hook(m.mlx_ptr, loop, &m);
	mlx_loop(m.mlx_ptr);
}
