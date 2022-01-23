#include "so_long.h"

char     **get_line(char **map, char *new_line)
{
    int i;
    int j;
    static int row = 0;
    char **new_map;

    i = 0;
    j = 0;
    row += 1;
    new_map = malloc(sizeof(char *) * (row + 1));
    if (!new_map)
        return (NULL);
    while (map && map[i])
    {
        j = 0;
        new_map[i] = malloc(sizeof(char) * ft_strlen(map[i] + 1));
        if (!new_map[i])
            return (NULL);
        while (map[i][j] && map[i][j] != '\n')
        {
            new_map[i][j] = map[i][j];
            ++j;
        }
        ++i;
    }
    j = 0;
    new_map[i] = malloc(sizeof(char) * (ft_strlen(new_line) + 1));
    if (!new_map[i])
            return (NULL);
    while (new_line[j])
    {
        new_map[i][j] = new_line[j];
        ++j;
    }
    new_map[i][j++] = '\0';
    new_map[i + 1] = NULL;
    j = 0;
    while (map && map[j])
    {
        free(map[j]);
        ++j;
    }
    return (new_map);
}

void    get_map(int fd, t_game *game)
{
    char    *line;

    line = NULL;
    game->map = NULL;

    get_next_line(fd, &line);
    game->map = get_line(game->map, line);
    while (*line)
    {
        get_next_line(fd, &line);
        if (ft_strlen(line) == 0)
            break ;
        game->map = get_line(game->map, line);
        free(line);
    }
    int ret = 0;
    ret = verif_map(game->map);
    if (ret == 1)
        return ;
}

int verif_map(char **map)
{
    int ret = 0;

    if (!map)
        return (1);
    ret = verif_limit(map);
    if (ret == 0)
        return (1);
    ret = verif_intern(map);
    if (ret == 0)
        return (1);
    return (0);
}

int verif_limit(char **map)
{
    int x = 0;
    int y = 0;

    while (map[y + 1] != NULL)
    {
        if (map[y][x] != '1')
            return (0);
        ++y;
    }
    while (map[y][x])
    {
        if (map[y][x] != '1')
            return (0);
        ++x;
    }
    y = 0;
    x = 0;
    while (map[y][x])
    {
        if (map[y][x] != '1')
            return (0);
        ++x;
    }
    x -= 1;
    while (map[y + 1] != NULL)
    {
        if (map[y][x] != '1')
            return (0);
        ++y;
    }
    return (1);
}

int verif_intern(char **map)
{
    int x = 1;
    int y = 1;
    int exit = 1;
    int perso = 1;
    int item = 0;
    int wall = 0;

    while (map[y + 1])
    {
        x = 1;
        while (map[y][x + 1])
        {
            if (map[y][x] == 'E')
                exit -= 1;
            if (map[y][x] == 'P')
                perso -= 1;
            if (map[y][x] == 'C')
                ++item;
            if (map[y][x] == '0')
                ++wall;
            if (exit == -1 || perso == -1 || item <= 0 || wall <= 0)
                return (0);
            if (exit == 0)
                return (0);
            if (!(map[y][x] == '1' || map[y][x] == '0' || map[y][x] == 'P' || map[y][x] == 'E' || map[y][x] == 'C'))
                return (0);
            ++x;
        }
        ++y;
    }
    return (1);
}

void	print_map(t_game *game, int pst_x, int pst_y)
{
	game->map_x = 0;
	game->map_y = 0;

	int	i = 0;
	int	j = 0;
	game->collect.number_item_to_collect = 0;
	while (game->map[j])
	{
		game->map_x = 0;
		i = 0;
		game->window.x = ft_strlen(game->map[j]);
		while (i < game->window.x)
		{
			if (game->map[j][i] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->background, game->map_x * 50, game->map_y * 50);
            if (game->map[j][i] == '0' && (i != pst_x || j != pst_y))
				mlx_put_image_to_window(game->mlx, game->win, game->wall, game->map_x * 50, game->map_y * 50);
            if (game->map[j][i] == 'E')
            {
				mlx_put_image_to_window(game->mlx, game->win, game->wall, game->map_x * 50, game->map_y * 50);
				mlx_put_image_to_window(game->mlx, game->win, game->exit, game->map_x * 50, game->map_y * 50);
            }
			if (game->map[j][i] == 'P')
            {
				mlx_put_image_to_window(game->mlx, game->win, game->wall, game->map_x * 50, game->map_y * 50);
				mlx_put_image_to_window(game->mlx, game->win, game->character, pst_x * 50, pst_y * 50);
            }
			if (game->map[j][i] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->item, game->map_x * 50, game->map_y * 50);
				game->collect.number_item_to_collect += 1;
			}
			++i;
			game->map_x++;
		}
		++j;
			game->map_y++;
	}
}

void	update_map(t_game *game, int i, int j)
{
	mlx_clear_window(game->mlx, game->win);
	print_map(game, i, j);
}