/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:09:50 by bbeltran          #+#    #+#             */
/*   Updated: 2023/10/27 12:42:08 by jaimmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_player(int keycode, t_cub *cub)
{
	if (keycode == W)
	{
		cub->player.y -= 5;
		render_minimap(cub);
	}
	if (keycode == S)
	{
		cub->player.y += 5;
		render_minimap(cub);
	}
	if (keycode == A)
	{
		cub->player.x -= 5;
		render_minimap(cub);
	}
	if (keycode == D)
	{
		cub->player.x += 5;
		render_minimap(cub);
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
