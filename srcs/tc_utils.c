/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:24:46 by bbeltran          #+#    #+#             */
/*   Updated: 2023/10/24 16:04:57 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	insert_node(t_tex **lst, t_tex *node)
{
	t_tex	*curr;

	if (!*lst)
		*lst = node;
	else
	{
		curr = *lst;
		while (curr->next)
			curr = curr->next;
		curr->next = node;
	}
}

t_tex	*create_node(char *texture_path, int type)
{
	t_tex	*new;

	new = malloc(sizeof(t_tex));
	if (!new)
		return (printf(ERRMEM, "create_node"), NULL);
	new->path = ft_strdup(texture_path);
	new->type = type;
	new->next = NULL;
	return (new);
}

int	check_rgb_code(int *rgb_code)
{
	if (rgb_code[0] < 0 || rgb_code[0] > 255)
		return (0);
	if (rgb_code[1] < 0 || rgb_code[1] > 255)
		return (0);
	if (rgb_code[2] < 0 || rgb_code[2] > 255)
		return (0);
	return (1);
}

int	only_numbers(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != '\n' && !ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

int	check_extension(char *filename)
{
	int		i;
	int		j;
	char	*ext;

	ext = ".cub";
	i = ft_strlen(filename);
	j = ft_strlen(ext);
	while (j >= 0)
	{
		if (filename[i--] != ext[j--])
			return (0);
	}
	return (1);
}

void	free_2d_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
}
