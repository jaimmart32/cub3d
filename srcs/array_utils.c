/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:42:36 by bbeltran          #+#    #+#             */
/*   Updated: 2023/10/26 13:09:12 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_2d_array_size(char **array)
{
	int	size;

	size = 0;
	while (array[size])
		size++;
	return (size);
}

size_t	get_longest_line(char **map)
{
	size_t	longest;
	int		i;

	longest = 0;
	i = -1;
	while (map[++i])
	{
		if (ft_strlen(map[i]) > longest)
			longest = ft_strlen(map[i]);
	}
	return (longest);
}

char	**copy_spaced_map(char **map)
{
	char	**spaced_map;
	int		size;
	size_t	longest_line;
	int		i;
	int		j;

	size = get_2d_array_size(map);
	spaced_map = ft_calloc(size + 3, sizeof(char *));
	if (!spaced_map)
		return (printf(ERRMEM, "copy_spaced_map"), NULL);
	longest_line = get_longest_line(map);
	i = 0;
	j = 0;
	while (j <= size + 1)
	{
		if (!j || j == size + 1)
			spaced_map[j] = get_spaced_line(NULL, longest_line); 
		else
			spaced_map[j] = get_spaced_line(map[i++], longest_line); 
		j++;
	}
	return (spaced_map);
}

void	free_2d_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}
