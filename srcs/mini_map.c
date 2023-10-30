/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:30:03 by bbeltran          #+#    #+#             */
/*   Updated: 2023/10/30 11:44:36 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* Ojo, se asume que todas las lineas del mapa miden lo mismo!*/
void	init_map_data(t_cub *cub)
{
	cub->map_data.x_len = (int)ft_strlen(cub->map[0]);
	cub->map_data.y_len = get_2d_array_size(cub->map);
}

void	paint_mini_map(t_cub *cub)
{
	float			x;
	float			y;
	unsigned int	e_color;
	unsigned int	w_color;
	int				i;
	int				j;

	y = 0;
	init_map_data(cub);
	cub->minimap.tyle_size = 16;
	cub->minimap.x_size = cub->map_data.x_len * cub->minimap.tyle_size;
	cub->minimap.y_size = cub->map_data.y_len * cub->minimap.tyle_size;
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
				ft_mlx_pixel_put(&cub->mlx.img_background, x, y, w_color);
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
