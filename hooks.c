/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:13:47 by myrmarti          #+#    #+#             */
/*   Updated: 2022/01/28 16:28:17 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_win(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	game->win = NULL;
	return (0);
}

int	handle_event(void)
{
	return (0);
}

void	escape(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	game->win = NULL;
}

int	hanlde_input(int keysym, t_game *game)
{
	int	ret;

	ret = 2;
	if (keysym == XK_Escape)
		escape(game);
	else if (keysym == 119)
		ret = key_up(game);
	else if (keysym == 115)
		ret = key_down(game);
	else if (keysym == 97)
		ret = key_left(game);
	else if (keysym == 100)
		ret = key_right(game);
	if (ret != 0)
		return (0);
	ft_printf("Total numbers of movements|%d|\n", game->loc.move);
	if (game->map[game->loc.character_y][game->loc.character_x] == 'E'
		&& game->collect.number_item_to_collect == 0)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	return (0);
}
