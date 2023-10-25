/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:36:29 by bbeltran          #+#    #+#             */
/*   Updated: 2023/10/25 17:12:23 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define USAGE "Usage: ./cub3d filename.cub\n"
# define ERRFORMAT "Error: %s: File should be in the \".cub\" format\n"
# define ERROPEN "Error: %s: No access to the file\n"
# define ERRMEM "Error: %s: Memory error\n"
# define ERRCOLOR "Error: %s: Non-valid RGB value\n"
# define ERRTEXT "Error: Non-valid textures\n"
# define ERRMAP "Error: Non-valid map\n"

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

enum	e_tx_type
{
	NON,
	NO,
	SO,
	WE,
	EA,
};

enum	e_map_char
{
	NOT_VALID,
	OPEN,
	WALL,
	PLAYER,
	SPACE,
};

typedef struct s_tex
{
	char			*path;
	int				type;
	struct s_tex	*next;
}				t_tex;

typedef struct s_cub
{
	char	**map;
	int		ceiling[3];
	int		floor[3];
	t_tex	**textures;
}				t_cub;

/*		cub3d		*/
int		check_extension(char *filename);
int		parsing(char *filename);
/*		t_tex__utils	*/
void	insert_node(t_tex **lst, t_tex *node);
t_tex	*create_node(char *texture_path, int type);
int		t_tex_size(t_tex *lst);
/*		tc_utils		*/
int		check_rgb_code(int *rgb_code);
int		only_numbers(char *str);
int		check_extension(char *filename);
/*		fetch_header_data		*/
t_cub	*fetch_header_data(int file_fd);
/*		map_parsing				*/
char	**get_map(char *filename);
int		valid_char(char c);
/*		checkers				*/
char	*get_spaced_line(char *str, int len);
int		check_cub_struct(t_cub *cub);
/*		array_utils				*/
int		get_2d_array_size(char **array);
char	**copy_spaced_map(char **map);
void	free_2d_array(char **array);


#endif
