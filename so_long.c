#include "so_long.h"

#define WIDTH 900
#define HEIGHT 700


int main(int ac, char **av)
{
	t_game     game;
    char	str[4] = ".ber";
	int fd;
	int	i = 0;
	int	j = 0;

	if (ac != 2)
		return (0);
	while (av[1][i + 4])
		++i;
	while (av[1][i + j])
	{
		if (av[1][i + j] != str[j])
			return (0);
		++j;
	}
    fd = open("maps/map.ber", O_RDONLY);
    get_map(fd, &game);
    close (fd);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "First map by image");

	int	width, height;
	int	w, h;
	game.background = mlx_xpm_file_to_image(game.mlx, "./img/Crate-_2_.xpm", &width, &height);
	game.character = mlx_xpm_file_to_image(game.mlx, "./img/perso_wall.xpm", &w, &h);
	game.wall = mlx_xpm_file_to_image(game.mlx, "./img/8.xpm", &w, &h);
	game.item = mlx_xpm_file_to_image(game.mlx, "./img/mushroom.xpm", &w, &h);
	game.exit = mlx_xpm_file_to_image(game.mlx, "./img/exit.xpm", &w, &h);
	print_map(&game, 1, 1);

	mlx_loop_hook(game.mlx, &handle_event, &game);
	mlx_hook(game.win, ClientMessage, LeaveWindowMask, &destroy_win, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, &hanlde_input, &game);

	mlx_loop(game.mlx);

	mlx_destroy_display(game.mlx);
	free(game.mlx);
}