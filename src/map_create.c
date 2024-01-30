/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:09:21 by wiljimen          #+#    #+#             */
/*   Updated: 2024/01/29 17:43:25 by wiljimen         ###   ########.fr       */
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

int	valid_map(char **map, int width, int num)
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
			if (ft_strlen(map[i]) != width || map[0][j] != '1'
				|| map[i][width - 1] != '1' || map[i][0] != '1'
				|| map[i][j] != '1')
			{
				ft_free(map[i], num);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
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
				map[i][j] != 'E' || map[i][j] != 'P'
				map[i][j] != 'C')
			{
				ft_free(map[i], i);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

// Conseguir saber si el mapa es válido con todo esto, y guardandolo en variables para saber el resultado.
// En proceso...

int	real_map_valid(t_ptr *mapp, char **argv)
{
	mapp->map.fd = open(argv[1], O_RDONLY);
	mapp->map.all_size = map_size(argv);
	if (mapp->map.all_size == 0)
		return (0);
	mapp->map.line = get_next_line(mapp->map.fd);
	mapp->map.col_count = ft_strlen(mapp->map.line);

}