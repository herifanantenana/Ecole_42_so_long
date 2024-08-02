/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 23:08:44 by arakotom          #+#    #+#             */
/*   Updated: 2024/08/01 06:22:15 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_bool is_map_rectangular(char **map)
{
	int i;
	int j;
	int len;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j != len)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static t_bool is_map_content_valid(t_map_data map_content)
{
	if ((map_content.x * map_content.y) != (map_content.empty + map_content.wall + map_content.item + map_content.exit + map_content.player))
		return (FALSE);
	if (map_content.x < 3 || map_content.y < 3)
		return (FALSE);
	if (map_content.player != 1 || map_content.exit != 1)
		return (FALSE);
	return (TRUE);
}

static t_bool is_map_surrounded_by_walls(char **map, t_map_data map_content)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 || i == map_content.y - 1 || j == 0 || j == map_content.x - 1)
			{
				if (map[i][j] != MAP_W)
					return (FALSE);
			}
			j++;
		}
		i++;
	}
	return (TRUE);
}

static t_bool is_map_solvable(char **map, t_map_data *map_content)
{
	t_coord player;

	init_pos_player(map, &player);
	find_way(map, map_content, player.x, player.y);
	if (map_content->item != 0 && map_content->exit != 0)
		return (FALSE);
	return (TRUE);
}

void check_map_validation(const char *path)
{
	char **map;
	t_map_data map_content;

	map = read_map_file(path);
	init_map_data(&map_content);
	if (is_map_rectangular(map))
	{
		set_map_data(&map_content, map);
		if (is_map_content_valid(map_content))
			if (is_map_surrounded_by_walls(map, map_content))
				if (is_map_solvable(map, &map_content))
					ft_printf("\033[1;32m🗺️ Map is valid\n\033[0m");
				else
					map_error_exit(map, ERR_MAP_NOT_SOLVABLE);
			else
				map_error_exit(map, ERR_MAP_WALLS);
		else
			map_error_exit(map, ERR_MAP_CONTENT);
	}
	else
		map_error_exit(map, ERR_MAP_RECT);
	ft_free_tab_str(map);
}
