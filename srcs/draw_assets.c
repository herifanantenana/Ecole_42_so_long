/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:35:09 by arakotom          #+#    #+#             */
/*   Updated: 2024/08/02 13:39:23 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_wall(t_game *game, t_wall_img wall, t_coord c_map)
{
	t_map_data	map_data;

	map_data = game->map.map_data;
	if (c_map.x == 0 || c_map.y == 0 || c_map.x == map_data.x - 1
		|| c_map.y == map_data.y - 1)
		put_img_mlx(game, wall.wall_e, c_map);
	else if (game->ratio <= RATIO_24 && (c_map.x == 1 || c_map.y == 1
			|| c_map.x == map_data.x - 2 || c_map.y == map_data.y - 2))
		put_img_mlx(game, wall.wall_e, c_map);
	else
		put_img_mlx(game, wall.wall_i, c_map);
}

void	draw_ground(t_game *game, void *ground, t_coord c_map)
{
	put_img_mlx(game, ground, c_map);
}

void	draw_exit(t_game *game, t_exit_img exit, t_coord c_map)
{
	if (game->map.map_data.item == 0)
		put_img_mlx(game, exit.open, c_map);
	else
		put_img_mlx(game, exit.close, c_map);
}

void	draw_player(t_game *game, t_player_img player, t_direction dir,
		t_coord c_map)
{
	if (dir == UP)
		put_img_mlx(game, player.up, c_map);
	else if (dir == DOWN)
		put_img_mlx(game, player.down, c_map);
	else if (dir == LEFT)
		put_img_mlx(game, player.left, c_map);
	else if (dir == RIGHT)
		put_img_mlx(game, player.right, c_map);
}
void	draw_player_on_exit(t_game *game, t_player_img player, t_direction dir,
		t_coord c_map)
{
	if (dir == UP)
		put_img_mlx(game, player.up_e, c_map);
	else if (dir == DOWN)
		put_img_mlx(game, player.down_e, c_map);
	else if (dir == LEFT)
		put_img_mlx(game, player.left_e, c_map);
	else if (dir == RIGHT)
		put_img_mlx(game, player.right_e, c_map);
}
