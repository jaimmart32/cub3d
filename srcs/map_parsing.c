/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:35:37 by bbeltran          #+#    #+#             */
/*   Updated: 2023/10/19 18:02:27 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	start_program(char *filename)
{
	int		fd;
	t_cub	*cub;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (printf(ERROPEN, filename), 1);
	cub = malloc(sizeof(t_cub));
	if (!cub)
		return (printf(ERRMEM, "start_program"), 1);
	
}

t_map	**get_list_map(int file)
{
	t_map	**lst_map;
	char	*line;

	lst_map = malloc(sizeof(t_map *));
	if (!lst_map)
		return (printf(ERRMEM, "get_list_map"), NULL);
	*lst_map = NULL;
	line = get_next_line(file);
	while (line)
	{
		if (ft_strcmp(line, "\n"))
			map_add_back(lst_map, create_node(line));
		free(line);
		line = get_next_line(file);
	}

}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (printf(USAGE), 1);
	if (start_program(argv[1]))
		return (1);
	return (0);
}
