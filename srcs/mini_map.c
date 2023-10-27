/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:30:03 by bbeltran          #+#    #+#             */
/*   Updated: 2023/10/27 12:40:46 by jaimmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	render_background(t_cub *cub)
{
	float			x;
	float			y;
	unsigned int	color;
	unsigned int	backc;

	cub->mlx.background = mlx_new_image(cub->mlx.connect, W_WIDTH, W_HEIGHT);
	color = 0x00FFFF00;
	backc = 0x00555555;
	x = 0;
	while (x < W_WIDTH)
	{
		y = 0;
		while (y < W_HEIGHT)
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

void	render_minimap(t_cub *cub)
{
	int	x;
	int y;
	unsigned int	color;

	x = 0;
	cub->minimap.tyle_size = 32;
	cub->minimap.x_size = W_WIDTH / 2;
	cub->minimap.y_size = W_HEIGHT;
	color = 0x00FFFFFF;
	while (x < cub->minimap.x_size)
	{
		y = 0;
		while (y < cub->minimap.y_size)
		{
			if ((x == cub->player.x && y == cub->player.y) ||
				(x == cub->player.x + 1 && y == cub->player.y) ||
				(x == cub->player.x && y == cub->player.y + 1) ||
				(x == cub->player.x + 1 && y == cub->player.y + 1))
				render_player(cub->mlx, cub->player);
			else
				mlx_pixel_put(cub->mlx.connect, cub->mlx.window, x, y, color);
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
