/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 23:11:05 by arakotom          #+#    #+#             */
/*   Updated: 2024/08/02 16:15:49 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

char	**read_map_file(const char *filename)
{
	int		fd;
	char	*line;
	char	*map_line;
	char	*map_line_tmp;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		map_file_error_exit(ERR_FILE_NOT_FOUND);
	map_line = get_next_line(fd);
	line = get_next_line(fd);
	while (line)
	{
		map_line_tmp = map_line;
		map_line = ft_strjoin(map_line_tmp, line);
		free(map_line_tmp);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map = ft_split(map_line, '\n');
	free(map_line);
	free(line);
	return (map);
}

void	check_map_file(const char *path)
{
	int	path_len;
	int	ext_len;

	path_len = ft_strlen(path);
	ext_len = ft_strlen(EXT_MAP_FILE_NAME);
	if (path_len <= ext_len)
		map_file_error_exit(ERR_INVALID_FILE_NAME);
	if (ft_strncmp(&path[path_len - ext_len], EXT_MAP_FILE_NAME, ext_len) != 0)
		map_file_error_exit(ERR_FILE_EXT);
}
