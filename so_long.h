/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblin <ayblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 13:50:57 by ayblin            #+#    #+#             */
/*   Updated: 2022/04/23 09:45:33 by ayblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define FRAME_RATE 3000
# define TRAP_RATE 25
# define FRAME 1536
# define HEIGHT_LIMIT 1920
# define WIDTH_LIMIT 1080

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdint.h>
# include <unistd.h>
# include <time.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

typedef struct s_long
{
	char	*map;
	char	**maptab;
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
	int		x;
	int		y;
	int		item;
	int		item_nb;
	int		rate;
	int		gob_rate;
	int		frame;
	int		ori;
	int		gob_ori;
	int		gob_nb;
	int		end;
	int		mv_count;

	void	*img_wall;
	void	*img_tile;
	void	*img_exit;
	void	*img_item;
	void	*man[12];
	void	*gob[12];
	void	*trap[8];
	void	*over;
	void	*win;
	void	*img_count;
}	t_long;

char	*ft_itoa(int n);
char	**free_tab(char **tab);
char	*ft_strdup(char *src);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int		ft_putstr(char *str, int ret);
char	*ftc_putstr(char *str, char *ret);
int		is_valid_map(t_long *m);
int		iter(t_long *m, int p, int i, int len);
void	init_map(t_long *m);
int		min_map(t_long *m, int i, int len);
void	init_value(t_long *m);
void	put_image(char c, int i, int j, t_long *m);
void	moove_up(t_long *m);
void	moove_down(t_long *m);
void	moove_right(t_long *m);
void	moove_left(t_long *m);
void	trap_display(t_long *m);
void	man_display(t_long *m);
void	gob_display(t_long *m);
void	moove_trap(t_long *m, int i, int j, int g);
int		is_charset(char c, char *str);
void	game_over(t_long *m);
void	get_image(t_long *m);
int		close_window(t_long *m);
int		close_window2(t_long *m);
int		close_window3(t_long *m);
int		close_window4(t_long *m);
int		file_ber(char *str, int	len);

void	gob_display_up(t_long *m, int i, int j);
void	gob_display_down(t_long *m, int i, int j);
void	gob_display_right(t_long *m, int i, int j);
void	gob_display_left(t_long *m, int i, int j);
void	gob_up(t_long *m, int i, int j);
void	gob_down(t_long *m, int i, int j);
void	gob_right(t_long *m, int i, int j);
void	gob_left(t_long *m, int i, int j);

#endif