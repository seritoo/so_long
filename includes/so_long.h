/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:49:32 by seizquie          #+#    #+#             */
/*   Updated: 2025/06/11 14:00:24 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define MAX_MAP_AREA 2000
# define SO_LONG_H
# define SCREEN_WIDTH_LIMIT 3840
# define SCREEN_HEIGHT_LIMIT 2160
# define TILE_SIZE 64

# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "../libs/MLX42/include/MLX42/MLX42_Int.h"
# include "ft_printf/include/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "include/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	int			width;
	int			height;
	char		**map;
}				t_map;

typedef struct s_game
{
	t_map		map;
	mlx_t		*mlx;
	mlx_image_t	*img_wall;
	mlx_image_t	*img_floor;
	mlx_image_t	*img_player;
	mlx_image_t	*img_collect;
	mlx_image_t	*img_exit;
	int			player_x;
	int			player_y;
	int			moves;
	int			collectibles;
	int			exits_total;
	int			exit_x;
	int			exit_y;
	int			fd;
}				t_game;

typedef struct s_counts
{
	int			p;
	int			e;
	int			c;
}				t_counts;

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

void			ft_error(char *str);
void			read_map(t_game *game);
void			store_lines(t_game *game, char *filename);
void			free_map(t_game *game);
void			check_file(char *filename);
void			is_rectangular(t_game *game);
void			check_walls(t_game *game);
void			check_components(t_game *game);
void			count_elements(t_game *game, t_counts *counts);
int				count_collectibles(t_game *game);
int				check_counts(t_counts counts);
void			map_parce(t_game *game, char *filename);
void			find_player(t_game *game, int *x, int *y);
void			path_finder(t_game *game);
void			init_game(t_game *game);
void			free_map_copy(char **map, int height);
void			render_map(t_game *game);
void			move_player(mlx_key_data_t keydata, void *param);
void			find_exit(t_game *game);
int				count_exits(t_game *game);
void			cleanup_game(t_game *game);
void			update_player_position(t_game *game, t_pos old_pos,
					t_pos new_pos);
void			check_victory(t_game *game);
void			restrict_map_to_screen(t_game *game);
void			load_images(t_game *game);
void			check_png_files(void);

#endif