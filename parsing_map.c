/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 21:00:59 by myrmarti          #+#    #+#             */
/*   Updated: 2022/01/28 15:54:51 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_map(char **map, t_game *game)
{
	int	i;
	int	ret;
	int	length_map;

	i = 0;
	ret = 0;
	length_map = 0;
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
	ret = limit_second_part(map);
	if (ret == 1)
		return (0);
	ret = verif_intern(map, game);
	return (1);
}

int	limit_first_part(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y + 1] != NULL)
	{
		if (map[y][x] != '1')
			map_is_wrong("Map is wrong", map);
		++y;
	}
	while (map[y][x + 1])
	{
		if (map[y][x] != '1')
			map_is_wrong("Map is wrong", map);
		++x;
	}
	return (0);
}

int	limit_second_part(char **map)
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

void	verif_arg_map(t_game *game, char loc, int x, int y)
{
	if (loc == 'E')
		game->collect.exit_game += 1;
	if (loc == 'P')
	{
		game->loc.character_y = y;
		game->loc.character_x = x;
		game->collect.perso += 1;
	}
	if (loc == 'C')
		++game->collect.item;
	if (loc == '0')
		++game->collect.wall;
	if (!(loc == '1' || loc == '0' || loc == 'P' || loc == 'E' || loc == 'C'))
		map_is_wrong("Argument map is wrong", game->map);
}

int	verif_intern(char **map, t_game *game)
{
	int	x;
	int	y;
	int	ret;

	x = 1;
	y = 1;
	ret = 0;
	while (map[y])
	{
		x = 1;
		while (map[y][x])
		{
			verif_arg_map(game, map[y][x], x, y);
			++x;
		}
		++y;
	}
	if (game->collect.exit_game == 0 || game->collect.perso != 1
		|| game->collect.item <= 0 || game->collect.wall <= 0)
		map_is_wrong("Map is wrong", map);
	return (0);
}
