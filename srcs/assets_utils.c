/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 06:36:43 by arakotom          #+#    #+#             */
/*   Updated: 2024/08/02 12:51:21 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*set_img_mlx(t_game *game, char *path)
{
	return (mlx_xpm_file_to_image(game->mlx, path, &game->win_w, &game->win_h));
}

void	put_img_mlx(t_game *game, void *img, t_coord c_map)
{
	t_coord	c_img;

	c_img.x = c_map.x * game->ratio;
	c_img.y = c_map.y * game->ratio;
	mlx_put_image_to_window(game->mlx, game->win, img, c_img.x, c_img.y);
}
