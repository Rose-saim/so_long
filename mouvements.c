/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:46:37 by myrmarti          #+#    #+#             */
/*   Updated: 2022/01/28 16:31:06 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_up(t_game *game)
{
	if (game->map[game->loc.character_y - 1][game->loc.character_x] == '1')
		return (1);
	game->loc.character_y -= 1;
	if (game->map[game->loc.character_y][game->loc.character_x] == 'C')
	{
		game->map[game->loc.character_y][game->loc.character_x] = '0';
		game->collect.number_item_to_collect -= 1;
	}
	game->loc.move += 1;
	update_map(game);
	return (0);
}

int	key_down(t_game *game)
{
	if (game->map[game->loc.character_y + 1][game->loc.character_x] == '1')
		return (1);
	game->loc.character_y += 1;
	if (game->map[game->loc.character_y][game->loc.character_x] == 'C')
	{
		game->map[game->loc.character_y][game->loc.character_x] = '0';
		game->collect.number_item_to_collect -= 1;
	}
	game->loc.move += 1;
	update_map(game);
	return (0);
}

int	key_left(t_game *game)
{
	if (game->map[game->loc.character_y][game->loc.character_x - 1] == '1')
		return (1);
	game->loc.character_x -= 1;
	if (game->map[game->loc.character_y][game->loc.character_x] == 'C')
	{
		game->map[game->loc.character_y][game->loc.character_x] = '0';
		game->collect.number_item_to_collect -= 1;
	}
	game->loc.move += 1;
	update_map(game);
	return (0);
}

int	key_right(t_game *game)
{
	if (game->map[game->loc.character_y][game->loc.character_x + 1] == '1')
		return (1);
	game->loc.character_x += 1;
	if (game->map[game->loc.character_y][game->loc.character_x] == 'C')
	{
		game->map[game->loc.character_y][game->loc.character_x] = '0';
		game->collect.number_item_to_collect -= 1;
	}
	game->loc.move += 1;
	update_map(game);
	return (0);
}
