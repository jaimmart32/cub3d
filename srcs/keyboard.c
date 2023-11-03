/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:09:50 by bbeltran          #+#    #+#             */
/*   Updated: 2023/11/03 16:45:27 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_player(int keycode, t_cub *cub)
{
	t_player	*player;
	double		new_x;
	double		new_y;

	player = &cub->player;
	if (keycode == W)
	{
		player->move = 1;
		new_x = player->x + (cos(player->rotation) * player->m_speed);
		new_y = player->y + (sin(player->rotation) * player->m_speed);
		if (!collision(new_x, new_y, cub->map))
		{
			player->x = new_x;
			player->y = new_y;
		}
		player->dest_x = player->x + (cos(player->rotation) * 50);
		player->dest_y = player->y + (sin(player->rotation) * 50);
//		paint_mini_map(cub);
		create_ray_vision(cub);
		paint_walls(cub);
	}
	if (keycode == S)
	{
		player->move = -1;
		new_x = player->x + player->move * (cos(player->rotation) * player->m_speed);
		new_y = player->y + player->move * (sin(player->rotation) * player->m_speed);
		if (!collision(new_x, new_y, cub->map))
		{
			player->x = new_x;
			player->y = new_y;
		}
		player->dest_x = player->x + (cos(player->rotation) * 50);
		player->dest_y = player->y + (sin(player->rotation) * 50);
//		paint_mini_map(cub);
		create_ray_vision(cub);
		paint_walls(cub);
	}
	if (keycode == A)
	{
		player->turn = -1;
		player->rotation += player->turn * player->t_speed;
		player->rotation = normalize_angle(player->rotation);
		player->dest_x = player->x + (cos(player->rotation) * 50);
		player->dest_y = player->y + (sin(player->rotation) * 50);
//		paint_mini_map(cub);
		create_ray_vision(cub);
		paint_walls(cub);
	}
	if (keycode == D)
	{
		player->turn = 1;
		player->rotation += player->turn * player->t_speed;
		player->rotation = normalize_angle(player->rotation);
		player->dest_x = player->x + (cos(player->rotation) * 50);
		player->dest_y = player->y + (sin(player->rotation) * 50);
//		paint_mini_map(cub);
		create_ray_vision(cub);
		paint_walls(cub);
	}
	if (keycode == LEFT)
	{
		player->turn = -1;
		player->rotation += player->turn * player->t_speed;
	}
	if (keycode == RIGHT)
	{
		player->turn = 1;
		player->rotation += player->turn * player->t_speed;
	}
	printf("rot = %f\n", player->rotation);
}

/* Just a function for when the user presses the ESC key. */
void	close_game(t_cub *cub)
{
	mlx_destroy_window(cub->mlx.connect, cub->mlx.window);
	exit(0);
}

/* This function is one of the arguments passed to the mlx_hook(), in
 * exec_game(). Will receive a keycode and accordingly to that keycode
 * it will call a different function. */ 
int	key_press(int keycode, t_cub *cub)
{
	if (keycode == ESC)
		close_game(cub);
	if (keycode == W)
		move_player(W, cub);
	if (keycode == A)
		move_player(A, cub);
	if (keycode == S)
		move_player(S, cub);
	if (keycode == D)
		move_player(D, cub);
//	if (keycode == LEFT)
//	if (keycode == RIGHT)
	return (0);
}
