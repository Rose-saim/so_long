#include "so_long.h"

void open_xpm(t_game *game)
{
	int	width, height;
    
	game->background = mlx_xpm_file_to_image(game->mlx, "./img/Crate-_2_.xpm", &width, &height);
    if (game->background == NULL)
    {
		write_error("Error create image of background");
	} 
	game->character = mlx_xpm_file_to_image(game->mlx, "./img/perso_wall.xpm", &width, &height);
    if (game->character == NULL)
    {
		write_error("Error create image of character");
	} 
	game->wall = mlx_xpm_file_to_image(game->mlx, "./img/8.xpm", &width, &height);
    if (game->wall == NULL)
    {
		write_error("Error create image of wall");
	} 
	game->item = mlx_xpm_file_to_image(game->mlx, "./img/mushroom.xpm", &width, &height);
    if (game->item == NULL)
    {
		write_error("Error create image of item");
	} 
	game->exit = mlx_xpm_file_to_image(game->mlx, "./img/exit.xpm", &width, &height);
    if (game->exit == NULL)
    {
		write_error("Error create image of exit");
	} 
}

void    destroy_picture(t_game *game)
{
   	mlx_destroy_image(game->mlx,game->background);
	mlx_destroy_image(game->mlx,game->character);
	mlx_destroy_image(game->mlx,game->wall);
	mlx_destroy_image(game->mlx,game->item);
	mlx_destroy_image(game->mlx,game->exit);
}