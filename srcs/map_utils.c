/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 23:11:44 by arakotom          #+#    #+#             */
/*   Updated: 2024/08/01 06:17:01 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void init_map_data(t_map_data *map_data)
{
	map_data->x = 0;
	map_data->y = 0;
	map_data->empty = 0;
	map_data->wall = 0;
	map_data->item = 0;
	map_data->exit = 0;
	map_data->player = 0;
}

void set_map_data(t_map_data *map_data, char **map)
{
	int i;
	int j;

	i = 0;
	map_data->x = ft_strlen(map[0]);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == MAP_0)
				map_data->empty++;
			else if (map[i][j] == MAP_W)
				map_data->wall++;
			else if (map[i][j] == MAP_C)
				map_data->item++;
			else if (map[i][j] == MAP_E)
				map_data->exit++;
			else if (map[i][j] == MAP_P)
				map_data->player++;
			j++;
		}
		i++;
	}
	map_data->y = i;
}

void init_pos_player(char **map, t_coord *player)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == MAP_P)
			{
				player->x = j;
				player->y = i;
				return;
			}
			j++;
		}
		i++;
	}
}

void init_pos_exit(char **map, t_coord *exit)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == MAP_E)
			{
				exit->x = j;
				exit->y = i;
				return;
			}
			j++;
		}
		i++;
	}
}

void find_way(char **map, t_map_data *map_data, int player_x, int player_y)
{
	if (map[player_y][player_x] == MAP_W)
		return;
	if (map[player_y][player_x] == MAP_F)
		return;
	if (map[player_y][player_x] == MAP_C)
		map_data->item--;
	if (map[player_y][player_x] == MAP_E)
		map_data->exit--;
	map[player_y][player_x] = MAP_F;
	find_way(map, map_data, player_x + 1, player_y);
	find_way(map, map_data, player_x - 1, player_y);
	find_way(map, map_data, player_x, player_y + 1);
	find_way(map, map_data, player_x, player_y - 1);
}
