/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:09:50 by bbeltran          #+#    #+#             */
/*   Updated: 2023/10/31 10:51:05 by jaimmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_player(int keycode, t_cub *cub)
{
	if (keycode == W)
	{
		cub->player.move = 1;
		cub->player.x += (cos(cub->player.rotation) * cub->player.m_speed);
		cub->player.y += (sin(cub->player.rotation) * cub->player.m_speed);
		//cub->player.y -= 5;
		paint_mini_map(cub);
		printf("player.x = %f player.y = %f\n", cub->player.x, cub->player.y);
//		render_minimap(cub);
	}
	if (keycode == S)
	{
		cub->player.move = -1;
		cub->player.x += cub->player.move * (cos(cub->player.rotation) * cub->player.m_speed);
		cub->player.y += cub->player.move * (sin(cub->player.rotation) * cub->player.m_speed);
		//cub->player.y += 5;
		paint_mini_map(cub);
		printf("player.x = %f player.y = %f\n", cub->player.x, cub->player.y);
//		render_minimap(cub);
	}
	if (keycode == A)
	{
		cub->player.turn = -1;
		cub->player.rotation += cub->player.turn * cub->player.t_speed;
		printf("rot = %f\n", cub->player.rotation);
		//cub->player.x -= 5;
		paint_mini_map(cub);
//		render_minimap(cub);
	}
	if (keycode == D)
	{
		cub->player.turn = 1;
		cub->player.rotation += cub->player.turn * cub->player.t_speed;
		printf("rot = %f\n", cub->player.rotation);
	//	cub->player.x += 5;
		paint_mini_map(cub);
//		render_minimap(cub);
	}
	if (keycode == LEFT)
	{
		cub->player.turn = -1;
		cub->player.rotation += cub->player.turn * cub->player.t_speed;
		printf("rot = %f\n", cub->player.rotation);
	}
	if (keycode == RIGHT)
	{
		cub->player.turn = 1;
		cub->player.rotation += cub->player.turn * cub->player.t_speed;
		printf("rot = %f\n", cub->player.rotation);
	}
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
