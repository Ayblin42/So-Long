/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblin <ayblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:14:34 by ayblin            #+#    #+#             */
/*   Updated: 2022/04/23 19:52:59 by ayblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(char *argv)
{
	char	str[50000];
	char	c;
	int		i;
	int		fd;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 1)
		return (ftc_putstr("Failed to open file\n", 0));
	while (read(fd, &c, 1) > 0)
	{
		str[i] = c;
		i++;
	}
	str[i] = 0;
	if (!file_ber(argv, ft_strlen(argv)))
		return (0);
	return (ft_strdup(str));
}

int	file_ber(char *str, int	len)
{
	if (str[len - 1] != 'r')
		return(ft_putstr("not a .ber file\n", 0));
	if (str[len - 2] != 'e')
		return(ft_putstr("not a .ber file\n", 0));
	if (str[len - 3] != 'b')
		return(ft_putstr("not a .ber file\n", 0));
	if (str[len - 4] != '.')
		return(ft_putstr("not a .ber file\n", 0));
	return (1);
}

int	deal_key(int key, t_long *m)
{
	char	*str;

	if (m->end == 0 && is_charset(key, "zqsd"))
	{
		m->mv_count++;
		str = ft_itoa(m->mv_count);
		mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->img_count, 0, 0);
		mlx_string_put(m->mlx_ptr, m->win_ptr, 10, 15, 0x00FBFF, str);
		mlx_string_put(m->mlx_ptr, m->win_ptr, 11, 15, 0xFFFF16, str);
		free(str);
		if (key == 'z')
			moove_up(m);
		if (key == 'q')
			moove_left(m);
		if (key == 's')
			moove_down(m);
		if (key == 'd')
			moove_right(m);
	}
	else if (key == 65307)
		close_window(m);
	if (m->end == 1 || m->end == 2)
		game_over(m);
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
				moove_trap(m, 0, 0, 0);
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
	init_value(&m);
	m.map = read_map(argv[1]);
	if (!m.map)
		return (close_window3(&m));
	m.maptab = ft_split(m.map, '\n');
	if (!is_valid_map(&m))
		return (close_window4(&m));
	m.mlx_ptr = mlx_init();
	if (!m.mlx_ptr)
		return (close_window4(&m));
	m.win_ptr = mlx_new_window(m.mlx_ptr, m.width, m.height, "test");
	if (m.width > WIDTH_LIMIT || m.height > HEIGHT_LIMIT)
		close_window2(&m);
	get_image(&m);
	init_map(&m);
	mlx_hook(m.win_ptr, 17, 0, close_window, &m);
	mlx_key_hook(m.win_ptr, deal_key, &m);
	mlx_loop_hook(m.mlx_ptr, loop, &m);
	mlx_loop(m.mlx_ptr);
}
