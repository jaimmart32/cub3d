/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:28:14 by bbeltran          #+#    #+#             */
/*   Updated: 2023/10/27 12:43:12 by jaimmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	render_player(t_mlx mlx, t_player player)
{
	unsigned int color = 0x00FF0000;

	mlx_pixel_put(mlx.connect, mlx.window, player.x, player.y, color);
	mlx_pixel_put(mlx.connect, mlx.window, player.x, player.y + 1, color);
	mlx_pixel_put(mlx.connect, mlx.window, player.x + 1, player.y, color);
	mlx_pixel_put(mlx.connect, mlx.window, player.x + 1, player.y + 1, color);
}
