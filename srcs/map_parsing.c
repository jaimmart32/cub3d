/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:35:37 by bbeltran          #+#    #+#             */
/*   Updated: 2023/10/24 16:44:44 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	valid_char(char c)
{
	if (c == '1')
		return (1);
	if (c == '0')
		return (1);
	if (c == ' ')
		return (1);
	if (c == 'N')
		return (1);
	if (c == 'S')
		return (1);
	if (c == 'W')
		return (1);
	if (c == 'E')
		return (1);
	return (0);
}

int	map_valid_chars(char *line)
{
	int	i;

	i = -1;
	while (line[++i] && line[i] != '\n')
	{
		if (!valid_char(line[i]))
			return (0);
	}
	return (1);
}

int	get_array_size(int file_fd)
{
	int		size;
	char	*line;

	size = 0;
	line = get_next_line(file_fd);
	while (line && !ft_strcmp(line, "\n"))
	{
		free(line);
		line = get_next_line(file_fd);
	}
	while (line)
	{
		if (!map_valid_chars(line))
			return (free(line), 0);
		size++;
		free(line);
		line = get_next_line(file_fd);
	}
	close(file_fd);
	return (size);
}

char	**get_map(char *filename, int file_fd)
{
	int		arr_size;
	char	*line;
	char	**map;
	int		i;

	arr_size = get_array_size(file_fd);
	if (!arr_size)
		return (printf("Error: Invalid map\n"), NULL);
	file_fd = open(filename, O_RDONLY);
	if (file_fd == -1)
		return (printf(ERROPEN, filename), 1);
	map = ft_calloc(arr_size + 1, sizeof(char *));
	if (!map)
		return (printf(ERRMEM, "get_map"), NULL);
	line = get_next_line(file_fd);
	i = 0;
	while (line)
	{
		if (map_valid_chars(line))
			map[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(file_fd);
	}
	return (map);
}
