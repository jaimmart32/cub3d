/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:28:14 by bbeltran          #+#    #+#             */
/*   Updated: 2023/10/30 15:36:39 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_player	get_player_position(char **map)
{
	t_player	player;
	int			i;
	int			j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'W' || map[i][j] == 'N' || map[i][j] == 'E'
					|| map[i][j] == 'S')
			{
				player.x = (j * TILE_SIZE) + (TILE_SIZE / 2);
				player.y = (i * TILE_SIZE) + (TILE_SIZE / 2);
			}
		}
	}
	return (player);
}

void	render_player(t_mlx mlx, t_player player)
{
	unsigned int color = 0x00FF0000;

	mlx_pixel_put(mlx.connect, mlx.window, player.x, player.y, color);
	mlx_pixel_put(mlx.connect, mlx.window, player.x, player.y + 1, color);
	mlx_pixel_put(mlx.connect, mlx.window, player.x + 1, player.y, color);
	mlx_pixel_put(mlx.connect, mlx.window, player.x + 1, player.y + 1, color);
}
