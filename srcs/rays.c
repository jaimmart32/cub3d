/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:26:51 by bbeltran          #+#    #+#             */
/*   Updated: 2023/10/31 18:03:19 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_player_direction(t_player player, t_ray *ray)
{
	ray->down = 0;
	ray->left = 0;
	if (player.rotation > 0 && player.rotation < PI)
		ray->down = 1;
	if (player.rotation < 3 * (PI / 2) && player.rotation > PI / 2)
		ray->left = 1;
}

void	ray_y(t_ray *ray, t_player player, char **map)
{
	float	adjacent;
	float	next_x_intercept;
	float	next_y_intercept;
	int		horizontalCol;

	horizontalCol = 0;
	ray->y_intercept = floor(ray->y/TILE_SIZE) * TILE_SIZE;
	if (ray->down)
		ray->y_intercept += TILE_SIZE;
	adjacent = (ray->y_intercept - ray->y) / tan(player.rotation);
	ray->x_intercept = ray->x + adjacent;
	ray->y_step = TILE_SIZE;
	ray->x_step = ray->y_step / tan(player.rotation);
	if (!ray->down)
		ray->y_step *= -1;
	if ((ray->left && ray->x_step > 0) || (!ray->left && ray->x_step < 0))
		ray->x_step *= -1;
	next_x_intercept = ray->x_intercept;
	next_y_intercept = ray->y_intercept;
	if (!ray->down)
		next_y_intercept--;
	while (!horizontalCol)
	{
		if (collision(next_x_intercept, next_y_intercept, map))
		{
			horizontalCol++;
			printf("collisioned\n");
			ray->h_wallHit_x = next_x_intercept;
			ray->h_wallHit_y = next_y_intercept;
		}
		else
		{
			next_x_intercept += ray->x_step;
			next_y_intercept += ray->y_step;
		}
	}
}

t_ray	raycaster(t_player player, char **map)
{
//	Should we do an array of rays?
	t_ray	ray;

	ray.x = player.x;
	ray.y = player.y;
	check_player_direction(player, &ray);
	ray_y(&ray, player, map);
	return (ray);
}
