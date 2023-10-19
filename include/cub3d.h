/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:36:29 by bbeltran          #+#    #+#             */
/*   Updated: 2023/10/19 18:02:32 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define USAGE "Usage: ./cub3d filename.cub\n"
# define ERRFORMAT "Error: %s: File should be in the \".cub\" format\n"
# define ERROPEN "Error: %s: No access to the file\n"
# define ERRMEM "Error: %s: Memory error\n"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>

enum	e_type
{
	NON,
	N,
	S,
	WE,
	EA,
};

typedef struct s_map
{
	char			*line;
	struct s_map	*next;
}				t_map;

typedef struct s_tex
{
	char			*arg;
	int				type;
	struct s_tex	*next;
}				t_tex;

typedef struct	s_cub
{ 
	char	**map;
	char	*c_ceiling;
	char	*c_floor;
	t_tex	**textures;
}

/*		cub3d		*/
int		start_program(char *filename);
/*		utils		*/

#endif
