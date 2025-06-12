/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:36:58 by seizquie          #+#    #+#             */
/*   Updated: 2025/06/12 15:47:26 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	
	if (argc != 2)
	{
		ft_printf("Usage: ./so_long <map2.ber>\n");
		return (1);
	}
	game.map.height = 0;
	game.map.map = NULL;
	game.fd = open(argv[1], O_RDONLY);
	if (game.fd == -1)
		ft_error("Error: Failed to open map file.\n");
	map_parce(&game, argv[1]);
	path_finder(&game);
	init_game(&game);
	render_map(&game);
	mlx_loop(game.mlx);
	free_map(&game);
	close(game.fd);
	return (0);
}

void	map_parce(t_game *game, char *filename)
{
	check_png_files();
	check_file(filename);
	read_map(game);
	store_lines(game, filename);
	is_rectangular(game);
	restrict_map_to_screen(game);
	check_walls(game);
	check_components(game);
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init(game->map.width * 64, game->map.height * 64, "so long",
			false);
	if (!game->mlx)
		ft_error("Error\n Failed to initialize MLX\n");
	load_images(game);
	find_player(game, &game->player_x, &game->player_y);
	game->moves = 0;
	find_exit(game);
	mlx_key_hook(game->mlx, move_player, game);
}
