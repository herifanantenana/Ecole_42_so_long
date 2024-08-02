/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:37:58 by arakotom          #+#    #+#             */
/*   Updated: 2024/08/02 16:43:02 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	reset_prev_img(t_game *game, t_coord c_old)
{
	if (game->map.map[c_old.y][c_old.x] == MAP_E)
		draw_exit(game, game->assets.exit, c_old);
	else
	{
		game->map.map[c_old.y][c_old.x] = MAP_0;
		draw_ground(game, game->assets.ground, c_old);
	}
}

void	set_next_img(t_game *game, t_coord c_new, t_direction dir)
{
	if (game->map.map[c_new.y][c_new.x] == MAP_E)
	{
		if (game->map.map_data.item == 0)
		{
			ft_printf("Move: %d\n", game->move + 1);
			exit_game(game);
		}
		draw_player_on_exit(game, game->assets.player, dir, c_new);
	}
	else
	{
		if (game->map.map[c_new.y][c_new.x] == MAP_C)
			game->map.map_data.item--;
		game->map.map[c_new.y][c_new.x] = MAP_P;
		draw_player(game, game->assets.player, dir, c_new);
	}
	game->map.player = c_new;
}
