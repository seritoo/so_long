/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:55:01 by seizquie          #+#    #+#             */
/*   Updated: 2025/06/11 13:56:16 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		ft_error("Error: Invalid file name.\n");
	if (filename[len - 1] != 'r' || filename[len - 2] != 'e'
		|| filename[len - 3] != 'b' || filename[len - 4] != '.')
		ft_error("Error: Invalid file extension.\n");
}

void	is_rectangular(t_game *game)
{
	int	i;
	int	len;
	int	curr_len;

	i = 0;
	len = ft_strlen(game->map.map[0]);
	if (game->map.map[0][len - 1] == '\n')
		len = len - 1;
	while (i < game->map.height)
	{
		curr_len = ft_strlen(game->map.map[i]);
		if (game->map.map[i][curr_len - 1] == '\n')
			curr_len = curr_len - 1;
		if (curr_len != len)
		{
			free_map(game);
			ft_error("Error: Map is not rectangular.\n");
		}
		i++;
	}
	game->map.width = len;
}

void	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.width)
	{
		if (game->map.map[0][i] != '1' || game->map.map[game->map.height
			- 1][i] != '1')
		{
			free_map(game);
			ft_error("Error: top or bottom wall missing\n");
		}
		i++;
	}
	i = 1;
	while (i < game->map.height - 1)
	{
		if (game->map.map[i][0] != '1' || game->map.map[i][game->map.width
			- 1] != '1')
		{
			free_map(game);
			ft_error("Error: side wall missing.\n");
		}
		i++;
	}
}

void	check_components(t_game *game)
{
	t_counts	counts;

	counts.p = 0;
	counts.c = 0;
	counts.e = 0;
	count_elements(game, &counts);
	if (check_counts(counts) == 1)
	{
		free_map(game);
		ft_error("Error: Invalid P, E, or C count\n");
	}
	game->collectibles = counts.c;
	game->exits_total = counts.e;
}

void	count_elements(t_game *game, t_counts *counts)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == 'P')
				counts->p++;
			else if (game->map.map[i][j] == 'E')
				counts->e++;
			else if (game->map.map[i][j] == 'C')
				counts->c++;
			else if (game->map.map[i][j] != '0' && game->map.map[i][j] != '1')
			{
				free_map(game);
				ft_error("Error: Invalid character\n");
			}
			j++;
		}
		i++;
	}
}
