/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:36:29 by bbeltran          #+#    #+#             */
/*   Updated: 2023/10/23 15:51:32 by jaimmart         ###   ########.fr       */
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

typedef struct s_tex
{
	char			*arg;
	int				type;
	struct s_tex	*next;
}				t_tex;

typedef struct s_cub
{
	char	**map;
	int		c_ceiling[3];
	int		c_floor[3];
	t_tex	**textures;
}				t_cub;

/*		cub3d		*/
int	start_program(char *filename);
/*		utils		*/

#endif
