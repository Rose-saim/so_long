#include "so_long.h"

void    limit_map(char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map[i][j])
    {
        if (map[i][j] != '1')
            return (1);
        --i;
    }
    while (map[i][j])
    {
        if (map[i][j] != '1')
            return (1);
        ++j;
    }
    while (j >= 0)
    {
        if (map[i][j] != '1')
            return (1);
        --j;
    }
    while (i >= 0)
    {
        if (map[i][j] != '1')
            return (1);
        --i;
    }
}

void    in_map(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i][j])
    {
        if (map[i][j] != '1')
            return (1);
        ++i;
    }
    j = 0;
    while (map[i][j])
    {
        if (map[i][j] != '1')
            return (1);
        ++j;
    }
    while (j >= 0)
    {
        if (map[i][j] != '1')
            return (1);
        --j;
    }
    while (i >= 0])
    {
        if (map[i][j] != '1')
            return (1);
        --i;
    }
}