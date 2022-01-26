#include "so_long.h"

void	map_is_wrong(char *str, char **map)
{
	free_map(map);
	ft_printf("Error\n");
	write_error(str);
}

int verif_map(char **map, t_game *game)
{
	int	i = 0;
	int ret = 0;
	int	length_map = 0;

	if (!map)
		return (1);
	length_map = ft_strlen(map[i]);
	while (ft_strlen(map[i]))
	{
		if (length_map != ft_strlen(map[i]))
			map_is_wrong("Map is not good size", map);
		++i;
	}
	ret = limit_first_part(map);
	if (ret == 1)
		return (0);
	ret = limit_second_part(map);
	if (ret == 1)
		return (0);
	ret = verif_intern(map, game);
	return (1);
}

int limit_first_part(char **map)
{
	int x = 0;
	int y = 0;

	while (map[y + 1] != NULL)
	{
		if (map[y][x] != '1')
			map_is_wrong("Map is wrong", map);
		++y;
	}
	while (map[y][x])
	{
		if (map[y][x] != '1')
			map_is_wrong("Map is wrong", map);
		++x;
	}
	return (0);
}

int limit_second_part(char **map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map[y][x])
	{
		if (map[y][x] != '1')
			map_is_wrong("Map is wrong", map);
		++x;
	}
	x -= 1;
	while (map[y + 1] != NULL)
	{
		if (map[y][x] != '1')
			map_is_wrong("Map is wrong", map);
		++y;
	}
	return (0);
}

int verif_intern(char **map, t_game *game)
{
	int x = 1;
	int y = 1;
	int exit_game = 0;
	int perso = 1;
	int item = 0;
	int wall = 0;

	while (map[y])
	{
		x = 1;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				exit_game += 1;
			if (map[y][x] == 'P')
			{
				game->loc.character_y = y;
				game->loc.character_x = x;
				perso -= 1;
			}
			if (map[y][x] == 'C')
				++item;
			if (map[y][x] == '0')
				++wall;
			if (!(map[y][x] == '1' || map[y][x] == '0' || map[y][x] == 'P' || map[y][x] == 'E' || map[y][x] == 'C'))
				map_is_wrong("Argument map is wrong", map);
			++x;
		}
		++y;
	}
	if (exit_game == 0 || perso != 0 || item <= 0 || wall <= 0)
		map_is_wrong("Map is wrong", map);
	return (0);
}