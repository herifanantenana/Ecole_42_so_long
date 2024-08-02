/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:36:43 by arakotom          #+#    #+#             */
/*   Updated: 2024/08/02 13:39:46 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_collect(t_game *game, void *collect, t_coord c_map)
{
	put_img_mlx(game, collect, c_map);
}

static void	draw_asset(t_game *game, char map_char, t_coord c_map)
{
	if (map_char == MAP_W)
		draw_wall(game, game->assets.wall, c_map);
	else if (map_char == MAP_0)
		draw_ground(game, game->assets.ground, c_map);
	else if (map_char == MAP_C)
		draw_collect(game, game->assets.collect, c_map);
	else if (map_char == MAP_E)
		draw_exit(game, game->assets.exit, c_map);
	else if (map_char == MAP_P)
		draw_player(game, game->assets.player, DOWN, c_map);
}

void	draw_game_map(t_game *game)
{
	t_coord	c_map;

	c_map.y = 0;
	while (game->map.map[c_map.y])
	{
		c_map.x = 0;
		while (game->map.map[c_map.y][c_map.x])
		{
			draw_asset(game, game->map.map[c_map.y][c_map.x], c_map);
			c_map.x++;
		}
		c_map.y++;
	}
}
