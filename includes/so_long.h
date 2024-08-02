/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:49:35 by arakotom          #+#    #+#             */
/*   Updated: 2024/08/02 12:21:10 by arakotom         ###   ########.fr       */
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
void		map_error_exit(char **map, char *msg);
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
t_assets	init_assets_16px(t_game *game);
t_assets	init_assets_24px(t_game *game);
t_assets	init_assets_32px(t_game *game);
t_assets	init_assets_48px(t_game *game);
t_assets	init_assets_64px(t_game *game);
t_game		game_init(char **map);

#endif
