/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:53:34 by myrmarti          #+#    #+#             */
/*   Updated: 2022/01/27 19:35:07 by myrmarti         ###   ########.fr       */
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
	perror(str);
	exit (2);
}
