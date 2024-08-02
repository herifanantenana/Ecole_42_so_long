/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:40:34 by arakotom          #+#    #+#             */
/*   Updated: 2024/08/02 14:02:44 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_move_handler(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		exit_game(game);
	else if (keycode == XK_Z || keycode == XK_z || keycode == XK_Up)
		ft_printf("Up pressed");
	else if (keycode == XK_S || keycode == XK_s || keycode == XK_Down)
		ft_printf("Down pressed");
	else if (keycode == XK_Q || keycode == XK_q || keycode == XK_Left)
		ft_printf("Left pressed");
	else if (keycode == XK_D || keycode == XK_d || keycode == XK_Right)
		ft_printf("Right pressed");
	return (0);
}
