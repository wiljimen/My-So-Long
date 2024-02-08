/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:09:21 by wiljimen          #+#    #+#             */
/*   Updated: 2024/02/08 18:16:42 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

int	get_num_rows(int fd)
{
	char	*map;
	int		i;

	i = 0;
	if (fd < 0)
		return (0);
	map = get_next_line(fd);
	while (map)
	{
		i++;
		free(map);
		map = get_next_line(fd);
	}
	return (i);
}

void	map_rectangle(char **map, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	if (height == 0 || (int)ft_strlen(map[0]) != width)
		ft_free(map, height);
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if ((i == 0 || i == height - 1) && map[i][j] != '1')
				ft_free(map, height);
			else if ((j == 0 || j == width - 1) && map[i][j] != '1')
				ft_free(map, height);
			j++;
		}
		i++;
	}
}

void	map_chr_check(t_data *mapp)
{
	int	i;
	int	j;

	i = 0;
	while (mapp->map_ref[i])
	{
		j = 0;
		while (mapp->map_ref[i][j] && mapp->map_ref[i][j] != '\n')
		{
			if (mapp->map_ref[i][j] == 'P')
				mapp->mapcnt->player += 1;
			if (mapp->map_ref[i][j] == 'E')
				mapp->mapcnt->exit += 1;
			if (mapp->map_ref[i][j] == 'C')
				mapp->mapcnt->coin += 1;
			if (mapp->map_ref[i][j] != '1'
				&& mapp->map_ref[i][j] != '0')
				ft_free(mapp->map_ref, i);
			j++;
		}
		i++;
	}
}

void	map_print(t_data *mapp)
{
	int	i;

	i = 0;
	mapp->map_ref[i] = get_next_line(mapp->map.fd);
	while (mapp->map_ref[i])
	{
		i++;
		mapp->map_ref[i] = get_next_line(mapp->map.fd);
	}
	mapp->map_ref == NULL;
}

void	map_check(t_data *mapp)
{
	mapp->mapcnt->player = 0;
	mapp->mapcnt->coin = 0;
	mapp->mapcnt->exit = 0;
	mapp->map.line = ft_strlen(mapp->map_ref[0]);
	map_rectangle(mapp->map_ref, mapp->map.line, mapp->map.row);
	map_chr_check(mapp->map_ref);
}

t_map	map_maker(char **argv, t_data *mapp)
{
	mapp->map.line = ft_strlen(argv[1]);
	mapp->map.fd = open(argv[1], O_RDONLY);
	mapp->map.row = get_num_rows(mapp->map.fd);
	mapp->map_ref = ft_calloc(sizeof(char *), mapp->map.row);
	map_check(mapp);
	map_print(mapp);
	return(mapp->map);
}

void	print_map(t_data *mapp)
{
    int i;

    i = 0;
    while (mapp->map_ref[i])
    {
        printf("%s\n", mapp->map_ref[i]);;
        i++;
    }
}
// int	main(int argc, char **argv)
// {
// 	int 	fd;
// 	char	**map;
// 	char	*aux;
// 	int		row_len;
// 	int		row_num;
	
// 	fd = open("/System/Volumes/Data/sgoinfre/students/wiljimen/My-So-Long/src/mapa/mapa.ber", O_RDONLY);
// 	printf("%d\n", fd);
// 	if (fd == -1)
// 		return (1);
// 	row_num = get_num_rows(fd);
// 	map = malloc(sizeof(char *) * row_num);
// 	if (!map)
// 		return (0);
// 	aux = get_next_line(fd);
// 	int i = 0;
// 	while (aux)
// 	{
// 		map[i] = aux;
// 		aux = get_next_line(fd);
// 		++i;
// 	}
// 	row_len = ft_strlen(map[0]);
// 	int map_value = valid_map(map, row_len, get_num_rows(fd));
// 	printf("%d\n", map_value);
// 	close(fd);
// 	return (0);
// }