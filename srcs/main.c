/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:28:51 by jaimmart          #+#    #+#             */
/*   Updated: 2023/10/25 12:32:40 by jaimmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_duplicate_tex(t_tex **textures)
{
	t_tex	*curr;
	int		size;

	t_tex_size(*textures);
	curr = *textures;
	while(curr)
	{

		curr = curr->next;
	}
}

int	check_cub_struct(t_cub *cub)
{

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
	cub->map = get_map(filename);
//	Get cub->map value
//	Check errors inside of the cub structure
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (printf(USAGE), 1);
	if (parsing(argv[1]))
		return (1);
	return (0);
}
