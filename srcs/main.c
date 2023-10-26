/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:28:51 by jaimmart          #+#    #+#             */
/*   Updated: 2023/10/26 17:03:22 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_player	get_player_position(void)
{
	t_player	player;

	player.x = 512;
	player.y = 256;
	return (player);
}

int	exec_game(t_cub *cub)
{
	cub->mlx.connect = mlx_init();
	cub->mlx.window = mlx_new_window(cub->mlx.connect, 1024, 512, "cub3d");
	cub->player = get_player_position();
	mlx_hook(cub->mlx.window, 17, 0, (void *)exit, 0);
	mlx_hook(cub->mlx.window, 2, 1L << 0, key_press, cub);
	render_background(cub);
	mlx_loop(cub->mlx.connect);
	return (0);
}

void	free_cub(t_cub *cub)
{
	free_2d_array(cub->map);
	t_tex_free(cub->textures);
	free(cub);
}

t_cub	*parsing(char *filename)
{
	int		fd;
	t_cub	*cub;

	if (!check_extension(filename))
		return (printf(ERRFORMAT, filename), NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (printf(ERROPEN, filename), NULL);
	cub = fetch_header_data(fd);
	if (!cub)
		return (NULL);
	cub->map = get_map(filename);
	if (!cub->map)
		return (printf(ERRMAP), NULL);
	if (!check_cub_struct(cub))
		return (NULL);
	return (cub);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	if (argc != 2)
		return (printf(USAGE), 1);
	cub = parsing(argv[1]);
	if (!cub)
		return (1);
	if (exec_game(cub))
		return (1);
	free_cub(cub);
	return (0);
}
