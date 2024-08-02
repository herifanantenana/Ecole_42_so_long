/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 06:35:59 by arakotom          #+#    #+#             */
/*   Updated: 2024/08/02 13:11:25 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_assets	init_assets_16px(t_game *game)
{
	t_player_img	player_img;
	t_exit_img		exit_img;
	t_wall_img		wall_img;
	t_assets		assets;

	player_img.up = set_img_mlx(game, "assets/16px/up1.xpm");
	player_img.down = set_img_mlx(game, "assets/16px/down1.xpm");
	player_img.left = set_img_mlx(game, "assets/16px/left1.xpm");
	player_img.right = set_img_mlx(game, "assets/16px/right1.xpm");
	player_img.up_e = set_img_mlx(game, "assets/16px/up2.xpm");
	player_img.down_e = set_img_mlx(game, "assets/16px/down2.xpm");
	player_img.left_e = set_img_mlx(game, "assets/16px/left2.xpm");
	player_img.right_e = set_img_mlx(game, "assets/16px/right2.xpm");
	exit_img.close = set_img_mlx(game, "assets/16px/exit1.xpm");
	exit_img.open = set_img_mlx(game, "assets/16px/exit2.xpm");
	wall_img.wall_e = set_img_mlx(game, "assets/16px/wall1.xpm");
	wall_img.wall_i = set_img_mlx(game, "assets/16px/wall2.xpm");
	assets.collect = set_img_mlx(game, "assets/16px/coin.xpm");
	assets.ground = set_img_mlx(game, "assets/16px/ground.xpm");
	assets.wall = wall_img;
	assets.player = player_img;
	assets.exit = exit_img;
	return (assets);
}

t_assets	init_assets_24px(t_game *game)
{
	t_player_img	player_img;
	t_exit_img		exit_img;
	t_wall_img		wall_img;
	t_assets		assets;

	player_img.up = set_img_mlx(game, "assets/24px/up1.xpm");
	player_img.down = set_img_mlx(game, "assets/24px/down1.xpm");
	player_img.left = set_img_mlx(game, "assets/24px/left1.xpm");
	player_img.right = set_img_mlx(game, "assets/24px/right1.xpm");
	player_img.up_e = set_img_mlx(game, "assets/24px/up2.xpm");
	player_img.down_e = set_img_mlx(game, "assets/24px/down2.xpm");
	player_img.left_e = set_img_mlx(game, "assets/24px/left2.xpm");
	player_img.right_e = set_img_mlx(game, "assets/24px/right2.xpm");
	exit_img.close = set_img_mlx(game, "assets/24px/exit1.xpm");
	exit_img.open = set_img_mlx(game, "assets/24px/exit2.xpm");
	wall_img.wall_e = set_img_mlx(game, "assets/24px/wall1.xpm");
	wall_img.wall_i = set_img_mlx(game, "assets/24px/wall2.xpm");
	assets.collect = set_img_mlx(game, "assets/24px/coin.xpm");
	assets.ground = set_img_mlx(game, "assets/24px/ground.xpm");
	assets.wall = wall_img;
	assets.player = player_img;
	assets.exit = exit_img;
	return (assets);
}

t_assets	init_assets_32px(t_game *game)
{
	t_player_img	player_img;
	t_exit_img		exit_img;
	t_wall_img		wall_img;
	t_assets		assets;

	player_img.up = set_img_mlx(game, "assets/32px/up1.xpm");
	player_img.down = set_img_mlx(game, "assets/32px/down1.xpm");
	player_img.left = set_img_mlx(game, "assets/32px/left1.xpm");
	player_img.right = set_img_mlx(game, "assets/32px/right1.xpm");
	player_img.up_e = set_img_mlx(game, "assets/32px/up2.xpm");
	player_img.down_e = set_img_mlx(game, "assets/32px/down2.xpm");
	player_img.left_e = set_img_mlx(game, "assets/32px/left2.xpm");
	player_img.right_e = set_img_mlx(game, "assets/32px/right2.xpm");
	exit_img.close = set_img_mlx(game, "assets/32px/exit1.xpm");
	exit_img.open = set_img_mlx(game, "assets/32px/exit2.xpm");
	wall_img.wall_e = set_img_mlx(game, "assets/32px/wall1.xpm");
	wall_img.wall_i = set_img_mlx(game, "assets/32px/wall2.xpm");
	assets.collect = set_img_mlx(game, "assets/32px/coin.xpm");
	assets.ground = set_img_mlx(game, "assets/32px/ground.xpm");
	assets.wall = wall_img;
	assets.player = player_img;
	assets.exit = exit_img;
	return (assets);
}

t_assets	init_assets_48px(t_game *game)
{
	t_player_img	player_img;
	t_exit_img		exit_img;
	t_wall_img		wall_img;
	t_assets		assets;

	player_img.up = set_img_mlx(game, "assets/48px/up1.xpm");
	player_img.down = set_img_mlx(game, "assets/48px/down1.xpm");
	player_img.left = set_img_mlx(game, "assets/48px/left1.xpm");
	player_img.right = set_img_mlx(game, "assets/48px/right1.xpm");
	player_img.up_e = set_img_mlx(game, "assets/48px/up2.xpm");
	player_img.down_e = set_img_mlx(game, "assets/48px/down2.xpm");
	player_img.left_e = set_img_mlx(game, "assets/48px/left2.xpm");
	player_img.right_e = set_img_mlx(game, "assets/48px/right2.xpm");
	exit_img.close = set_img_mlx(game, "assets/48px/exit1.xpm");
	exit_img.open = set_img_mlx(game, "assets/48px/exit2.xpm");
	wall_img.wall_e = set_img_mlx(game, "assets/48px/wall1.xpm");
	wall_img.wall_i = set_img_mlx(game, "assets/48px/wall2.xpm");
	assets.collect = set_img_mlx(game, "assets/48px/coin.xpm");
	assets.ground = set_img_mlx(game, "assets/48px/ground.xpm");
	assets.wall = wall_img;
	assets.player = player_img;
	assets.exit = exit_img;
	return (assets);
}

t_assets	init_assets_64px(t_game *game)
{
	t_player_img	player_img;
	t_exit_img		exit_img;
	t_wall_img		wall_img;
	t_assets		assets;

	player_img.up = set_img_mlx(game, "assets/64px/up1.xpm");
	player_img.down = set_img_mlx(game, "assets/64px/down1.xpm");
	player_img.left = set_img_mlx(game, "assets/64px/left1.xpm");
	player_img.right = set_img_mlx(game, "assets/64px/right1.xpm");
	player_img.up_e = set_img_mlx(game, "assets/64px/up2.xpm");
	player_img.down_e = set_img_mlx(game, "assets/64px/down2.xpm");
	player_img.left_e = set_img_mlx(game, "assets/64px/left2.xpm");
	player_img.right_e = set_img_mlx(game, "assets/64px/right2.xpm");
	exit_img.close = set_img_mlx(game, "assets/64px/exit1.xpm");
	exit_img.open = set_img_mlx(game, "assets/64px/exit2.xpm");
	wall_img.wall_e = set_img_mlx(game, "assets/64px/wall1.xpm");
	wall_img.wall_i = set_img_mlx(game, "assets/64px/wall2.xpm");
	assets.collect = set_img_mlx(game, "assets/64px/coin.xpm");
	assets.ground = set_img_mlx(game, "assets/64px/ground.xpm");
	assets.wall = wall_img;
	assets.player = player_img;
	assets.exit = exit_img;
	return (assets);
}
