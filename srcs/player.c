/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:28:14 by bbeltran          #+#    #+#             */
/*   Updated: 2023/10/31 18:06:19 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*llamar en move_player()*/
float	normalize_angle(float angle)
{
	angle = fmod(angle, 2 * PI);
	if (angle < 0)
		angle += (2 * PI);
	return (angle);
}

int	collision(float x, float y, char **map)
{
	int	y_tile;
	int	x_tile;

	x_tile = floor(x / TILE_SIZE);
	y_tile = floor(y / TILE_SIZE);
	if (!map[y_tile][x_tile] || map[y_tile][x_tile] == '1')
		return (1);
	return (0);
}

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

void	init_player_stats(t_player *player)
{
	player->rotation = 1.5;
	player->dest_x = 0,
	player->dest_y = 0,
	player->move = 0;
	player->turn = 0;
	player->m_speed = 3;
	player->t_speed = 3 * (PI / 180);
}

void	render_ray(t_mlx mlx, t_player player, t_ray ray)
{
	unsigned int color = 0x0000FF00;
	float		x;
	float		y;
	int			i;

	i = 1;
	x = 0;
	y = 0;
	while (x < ray.h_wallHit_x && y < ray.h_wallHit_y)
	{
		x = player.x + (cos(player.rotation) * i);
		y = player.y + (sin(player.rotation) * i);
		mlx_pixel_put(mlx.connect, mlx.window, floor(x), floor(y), color);
		i++;
	}
}

void	render_direction(t_mlx mlx, t_player player)
{
	int		i;
	float	x;	
	float	y;	
	unsigned int color = 0x00FF0000;

	i = 0;
	while (++i < 30)
	{
		x = player.x + (cos(player.rotation) * i);
		y = player.y + (sin(player.rotation) * i);
//		printf("floor(x) = %f, floor(y) = %f\n", floor(x), floor(y));
		mlx_pixel_put(mlx.connect, mlx.window, floor(x), floor(y), color);
	}
}

void	render_player(t_mlx mlx, t_player player)
{
	unsigned int color = 0x00FF0000;

	mlx_pixel_put(mlx.connect, mlx.window, player.x, player.y, color);
	mlx_pixel_put(mlx.connect, mlx.window, player.x, player.y + 1, color);
	mlx_pixel_put(mlx.connect, mlx.window, player.x + 1, player.y, color);
	mlx_pixel_put(mlx.connect, mlx.window, player.x + 1, player.y + 1, color);
//	render_direction(mlx, player);
}
