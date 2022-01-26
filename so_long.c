/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:20:41 by myrmarti          #+#    #+#             */
/*   Updated: 2022/01/26 16:12:58 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verif_file(char *file)
{
	char	str[4];
	int		i;
	int		j;

	i = 0;
	j = 0;
	str[0] = '.';
	str[1] = 'b';
	str[2] = 'e';
	str[3] = 'r';
	while (file[i + 4])
		++i;
	while (file[i + j])
	{
		if (file[i + j] != str[j])
			write_error("File descriptor have not good extension \".ber\"");
		++j;
	}
}

void	close_window(t_game *game)
{
	destroy_picture(game);
	free_map(game->map);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	initilisation(t_game *game)
{
	game->loc.move = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
		write_error("Error since init mlx");
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "First map by image");
	if (!game->win)
		write_error("Error since create window");
}

int	main(int ac, char **av)
{
	t_game	game;
	int		fd;

	if (ac != 2)
		write_error("It is not good numbers of arguments");
	verif_file(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		write_error("Error file descriptor");
	get_map(fd, &game);
	close (fd);
	initilisation(&game);
	open_xpm(&game);
	print_map(&game, game.loc.character_x, game.loc.character_y);
	mlx_loop_hook(game.mlx, &handle_event, &game);
	mlx_hook(game.win, ClientMessage, LeaveWindowMask, &destroy_win, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, &hanlde_input, &game);
	mlx_loop(game.mlx);
	close_window(&game);
	return (0);
}
