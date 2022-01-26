#include "so_long.h"

int	destroy_win(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	return (0);
}

int	handle_event()
{
	return (0);
}

int		hanlde_input(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(game->mlx, game->win);
	else if (keysym == 119)
	{
		if (game->map[game->loc.character_y - 1][game->loc.character_x] == '1')
			return(0) ;
		key_up(game);
	}
	else if (keysym == 115)
	{
		if (game->map[game->loc.character_y + 1][game->loc.character_x] == '1')
			return(0) ;
		key_down(game);
	}
	else if (keysym == 97)
	{
		if (game->map[game->loc.character_y][game->loc.character_x - 1] == '1')
			return(0) ;
		key_left(game);
	}
	else if (keysym == 100)
	{
		if (game->map[game->loc.character_y][game->loc.character_x + 1] == '1')
			return(0) ;
		key_right(game);
	}
	ft_printf("Total numbers of movements|%d|\n", game->loc.move);
	if (game->map[game->loc.character_y][game->loc.character_x] == 'E' && game->collect.number_item_to_collect == 0)
		mlx_destroy_window(game->mlx, game->win);
	return 0;
}
