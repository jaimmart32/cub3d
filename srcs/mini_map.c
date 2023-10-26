/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:30:03 by bbeltran          #+#    #+#             */
/*   Updated: 2023/10/26 18:01:28 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	render_background(t_cub *cub)
{
	float			x;
	float			y;
	unsigned int	color;
	unsigned int	backc;

	cub->mlx.background = mlx_new_image(cub->mlx.connect, 1024, 512);
	color = 0x00FFFF00;
	backc = 0x00FF5555;
	x = 0;
	while (x < 1024)
	{
		y = 0;
		while (y < 512)
		{
			if ((x == cub->player.x && y == cub->player.y) ||
				(x == cub->player.x + 1 && y == cub->player.y) ||
				(x == cub->player.x && y == cub->player.y + 1) ||
				(x == cub->player.x + 1 && y == cub->player.y + 1))
				render_player(cub->mlx, cub->player);
			else
				mlx_pixel_put(cub->mlx.connect, cub->mlx.window, x, y, backc);
			y++;
		}
		x++;
	}
}
/*void	render_background(t_cub *cub)
{
	int			x;
	int			y;
	unsigned int	color;
	unsigned int	backc;

	color = 0x00FFFF00;
	backc = 0x00FF5555;
	x = 0;
	while (x < 1024)
	{
		y = 0;
		while (y < 512)
		{
			if ((x == cub->player.x && y == cub->player.y) ||
				(x == cub->player.x + 1 && y == cub->player.y) ||
				(x == cub->player.x && y == cub->player.y + 1) ||
				(x == cub->player.x + 1 && y == cub->player.y + 1))
				render_player(cub->mlx, cub->player);
			else
				mlx_pixel_put(cub->mlx.connect, cub->mlx.window, x, y, backc);
			y++;
		}
		x++;
	}
}*/
