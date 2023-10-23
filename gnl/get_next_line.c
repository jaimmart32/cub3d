/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:48:15 by jaimmart          #+#    #+#             */
/*   Updated: 2023/10/23 18:35:36 by jaimmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
//#include <stdio.h>
//#include <fcntl.h>
/*FT_READ_TO_LEFT_STR:
Coge el fd abierto y guarda en una variable "buff" lo que ha leido. Luego 
lo junta a la variable estatica acumulativa para mantener la informacion.

PARAMETROS(un fd, un puntero a la variable estatica acumulativa de ejecuciones
previas de el ft_get_next_line).
RETURN(el nuevo valor de la variable estatica con el buffer unido para la
retencion de la informacion o NULL si hay error).

FT_GET_NEXT_LINE:
Coge  un fd abierto y devuelve la next line

parametros(un fd(archivos, directorios, dispositivos de bloques o dispositivos
 de caracteres)).
return(si tiene exito, devuelve un string con la linea entera terminada en '\n'
cuando la hay. Si hay un error o no hay nada mas que leer, devuellve NULL.*/

	//La función _read lee un máximo de buffer_size bytes en buffer desde el
	// archivo asociado a fd.Devuelve n· de bytes leidos.
char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!f_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = f_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = ft_read_to_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_new_left_str(left_str);
	return (line);
}

/*int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/