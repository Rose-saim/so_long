/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_pictures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:55:16 by myrmarti          #+#    #+#             */
/*   Updated: 2022/01/28 16:32:56 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	back_mlx(t_game *game, int pst_x, int pst_y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->image.background,
		pst_x * 50, pst_y * 50);
}

void	wall_mlx(t_game *game, int pst_x, int pst_y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->image.wall,
		pst_x * 50, pst_y * 50);
}

void	exit_mlx(t_game *game, int pst_x, int pst_y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->image.exit,
		pst_x * 50, pst_y * 50);
}

void	perso_mlx(t_game *game, int pst_x, int pst_y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->image.character,
		pst_x * 50, pst_y * 50);
}

void	item_mlx(t_game *game, int pst_x, int pst_y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->image.item,
		pst_x * 50, pst_y * 50);
	game->collect.number_item_to_collect += 1;
}
