/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:30:03 by bbeltran          #+#    #+#             */
/*   Updated: 2023/10/30 11:27:24 by jaimmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* Ojo, se asume que todas las lineas del mapa miden lo mismo!*/
void	init_map_data(t_cub *cub)
{
	cub->map_data.x_len = (int)ft_strlen(cub->map[0]);
	cub->map_data.y_len = get_2d_array_size(cub->map);
}

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
	unsigned int	e_color;
	unsigned int	w_color;

	y = 0;
	init_map_data(cub);
	cub->minimap.tyle_size = 32;
	cub->minimap.x_size = cub->map_data.x_len * cub->minimap.tyle_size;
	cub->minimap.y_size = cub->map_data.y_len * cub->minimap.tyle_size;
//	cub->minimap.x_size = W_WIDTH / 2;
//	cub->minimap.y_size = W_HEIGHT;
	e_color = 0x00777777;
	w_color = 0x00FFFFFF;
	int i = 1;
	while (y < cub->minimap.y_size)
	{
		int	j = 1;
		x = 0;
		while (x < cub->minimap.x_size)
		{
			if ((x == cub->player.x && y == cub->player.y) ||
				(x == cub->player.x + 1 && y == cub->player.y) ||
				(x == cub->player.x && y == cub->player.y + 1) ||
				(x == cub->player.x + 1 && y == cub->player.y + 1))
				render_player(cub->mlx, cub->player);
			else if (y < cub->minimap.tyle_size * i && x < cub->minimap.tyle_size * j
						&& y > cub->minimap.tyle_size * (i - 1) && x > cub->minimap.tyle_size * (j - 1)
						&& cub->map[i - 1][j - 1] == '1')
				mlx_pixel_put(cub->mlx.connect, cub->mlx.window, x, y, w_color);
			else
				mlx_pixel_put(cub->mlx.connect, cub->mlx.window, x, y, e_color);
			x++;
			if (x >= cub->minimap.tyle_size * j)
				j++;
		}
		y++;
		if (y >= cub->minimap.tyle_size * i)
			i++;
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
