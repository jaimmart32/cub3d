/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:09:50 by bbeltran          #+#    #+#             */
/*   Updated: 2023/10/30 16:51:53 by jaimmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_player(int keycode, t_cub *cub)
{
	if (keycode == W)
	{
		//move = 1
		//cub->player.x += (coseno[angulo] * velocidad de movimiento)
		//cub->player.y += (seno[angulo] * velocidad de movimiento)
		cub->player.y -= 5;
		paint_mini_map(cub);
//		render_minimap(cub);
	}
	if (keycode == S)
	{
		//move = -1
		cub->player.y += 5;
		paint_mini_map(cub);
//		render_minimap(cub);
	}
	if (keycode == A)
	{
		cub->player.x -= 5;
		paint_mini_map(cub);
//		render_minimap(cub);
	}
	if (keycode == D)
	{
		cub->player.x += 5;
		paint_mini_map(cub);
//		render_minimap(cub);
	}
	//flecha izq -> turn = -1 angulo = turn * turn_speed
	//flecha der -> turn = 1 angulo = turn * turn_speed
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
