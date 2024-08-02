/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 06:00:06 by arakotom          #+#    #+#             */
/*   Updated: 2024/08/02 12:19:26 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	init_game_map(t_game *game, char **map)
{
	t_map		map_game;
	t_map_data	map_data;
	t_coord		player;
	t_coord		exit;

	map_game.map = map;
	init_pos_player(map, &player);
	init_pos_exit(map, &exit);
	init_map_data(&map_data);
	set_map_data(&map_data, map);
	map_game.map_data = map_data;
	map_game.player = player;
	map_game.exit = exit;
	game->map = map_game;
}
static void	init_game_ratio(t_game *game, t_map_data map_data)
{
	int	ratio_x;
	int	ratio_y;
	int	ratio_screen;
	int	screen_width;
	int	screen_height;

	mlx_get_screen_size(game->mlx, &screen_width, &screen_height);
	ratio_x = (screen_width - 150) / map_data.x;
	ratio_y = (screen_height - 150) / map_data.y;
	if (ratio_x < ratio_y)
		ratio_screen = ratio_x;
	else
		ratio_screen = ratio_y;
	if (ratio_screen > RATIO_64)
		game->ratio = RATIO_64;
	else if (ratio_screen > RATIO_48)
		game->ratio = RATIO_48;
	else if (ratio_screen > RATIO_32)
		game->ratio = RATIO_32;
	else if (ratio_screen > RATIO_24)
		game->ratio = RATIO_24;
	else
		game->ratio = RATIO_16;
}

static void	init_game_window(t_game *game, t_map_data map_data)
{
	game->win_w = game->ratio * map_data.x;
	game->win_h = game->ratio * map_data.y;
	game->win = mlx_new_window(game->mlx, game->win_w, game->win_h, "so_long");
}

static void	init_game_assets(t_game *game, int ratio)
{
	if (ratio == RATIO_64)
		game->assets = init_assets_64px(game);
	else if (ratio == RATIO_48)
		game->assets = init_assets_48px(game);
	else if (ratio == RATIO_32)
		game->assets = init_assets_32px(game);
	else if (ratio == RATIO_24)
		game->assets = init_assets_24px(game);
	else
		game->assets = init_assets_16px(game);
}

t_game	game_init(char **map)
{
	t_game	game;

	game.mlx = mlx_init();
	init_game_map(&game, map);
	init_game_ratio(&game, game.map.map_data);
	init_game_window(&game, game.map.map_data);
	init_game_assets(&game, game.ratio);
	return (game);
}
