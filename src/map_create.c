/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:09:21 by wiljimen          #+#    #+#             */
/*   Updated: 2024/01/31 15:16:30 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_size_total(char **argv)
{
	int		i;
	int		fd;
	char	*buffer;

	i = 0;
	fd = open(argv[0], O_RDONLY);
	if (fd == -1)
		return (0);
	buffer = malloc(sizeof(char));
	while (read(fd, buffer, 1))
		i++;
	close(fd);
	free(buffer);
	return (i);
}

int	valid_map(char **map, int width, int len)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((int)ft_strlen(map[i][j]) != width
				|| map[0][j] != '1' || map[len - 1][j] != '1'
				|| map[i][0] != '1' || map[i][width - 2] != '1')
			{
				ft_free(map, len);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	map_check(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' || map[i][j] != '0'
				|| map[i][j] != 'E' || map[i][j] != 'P'
				|| map[i][j] != 'C')
			{
				ft_free(map, i);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

// Conseguir saber si el mapa es válido con todo esto, y guardandolo en variables para saber el resultado.
// En proceso...
/*
int	real_map_valid(t_ptr *map_ptr, char **argv)
{
	map_ptr->map.fd = open(argv[1], O_RDONLY);
	map_ptr->map.all_size = map_size(argv);
	if (map_ptr->map.all_size == 0)
		return (0);
	map_ptr->map.line = get_next_line(map_ptr->map.fd);
	map_ptr->map.col_count = ft_strlen(map_ptr->map.line);
}*/

int	main(int argc, char **argv)
{
	if (argc > 3)
		return (0);
	else
	{
		int 	fd;
		char	**map;
		
		fd = open(argv[1], O_RDONLY);
		map = get_next_line(fd);
	}
}