/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 23:08:44 by arakotom          #+#    #+#             */
/*   Updated: 2024/08/08 00:37:28 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_bool	is_map_rectangular(char **map, int *id_err)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(map[0]);
	*id_err = 1;
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

static t_bool	is_map_content_valid(t_map_data map_content, int *id_err)
{
	if (map_content.player != 1 || map_content.exit != 1)
	{
		*id_err = 2;
		return (FALSE);
	}
	*id_err = 3;
	if ((map_content.x * map_content.y) != (map_content.empty + map_content.wall
			+ map_content.item + map_content.exit + map_content.player))
		return (FALSE);
	if (map_content.x < 3 || map_content.y < 3)
		return (FALSE);
	return (TRUE);
}

static t_bool	is_map_surrounded_by_walls(char **map, t_map_data map_content,
		int *id_err)
{
	int	i;
	int	j;

	*id_err = 4;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 || i == map_content.y - 1 || j == 0 || j == map_content.x
				- 1)
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

static t_bool	is_map_solvable(char **map, t_map_data *map_content,
		int *id_err)
{
	t_coord	player;

	*id_err = 5;
	init_pos_player(map, &player);
	find_way(map, map_content, player.x, player.y);
	if (map_content->item != 0 || map_content->exit != 0)
		return (FALSE);
	return (TRUE);
}

void	check_map_validation(const char *path)
{
	char		**map;
	int			id_err;
	t_map_data	map_content;

	map = read_map_file(path);
	id_err = 0;
	init_map_data(&map_content);
	set_map_data(&map_content, map);
	if (is_map_rectangular(map, &id_err) && is_map_content_valid(map_content,
			&id_err) && is_map_surrounded_by_walls(map, map_content, &id_err)
		&& is_map_solvable(map, &map_content, &id_err))
		ft_free_tab_str(map);
	else
		map_error_exit(map, id_err);
}
