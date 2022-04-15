#ifndef SO_LONG_H
# define SO_LONG_H
# define READ_SIZE 1
# define FRAME_RATE 1000
# define FRAME 12

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

typedef struct s_long
{
	char 	*map;
	char 	**maptab;
	void	*img_wall;
	void	*img_tile;
	void	*img_exit;
	void	*img_man;
	void	*img_item;
	void 	*mlx_ptr;
    void 	*win_ptr;
	int		width;
	int		height;
	int		x;
	int		y;
	int		item;
	int		item_nb;
	int		rate;
	int		frame;
}	t_long;

int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int		ft_putstr(char *str, int ret);
int		is_valid_map(char *map, char **maptab, t_long *m);
void	init_map(t_long *m);
void	put_image(char c, int i, int j, t_long *m);
void	moove_up(t_long *m);
void	moove_down(t_long *m);
void	moove_right(t_long *m);
void	moove_left(t_long *m);

#endif