MANDA_NAMES = 	so_long.c hooks.c print_map.c gnl/get_next_line.c gnl/get_next_line_utils.c

MANDA_OBJS =	 $(MANDA_NAMES:.c=.o)

NAME = so_long

CC = clang
CFLAGS = -Wall -Wextra -Werror 
MLX = -lX11 -lXext -lmlx

AR = ar rc

RM = rm -f

RL = ranlib

$(NAME):	$(MANDA_OBJS)
			$(CC) $(CFLAGS) $(MANDA_OBJS) $(MLX) -o $(NAME)

all:		$(NAME)

clean:	
			$(RM) $(MANDA_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re