/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:53:34 by myrmarti          #+#    #+#             */
/*   Updated: 2022/01/28 16:15:41 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	x;

	x = 0;
	if (!map)
		return ;
	while (map[x])
	{
		free(map[x]);
		++x;
	}
	free(map);
}

void	write_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit (1);
}

void	map_is_wrong(char *str, char **map)
{
	free_map(map);
	ft_printf("Error\n");
	write_error(str);
}
