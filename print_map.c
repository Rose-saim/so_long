/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:19:23 by myrmarti          #+#    #+#             */
/*   Updated: 2022/01/26 16:23:54 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*copy(char *str)
{
	int		i;
	char	*new_string;

	i = 0;
	new_string = NULL;
	new_string = (char *)malloc(sizeof(char) *(ft_strlen(str) + 1));
	if (!new_string)
		return (NULL);
	while (str[i])
	{
		new_string[i] = str[i];
		++i;
	}
	new_string[i] = '\0';
	return (new_string);
}

char	**get_line(char **map, char *new_line)
{
	int			i;
	static int	row = 0;
	char		**new_map;

	i = 0;
	row += 1;
	new_map = malloc(sizeof(char *) * (row + 1));
	if (!new_map)
		return (NULL);
	while (map && map[i])
	{
		new_map[i] = copy(map[i]);
		++i;
	}
	new_map[i] = copy(new_line);
	new_map[i + 1] = NULL;
	free_map(map);
	return (new_map);
}

void	get_map(int fd, t_game *game)
{
	int		ret;
	char	*line;

	line = NULL;
	game->map = NULL;
	ret = 0;
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
	ret = verif_map(game->map, game);
}

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
	mlx_put_image_to_window(game->mlx, game->win, game->image.character, pst_x * 50, pst_y * 50);
}

void	item_mlx(t_game *game, int pst_x, int pst_y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->image.item,pst_x * 50, pst_y * 50);
	game->collect.number_item_to_collect += 1;
}


void	print_map(t_game *game, int pst_x, int pst_y)
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
				perso_mlx(game,  pst_x, pst_y);
			}
			if (game->map[j][i] == 'C')
				item_mlx(game, i, j);
			++i;
		}
		++j;
	}
}

void	update_map(t_game *game, int i, int j)
{
	mlx_clear_window(game->mlx, game->win);
	print_map(game, i, j);
}