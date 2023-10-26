/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:09:50 by bbeltran          #+#    #+#             */
/*   Updated: 2023/10/26 16:50:08 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_player(int keycode, t_cub *cub)
{
	if (keycode == W)
	{
		cub->player.y--;
		render_background(cub);
	}
	if (keycode == S)
	{
		cub->player.y++;
		render_background(cub);
	}
	if (keycode == A)
	{
		cub->player.x--;
		render_background(cub);
	}
	if (keycode == D)
	{
		cub->player.x++;
		render_background(cub);
	}
}

void	close_game(t_cub *cub)
{
	mlx_destroy_window(cub->mlx.connect, cub->mlx.window);
	exit(0);
}

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
	return (0);
}
