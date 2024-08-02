/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:49:35 by arakotom          #+#    #+#             */
/*   Updated: 2024/08/02 16:39:29 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/includes/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "constants.h"
# include "types.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void		prog_error_exit(char *msg);
void		map_error_exit(char **map, int id_err);
void		map_file_error_exit(char *msg);
void		print_map(char **map);
char		**read_map_file(const char *filename);
void		check_map_file(const char *path);
void		set_map_data(t_map_data *map_data, char **map);
void		init_map_data(t_map_data *map_data);
void		init_pos_player(char **map, t_coord *player);
void		init_pos_exit(char **map, t_coord *exit);
void		find_way(char **map, t_map_data *map_data, int player_x,
				int player_y);
void		check_map_validation(const char *path);
void		*set_img_mlx(t_game *game, char *path);
void		put_img_mlx(t_game *game, void *img, t_coord c_map);
t_assets	init_assets_16px(t_game *game);
t_assets	init_assets_24px(t_game *game);
t_assets	init_assets_32px(t_game *game);
t_assets	init_assets_48px(t_game *game);
t_assets	init_assets_64px(t_game *game);
t_game		game_init(char **map);
void		draw_wall(t_game *game, t_wall_img wall, t_coord c_map);
void		draw_ground(t_game *game, void *ground, t_coord c_map);
void		draw_collect(t_game *game, void *collect, t_coord c_map);
void		draw_exit(t_game *game, t_exit_img exit, t_coord c_map);
void		draw_player(t_game *game, t_player_img player, t_direction dir,
				t_coord c_map);
void		draw_player_on_exit(t_game *game, t_player_img player,
				t_direction dir, t_coord c_map);
void		set_coord_x_y(t_coord *coord, int x, int y);
void		draw_game_map(t_game *game);
int			key_move_handler(int keycode, t_game *game);
void		reset_prev_img(t_game *game, t_coord c_old);
void		set_next_img(t_game *game, t_coord c_new, t_direction dir);
void		move_player(t_game *game, t_direction dir);
void		exit_game(t_game *game);
#endif
