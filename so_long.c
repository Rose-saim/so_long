#include "so_long.h"

int main(int ac, char **av)
{
	t_game     game;
    char	str[4] = ".ber";
	int fd;
	int	i = 0;
	int	j = 0;

	if (ac != 2)
		write_error("It is not good numbers of arguments");
	while (av[1][i + 4])
		++i;
	while (av[1][i + j])
	{
		if (av[1][i + j] != str[j])
			write_error("File descriptor have not good extension \".ber\"");
		++j;
	}
    fd = open(av[1], O_RDONLY);
	if (fd == -1)
		write_error("Error file descriptor");
    get_map(fd, &game);
    close (fd);
	game.mlx = mlx_init();
	if (!game.mlx)
		write_error("Error since init mlx");
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "First map by image");
	if (!game.win)
		write_error("Error since create window");

	open_xpm(&game);
	print_map(&game, 1, 1);

	mlx_loop_hook(game.mlx, &handle_event, &game);
	mlx_hook(game.win, ClientMessage, LeaveWindowMask, &destroy_win, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, &hanlde_input, &game);

	mlx_loop(game.mlx);

	destroy_picture(&game);
	free_map(game.map);
	mlx_destroy_display(game.mlx);
	free(game.mlx);
	return 0;
}