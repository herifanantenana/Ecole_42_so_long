/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 06:36:43 by arakotom          #+#    #+#             */
/*   Updated: 2024/08/01 06:52:03 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void *set_img_mlx(t_game *game, char *path)
{
	return (mlx_xpm_file_to_image(game->mlx, path, &game->win_w, &game->win_h));
}