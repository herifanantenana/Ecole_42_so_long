/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:40:34 by arakotom          #+#    #+#             */
/*   Updated: 2024/08/03 01:16:35 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_event_handler(int keycode, void *params)
{
	(void)keycode;
	(void)params;
	return (0);
}

int	key_move_handler(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		exit_game(game);
	else if (keycode == XK_W || keycode == XK_w)
		move_player(game, UP);
	else if (keycode == XK_S || keycode == XK_s)
		move_player(game, DOWN);
	else if (keycode == XK_A || keycode == XK_a)
		move_player(game, LEFT);
	else if (keycode == XK_D || keycode == XK_d)
		move_player(game, RIGHT);
	return (0);
}
