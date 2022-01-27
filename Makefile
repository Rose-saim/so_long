MANDA_NAMES = 	so_long.c hooks.c print_map.c free_and_exit.c open_pictures.c parsing_map.c \
				mouvements.c gnl/get_next_line.c gnl/get_next_line_utils.c \
				printf/functions_utils.c printf/functions_conversions.c printf/printf.c

MANDA_OBJS =	 $(MANDA_NAMES:.c=.o)

NAME = so_long

CC = clang
CFLAGS = -Wall -Wextra -Werror -g
MLX = mlx/libmlx_Linux.a -lX11 -lXext

AR = ar rc

RM = rm -f

RL = ranlib

$(NAME):	$(MANDA_OBJS)
			make -C mlx
			$(CC) $(CFLAGS) $(MANDA_OBJS) $(MLX) -o $(NAME)

all:		$(NAME)

clean:	
			$(RM) $(MANDA_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

malloc_test: $(MANDA_OBJS)
	make -C mlx
	$(CC) $(CFLAGS) -fsanitize=undefined -rdynamic -o $@ ${MANDA_OBJS} $(MLX) -L. -lmallocator

.PHONY:		all bonus clean fclean re