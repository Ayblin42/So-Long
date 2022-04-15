CC            =    gcc

FLAGS        =    -Wall -Werror -Wextra

RM            =    rm -f

SRCS        =   so_long.c \
				utils/ft_strjoin.c \
				utils/ft_strlen.c \
				utils/ft_split.c \
				utils/ft_putstr.c \
				is_valid_map.c \
				init_map.c \
				moove.c \

OBJS        =    ${SRCS:.c=.o}

MLX            =    ../minilibx-linux/libmlx_Linux.a

MLXFLAGS    =    -lX11 -lXext

NAME        =    so_long

all            :    ${NAME}

${NAME}	:	${OBJS}
			${CC} ${FLAGS} ${OBJS} -o ${NAME} ${MLX} ${MLXFLAGS}

.c.o	:
			$(CC) $(FLAGS) -I/usr/include -Iminilibx-linux -c $< -o $@

clean	:
		${RM} ${OBJS}

fclean	:	clean
			${RM} ${NAME}

re	:	fclean    all

.PHONY	:	all clean fclean re libft bonus