/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:30:03 by myrmarti          #+#    #+#             */
/*   Updated: 2022/01/28 16:30:42 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"
# include "printf/ft_printf.h"

typedef struct s_window
{
	int	x;
	int	y;
}				t_window;

typedef struct s_image
{
	void	*background;
	void	*character;
	void	*exit;
	void	*item;
	void	*wall;
}				t_image;

typedef struct s_collect
{
	int	number_item_to_collect;
	int	exit_game;
	int	perso;
	int	item;
	int	wall;
}				t_collect;

typedef struct s_localisation
{
	int			move;
	int			character_x;
	int			character_y;
}				t_localisation;

typedef struct s_game
{
	void			*win;
	void			*mlx;

	char			**map;
	t_localisation	loc;
	t_image			image;
	t_window		window;
	t_collect		collect;
}				t_game;

char	**get_line(char **map, char *new_line);

int		ft_printf(const char *str, ...);
int		hanlde_input(int keysym, t_game *game);
int		handle_event(void);
int		destroy_win(t_game *game);
int		limit_first_part(char **map);
int		limit_second_part(char **map);
int		verif_intern(char **map, t_game *game);
int		verif_map(char **map, t_game *game);

void	map_is_wrong(char *str, char **map);
void	free_map(char **map);
void	open_xpm(t_game *game, void **image, char *path);
void	destroy_picture(t_game *game);
void	write_error(char *str);

void	back_mlx(t_game *game, int pst_x, int pst_y);
void	wall_mlx(t_game *game, int pst_x, int pst_y);
void	exit_mlx(t_game *game, int pst_x, int pst_y);
void	perso_mlx(t_game *game, int pst_x, int pst_y);
void	item_mlx(t_game *game, int pst_x, int pst_y);

int		key_up(t_game *game);
int		key_down(t_game *game);
int		key_left(t_game *game);
int		key_right(t_game *game);

void	trash(t_game *game);
void	get_map(int fd, t_game *game);
void	print_map(t_game *game);
void	update_map(t_game *game);

#endif