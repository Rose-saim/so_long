#include "so_long.h"

void open_xpm(t_game *game)
{
	int	width, height;

	game->image.background = mlx_xpm_file_to_image(game->mlx, "./img/Crate-_2_.xpm", &width, &height);
    if (game->image.background == NULL)
    {
		write_error("Error create image of background");
	} 
	game->image.character = mlx_xpm_file_to_image(game->mlx, "./img/perso_wall.xpm", &width, &height);
    if (game->image.character == NULL)
    {
		write_error("Error create image of character");
	} 
	game->image.wall = mlx_xpm_file_to_image(game->mlx, "./img/8.xpm", &width, &height);
    if (game->image.wall == NULL)
    {
		write_error("Error create image of wall");
	} 
	game->image.item = mlx_xpm_file_to_image(game->mlx, "./img/mushroom.xpm", &width, &height);
    if (game->image.item == NULL)
    {
		write_error("Error create image of item");
	} 
	game->image.exit = mlx_xpm_file_to_image(game->mlx, "./img/exit.xpm", &width, &height);
    if (game->image.exit == NULL)
    {
		write_error("Error create image of exit");
	} 
}

void    destroy_picture(t_game *game)
{
   	mlx_destroy_image(game->mlx,game->image.background);
	mlx_destroy_image(game->mlx,game->image.character);
	mlx_destroy_image(game->mlx,game->image.wall);
	mlx_destroy_image(game->mlx,game->image.item);
	mlx_destroy_image(game->mlx,game->image.exit);
}