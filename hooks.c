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
	static int	i = 1;
	static int	j = 1;
	static int	move = 0;

	if (keysym == XK_Escape)
		mlx_destroy_window(game->mlx, game->win);
	if (keysym == 119)
	{
		if (game->map[j - 1][i] == '1')
			return 0;
		j -= 1;
		if (game->map[j][i] == 'C')
		{
			game->map[j][i] = '0';
			game->collect.number_item_to_collect -= 1;
		}
		++move;
		printf("Total numbers of movements|%d|\n", move);
		update_map(game, i, j);
	}
	if (keysym == 115)
	{
		if (game->map[j + 1][i] == '1')
			return 0;
		j += 1;
		if (game->map[j][i] == 'C')
		{
			game->map[j][i] = '0';
			game->collect.number_item_to_collect -= 1;
		}
		++move;
		printf("Total numbers of movements|%d|\n", move);
		update_map(game, i, j);
	}
	if (keysym == 97)
	{
		if (game->map[j][i - 1] == '1')
			return 0;
		i -= 1;
		if (game->map[j][i] == 'C')
		{
			game->map[j][i] = '0';
			game->collect.number_item_to_collect -= 1;
		}
		++move;
		printf("Total numbers of movements|%d|\n", move);
		update_map(game, i, j);
	}
	if (keysym == 100)
	{
		if (game->map[j][i + 1] == '1')
			return 0;
		i += 1;
		if (game->map[j][i] == 'C')
		{
			game->map[j][i] = '0';
			game->collect.number_item_to_collect -= 1;
		}
		++move;
		printf("Total numbers of movements|%d|\n", move);
		update_map(game, i, j);
	}
	if (game->map[j][i] == 'E' && game->collect.number_item_to_collect == 0)
		mlx_destroy_window(game->mlx, game->win);
	return 0;
}

