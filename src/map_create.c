/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:09:21 by wiljimen          #+#    #+#             */
/*   Updated: 2024/02/07 18:55:40 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_sl_utils.c"
#include "ft_strlen.c"
#include "get_next_line.c"

int	get_num_rows(int fd)
{
	char	*map;
	int		i;

	i = 0;
	map = get_next_line(fd);
	while (map)
	{
		i++;
		free(map);
		map = get_next_line(fd);
	}
	return (i);
}

int	valid_map(char **map, int width, int height)
{
	int	i;

	i = 0;
	while (i < width - 1)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != width
			|| map[i][width - 1] != '1' || map[i][0] != '1')
		{
			ft_free(map, width);
			return (1);
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
			if (map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != 'E' && map[i][j] != 'P'
				&& map[i][j] != 'C' && map[i][j] != '\n')
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

int	main(int argc, char **argv)
{
	int 	fd;
	char	**map;
	char	*aux;
	int		row_len;
	int		row_num;
	
	fd = open("/System/Volumes/Data/sgoinfre/students/wiljimen/My-So-Long/src/mapa/mapa.ber", O_RDONLY);
	printf("%d\n", fd);
	if (fd == -1)
		return (1);
	row_num = get_num_rows(fd);
	map = malloc(sizeof(char *) * row_num);
	if (!map)
		return (0);
	aux = get_next_line(fd);
	int i = 0;
	while (aux)
	{
		map[i] = aux;
		aux = get_next_line(fd);
		++i;
	}
	row_len = ft_strlen(map[0]);
	int map_value = valid_map(map, row_len, get_num_rows(fd));
	printf("%d\n", map_value);
	close(fd);
	return (0);
}