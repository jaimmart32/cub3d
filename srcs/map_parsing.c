/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:35:37 by bbeltran          #+#    #+#             */
/*   Updated: 2023/10/23 16:00:55 by jaimmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_extension(char *filename)
{
	//check that file ends in .cub
}

int	parsing(char *filename)
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

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (printf(USAGE), 1);
	if (parsing(argv[1]))
		return (1);
	return (0);
}
