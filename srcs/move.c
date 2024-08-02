/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:36:29 by arakotom          #+#    #+#             */
/*   Updated: 2024/08/02 16:39:53 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_bool	move_up(t_game *game)
{
	t_coord	p_old;
	t_coord	p_new;

	p_old = game->map.player;
	set_coord_x_y(&p_new, p_old.x, p_old.y - 1);
	if (game->map.map[p_new.y][p_new.x] == MAP_W)
		return (FALSE);
	reset_prev_img(game, p_old);
	set_next_img(game, p_new, UP);
	return (TRUE);
}

static t_bool	move_right(t_game *game)
{
	t_coord	p_old;
	t_coord	p_new;

	p_old = game->map.player;
	set_coord_x_y(&p_new, p_old.x + 1, p_old.y);
	if (game->map.map[p_new.y][p_new.x] == MAP_W)
		return (FALSE);
	if (game->map.map[p_new.y][p_new.x] == MAP_W)
		return (FALSE);
	reset_prev_img(game, p_old);
	set_next_img(game, p_new, RIGHT);
	return (TRUE);
}

static t_bool	move_down(t_game *game)
{
	t_coord	p_old;
	t_coord	p_new;

	p_old = game->map.player;
	set_coord_x_y(&p_new, p_old.x, p_old.y + 1);
	if (game->map.map[p_new.y][p_new.x] == MAP_W)
		return (FALSE);
	if (game->map.map[p_new.y][p_new.x] == MAP_W)
		return (FALSE);
	reset_prev_img(game, p_old);
	set_next_img(game, p_new, DOWN);
	return (TRUE);
}

static t_bool	move_left(t_game *game)
{
	t_coord	p_old;
	t_coord	p_new;

	p_old = game->map.player;
	set_coord_x_y(&p_new, p_old.x - 1, p_old.y);
	if (game->map.map[p_new.y][p_new.x] == MAP_W)
		return (FALSE);
	if (game->map.map[p_new.y][p_new.x] == MAP_W)
		return (FALSE);
	reset_prev_img(game, p_old);
	set_next_img(game, p_new, LEFT);
	return (TRUE);
}

void	move_player(t_game *game, t_direction dir)
{
	int	player_moved;

	player_moved = FALSE;
	if (dir == UP)
		player_moved = move_up(game);
	else if (dir == DOWN)
		player_moved = move_down(game);
	else if (dir == LEFT)
		player_moved = move_left(game);
	else if (dir == RIGHT)
		player_moved = move_right(game);
	if (player_moved)
	{
		game->move++;
		ft_printf("Move: %d\n", game->move);
	}
	if (game->map.map_data.item == 0)
		draw_exit(game, game->assets.exit, game->map.exit);
}
