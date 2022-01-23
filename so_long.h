#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "gnl/get_next_line.h"

#define WIN_WIDTH 500
#define WIN_HEIGHT 900

typedef struct	s_window
{
	int	x;
	int	y;
}				t_window;

typedef struct	s_collect
{
	int	number_item_to_collect;
}				t_collect;

typedef struct s_game
{
	void *win;
	void *mlx;
	void *background;
	void *character;
	void *exit;
	void *item;
	void *wall;

	char	**map;
	int	map_x;
	int	map_y;
	int	character_x;
	int	character_y;
	t_window	window;
	t_collect	collect;
}               t_game;

char     **get_line(char **map, char *new_line);


int		hanlde_input(int keysym, t_game *game);
int	handle_event();
int	destroy_win(t_game *game);
int verif_limit(char **map);
int verif_intern(char **map);
int verif_map(char **map);

void    get_map(int fd, t_game *game);
void	print_map(t_game *game, int pst_x, int pst_y);
void	update_map(t_game *game, int i, int j);

#endif