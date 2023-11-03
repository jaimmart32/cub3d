/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:30:03 by bbeltran          #+#    #+#             */
/*   Updated: 2023/11/03 16:59:09 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* Ojo, se asume que todas las lineas del mapa miden lo mismo!, lo suyo seria,
coger el length de la linea mas larga por si el mapa es irregular en el eje x*/
void	init_map_data(t_cub *cub)
{
	cub->map_data.x_len = (int)get_longest_line(cub->map);
	cub->map_data.y_len = get_2d_array_size(cub->map);
}

void	paint_mini_map(t_cub *cub)
{
	double			x;
	double			y;
	unsigned int	e_color;
	unsigned int	w_color;
	int				i;
	int				j;

	y = 0;
	init_map_data(cub);
	cub->minimap.x_size = cub->map_data.x_len * TILE_SIZE;
	cub->minimap.y_size = cub->map_data.y_len * TILE_SIZE;
//	cub->mlx.img_background = create_image(cub->mlx);
	e_color = 0x00777777;
	w_color = 0x00FFFFFF;
	i = 1;
	while (y < cub->minimap.y_size && cub->map[i - 1])
	{
		j = 1;
		x = 0;
		while (x < cub->minimap.x_size && cub->map[i - 1][j - 1])
		{
			if ((x == floor(cub->player.x) && y == floor(cub->player.y)) ||
				(x == floor(cub->player.x) + 1 && y == floor(cub->player.y)) ||
				(x == floor(cub->player.x) && y == floor(cub->player.y) + 1) ||
				(x == floor(cub->player.x) + 1 && y == floor(cub->player.y) + 1))
				render_player(cub->mlx, cub->player);
			else if (y < TILE_SIZE * i && x < TILE_SIZE * j
						&& y > TILE_SIZE * (i - 1) && x > TILE_SIZE * (j - 1)
						&& cub->map[i - 1][j - 1] == '1')
//				ft_mlx_pixel_put(&cub->mlx.img_background, x, y, w_color);
				mlx_pixel_put(cub->mlx.connect, cub->mlx.window, x, y, w_color);
			else
//				ft_mlx_pixel_put(&cub->mlx.img_background, x, y, e_color);
				mlx_pixel_put(cub->mlx.connect, cub->mlx.window, x, y, e_color);
			x++;
			if (x >= TILE_SIZE * j)
				j++;
		}
		y++;
		if (y >= TILE_SIZE * i)
			i++;
//		render_ray(cub->mlx, cub->player, cub->ray);
		render_direction(cub->mlx, cub->player);
	}
}

void	paint_background(t_cub *cub)
{
	int				x;
	int				y;
	unsigned int	b_color;

	y = 0;
	b_color = 0x00000000;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_pixel_put(cub->mlx.connect, cub->mlx.window, x, y, b_color);
			x++;
		}
		y++;
	}
}

void	render_walls(t_cub *cub, t_player player, t_ray ray, int x)
{
	double	distanceProjection;
	double	wall_height;
	int		tile_height;
	int		y0;
	int		y1;
	int		paint_y;
	unsigned int	w_color;

	w_color = 0x00FF0000;
	distanceProjection = (WIDTH / 2) / tan(player.rotation);
	tile_height = 500;
	wall_height = (tile_height/ray.distance) * distanceProjection;
	if (wall_height < 64)
		wall_height = 64;
	y0 = floor(HEIGHT / 2) - floor(wall_height / 2);
	y1 = y0 + wall_height;
	paint_y = y0;
	while (paint_y < y1)
	{
		mlx_pixel_put(cub->mlx.connect, cub->mlx.window, x, paint_y, w_color);
		paint_y++;
	}
}

void	paint_walls(t_cub *cub)
{
	int	i;

	i = 0;
	paint_background(cub);
	while (i < WIDTH)
	{
		render_walls(cub, cub->player, cub->ray[i], i);
		i++;
	}
}
