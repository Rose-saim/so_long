#include "so_long.h"

void    free_map(char **map)
{
    int	x = 0;
	while (map && map[x])
	{
		free(map[x]);
		++x;
	}
	free(map);
}

void    write_error(char *str)
{
    perror(str);
    exit (2);
}