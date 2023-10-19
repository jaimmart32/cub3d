/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:49:51 by bbeltran          #+#    #+#             */
/*   Updated: 2023/10/19 17:59:06 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*last_node(t_map **map)
{
	t_map	*curr;

	curr = *map;
	while (curr->next)
		curr = curr->next;
	return (curr);
}

void	map_add_back(t_map **map, t_map *node)
{
	if (!*map)
		*map = node;
	else
		(last_node(map))->next = node;
}
