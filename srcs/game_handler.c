/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:49:19 by arakotom          #+#    #+#             */
/*   Updated: 2024/08/02 14:01:13 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	free_assets(t_game *game)
{
	mlx_destroy_image(game->mlx, game->assets.ground);
	mlx_destroy_image(game->mlx, game->assets.collect);
	mlx_destroy_image(game->mlx, game->assets.wall.wall_i);
	mlx_destroy_image(game->mlx, game->assets.wall.wall_e);
	mlx_destroy_image(game->mlx, game->assets.exit.open);
	mlx_destroy_image(game->mlx, game->assets.exit.close);
	mlx_destroy_image(game->mlx, game->assets.player.up);
	mlx_destroy_image(game->mlx, game->assets.player.down);
	mlx_destroy_image(game->mlx, game->assets.player.left);
	mlx_destroy_image(game->mlx, game->assets.player.right);
	mlx_destroy_image(game->mlx, game->assets.player.up_e);
	mlx_destroy_image(game->mlx, game->assets.player.down_e);
	mlx_destroy_image(game->mlx, game->assets.player.left_e);
	mlx_destroy_image(game->mlx, game->assets.player.right_e);
}

void	exit_game(t_game *game)
{
	free_assets(game);
	ft_free_tab_str(game->map.map);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}
