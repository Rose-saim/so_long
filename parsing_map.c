#include "so_long.h"

int verif_map(char **map)
{
	int ret = 0;

	if (!map)
		return (1);
	ret = limit_first_part(map);
	if (ret == 1)
		return (0);
	ret = limit_second_part(map);
	if (ret == 1)
		return (0);
	ret = verif_intern(map);
	if (ret == 1)
		return (0);
	return (1);
}

int limit_first_part(char **map)
{
	int x = 0;
	int y = 0;

	while (map[y + 1] != NULL)
	{
		if (map[y][x] != '1')
			return (1);
		++y;
	}
	while (map[y][x])
	{
		if (map[y][x] != '1')
			return (1);
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
			return (1);
		++x;
	}
	x -= 1;
	while (map[y + 1] != NULL)
	{
		if (map[y][x] != '1')
			return (1);
		++y;
	}
	return (0);
}

int verif_intern(char **map)
{
	int x = 1;
	int y = 1;
	int exit_game = 1;
	int perso = 1;
	int item = 0;
	int wall = 0;

	while (map && map[y])
	{
		x = 1;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				exit_game -= 1;
			if (map[y][x] == 'P')
				perso -= 1;
			if (map[y][x] == 'C')
				++item;
			if (map[y][x] == '0')
				++wall;
			if (exit_game == -1 || perso == -1 || item <= 0 || wall <= 0)
				return (1);
			if (exit_game == 0)
				return (1);
			if (!(map[y][x] == '1' || map[y][x] == '0' || map[y][x] == 'P' || map[y][x] == 'E' || map[y][x] == 'C'))
				return (1);
			++x;
		}
		++y;
	}
	return (0);
}