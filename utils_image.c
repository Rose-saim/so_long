/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:32:21 by myrmarti          #+#    #+#             */
/*   Updated: 2022/01/28 16:33:29 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_xpm(t_game *game, void **image, char *path)
{
	int	w;
	int	h;

	*image = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	if (image == NULL)
	{
		trash(game);
		write_error("Error create");
	}
}

void	update_map(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	print_map(game);
}

void	print_image(t_game *game, int j, int i)
{
	int	pst_x;
	int	pst_y;

	pst_x = game->loc.character_x;
	pst_y = game->loc.character_y;
	if (game->map[j][i] == '1')
		back_mlx(game, i, j);
	if (game->map[j][i] == '0' && (i != pst_x || j != pst_y))
		wall_mlx(game, i, j);
	if (game->map[j][i] == 'E')
		exit_mlx(game, i, j);
	if (game->map[j][i] == 'P')
	{
		if (i != pst_x || j != pst_y)
			wall_mlx(game, i, j);
		perso_mlx(game, pst_x, pst_y);
	}
	if (game->map[j][i] == 'C')
		item_mlx(game, i, j);
}

void	print_map(t_game *game)
{
	int	ret;
	int	i;
	int	j;

	i = 0;
	j = 0;
	ret = 0;
	game->collect.number_item_to_collect = 0;
	while (game->map[j])
	{
		i = 0;
		game->window.x = ft_strlen(game->map[j]);
		while (i < game->window.x)
		{
			print_image(game, j, i);
			++i;
		}
		++j;
	}
}
