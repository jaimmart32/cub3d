/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 12:41:24 by bbeltran          #+#    #+#             */
/*   Updated: 2023/10/28 13:48:48 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_img	create_image(t_mlx mlx)
{
	t_img	img;

	img.img = mlx_new_image(mlx.connect, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.len, &img.endian);
	return (img);
}

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}
