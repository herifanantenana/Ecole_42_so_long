/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:49:14 by arakotom          #+#    #+#             */
/*   Updated: 2024/08/02 13:58:56 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char const *argv[])
{
	t_game	game;

	if (argc != 2)
		prog_error_exit(ERR_TOO_FEW_ARGS);
	check_map_file(argv[1]);
	check_map_validation(argv[1]);
	game = game_init(read_map_file(argv[1]));
	draw_game_map(&game);
	mlx_hook(game.win, KeyPress, KeyPressMask, &key_move_handler, &game);
	mlx_loop(game.mlx);
	return (0);
}
