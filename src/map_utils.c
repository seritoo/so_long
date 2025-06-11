/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:54:56 by seizquie          #+#    #+#             */
/*   Updated: 2025/06/11 13:56:14 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		free(game->map.map[i]);
		i++;
	}
	free(game->map.map);
}

void	free_map_copy(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(map[i++]);
	free(map);
}

int	check_counts(t_counts counts)
{
	if (counts.p != 1 || counts.e != 1 || counts.c < 1)
		return (1);
	else
		return (0);
}

void	cleanup_game(t_game *game)
{
	free_map(game);
	mlx_terminate(game->mlx);
	exit(0);
}

void	find_exit(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == 'E')
			{
				game->exit_x = j;
				game->exit_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
