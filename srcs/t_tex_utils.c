/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:27:44 by jaimmart          #+#    #+#             */
/*   Updated: 2023/10/25 12:31:52 by jaimmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	t_tex_size(t_tex *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
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
