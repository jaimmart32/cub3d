/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:35:37 by bbeltran          #+#    #+#             */
/*   Updated: 2023/10/23 18:47:39 by jaimmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_rgb_code(int *rgb_code)
{
	if (rgb_code[0] < 0 || rgb_code[0] > 255)
		return (0);
	if (rgb_code[1] < 0 || rgb_code[1] > 255)
		return (0);
	if (rgb_code[2] < 0 || rgb_code[2] > 255)
		return (0);
	return (1);
}

int	only_numbers(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

int	manage_colors(t_cub *cub, char **array, char type)
{
	char	**rgb;
	int		rgb_code[3];
	int		i;

	rgb = ft_split(array[1], ',');
	if (!rgb)
		return (0);
	i = -1;
	while (rgb[++i])
	{
		if (!only_numbers(rgb[i]))
			return (0);
		// put error
	}
	rgb_code[0] = ft_atoi(rgb[0]);
	rgb_code[1] = ft_atoi(rgb[1]);
	rgb_code[2] = ft_atoi(rgb[2]);
	if (!check_rgb_code(rgb_code))
		return (0);
		// put error
	if (type == 'F')
	{
		cub->floor[0] = rgb_code[0];
		cub->floor[1] = rgb_code[1];
		cub->floor[2] = rgb_code[2];
	}
	else if (type == 'C')
	{
		cub->ceiling[0] = rgb_code[0];
		cub->ceiling[1] = rgb_code[1];
		cub->ceiling[2] = rgb_code[2];
	}
	return (1);
}

int	clean_line(t_cub *cub, char *line)
{
	char	**array;

	if (!line)
		return (0);
	array = ft_split(line, ' ');
	if (!ft_strcmp(array[0], "F"))
		return (manage_colors(cub, array, 'F'));
	if (!ft_strcmp(array[0], "C"))
		return (manage_colors(cub, array, 'C'));
//	if (!ft_strcmp(array[0], "NO") || !ft_strcmp(array[0], "SO")
//		|| !ft_strcmp(array[0], "WE") || !ft_strcmp(array[0], "EA"))
//		cub->textures = manage_textures(array);
	return (1);
}

t_cub	*fetch_header_data(int file_fd)
{
	char	*line;
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	if (!cub)
		return (printf(ERRMEM, "fetch_header_data"), NULL);
	line = get_next_line(file_fd);
	while (line)
	{
		while (!ft_strcmp(line, "\n"))
		{
			free(line);
			line = get_next_line(file_fd);
		}
		if (!clean_line(cub, line))
			return (0);
		// put error
		free(line);
		line = get_next_line(file_fd);
	}
	return (cub);
}

int	check_extension(char *filename)
{
	int		i;
	int		j;
	char	*ext;

	ext = ".cub";
	i = ft_strlen(filename);
	j = ft_strlen(ext);
	while (j >= 0)
	{
		if (filename[i--] != ext[j--])
			return (0);
	}
	return (1);
}

int	parsing(char *filename)
{
	int		fd;
	t_cub	*cub;

	if (!check_extension(filename))
		return (printf(ERRFORMAT, filename), 1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (printf(ERROPEN, filename), 1);
	cub = fetch_header_data(fd);
	return (0);
}
