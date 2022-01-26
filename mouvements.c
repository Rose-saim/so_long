/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:46:37 by myrmarti          #+#    #+#             */
/*   Updated: 2022/01/26 16:19:24 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_up(t_game *game)
{
	
	game->loc.character_y -= 1;
	if (game->map[game->loc.character_y][game->loc.character_x] == 'C')
	{
		game->map[game->loc.character_y][game->loc.character_x] = '0';
		game->collect.number_item_to_collect -= 1;
	}
	game->loc.move += 1;
	update_map(game, game->loc.character_x, game->loc.character_y);
}

void	key_down(t_game *game)
{
	game->loc.character_y += 1;
	if (game->map[game->loc.character_y][game->loc.character_x] == 'C')
	{
		game->map[game->loc.character_y][game->loc.character_x] = '0';
		game->collect.number_item_to_collect -= 1;
	}
	game->loc.move += 1;
	update_map(game, game->loc.character_x, game->loc.character_y);
}

void	key_left(t_game *game)
{
	game->loc.character_x -= 1;
	if (game->map[game->loc.character_y][game->loc.character_x] == 'C')
	{
		game->map[game->loc.character_y][game->loc.character_x] = '0';
		game->collect.number_item_to_collect -= 1;
	}
	game->loc.move += 1;
	update_map(game, game->loc.character_x, game->loc.character_y);
}

void	key_right(t_game *game)
{
	game->loc.character_x += 1;
	if (game->map[game->loc.character_y][game->loc.character_x] == 'C')
	{
		game->map[game->loc.character_y][game->loc.character_x] = '0';
		game->collect.number_item_to_collect -= 1;
	}
	game->loc.move += 1;
	update_map(game, game->loc.character_x, game->loc.character_y);
}
