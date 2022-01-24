#include "so_long.h"

char     **get_line(char **map, char *new_line)
{
	int i;
	int j;
	static int row = 0;
	char **new_map;

	i = 0;
	j = 0;
	row += 1;
	new_map = malloc(sizeof(char *) * (row + 1));
	if (!new_map)
		return (NULL);
	while (map && map[i])
	{
		j = 0;
		new_map[i] = malloc(sizeof(char) * (ft_strlen(map[i]) +1));
		if (!new_map[i])
			return (NULL);
		while (map[i][j])
		{
			new_map[i][j] = map[i][j];
			++j;
		}
		new_map[i][j] = '\0';
		++i;
	}
	j = 0;
	new_map[i] = malloc(sizeof(char) * (ft_strlen(new_line) + 1));
	if (!new_map[i])
			return (NULL);
	while (new_line[j])
	{
		new_map[i][j] = new_line[j];
		++j;
	}
	new_map[i][j] = '\0';
	new_map[i + 1] = NULL;
	j = 0;
	free_map(map);
	return (new_map);
}

void    get_map(int fd, t_game *game)
{
	int ret = 0;
	char    *line;

	line = NULL;
	game->map = NULL;

	get_next_line(fd, &line);
	if (line == NULL)
		write_error("Map is empty");
	game->map = get_line(game->map, line);
	free(line);
	while (line)
	{
		get_next_line(fd, &line);
		if (ft_strlen(line) == 0)
		{
			free(line);
			break ;
		}
		game->map = get_line(game->map, line);
		free(line);
	}
	ret = verif_map(game->map);
	if (ret == 1)
	{
		free_map(game->map);
		write_error("Error:Arguments in map");
	}
}


void	print_map(t_game *game, int pst_x, int pst_y)
{
	int	ret = 0;
	game->map_x = 0;
	game->map_y = 0;

	int	i = 0;
	int	j = 0;
	game->collect.number_item_to_collect = 0;
	while (game->map[j])
	{
		game->map_x = 0;
		i = 0;
		game->window.x = ft_strlen(game->map[j]);
		while (i < game->window.x)
		{
			if (game->map[j][i] == '1')
				ret = mlx_put_image_to_window(game->mlx, game->win, game->background, game->map_x * 50, game->map_y * 50);
			if (game->map[j][i] == '0' && (i != pst_x || j != pst_y))
				ret = mlx_put_image_to_window(game->mlx, game->win, game->wall, game->map_x * 50, game->map_y * 50);
			if (game->map[j][i] == 'E')
			{
				ret = mlx_put_image_to_window(game->mlx, game->win, game->wall, game->map_x * 50, game->map_y * 50);
				ret = mlx_put_image_to_window(game->mlx, game->win, game->exit, game->map_x * 50, game->map_y * 50);
			}
			if (game->map[j][i] == 'P')
			{
				ret = mlx_put_image_to_window(game->mlx, game->win, game->wall, game->map_x * 50, game->map_y * 50);
				ret = mlx_put_image_to_window(game->mlx, game->win, game->character, pst_x * 50, pst_y * 50);
			}
			if (game->map[j][i] == 'C')
			{
				ret = mlx_put_image_to_window(game->mlx, game->win, game->item, game->map_x * 50, game->map_y * 50);
				game->collect.number_item_to_collect += 1;
			}
			++i;
			game->map_x++;
		}
		++j;
			game->map_y++;
	}
}

void	update_map(t_game *game, int i, int j)
{
	mlx_clear_window(game->mlx, game->win);
	print_map(game, i, j);
}