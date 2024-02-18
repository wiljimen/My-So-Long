/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:09:21 by wiljimen          #+#    #+#             */
/*   Updated: 2024/02/18 17:40:50 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

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
			if ((i == 0 || i == height - 1) && map[i][j] != '1'
				&& map[i][j] != '\n')
				ft_free(map, height);
			else if ((j == 0 || j == width - 1) && map[i][j] != '1'
					&& map[i][j] != '\n')
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
				mapp->mapcnt.player += 1;
			else if (mapp->map_ref[i][j] == 'E')
				mapp->mapcnt.exit += 1;
			else if (mapp->map_ref[i][j] == 'C')
				mapp->mapcnt.coin += 1;
			else if (mapp->map_ref[i][j] != '1'
				&& mapp->map_ref[i][j] != '0')
			{
				ft_free(mapp->map_ref, i);
			}
			j++;
		}
		i++;
	}
}

void	map_saver(char **argv, t_data *mapp)
{
	int	i;

	i = 0;
	mapp->map.fd = open(argv[1], O_RDONLY);
	mapp->map_ref[i] = get_next_line(mapp->map.fd);
	while (mapp->map_ref[i])
	{
		i++;
		mapp->map_ref[i] = get_next_line(mapp->map.fd);
	}
	mapp->map_ref[i] = NULL;
	close(mapp->map.fd);
}

void	map_check(t_data *mapp)
{
	mapp->mapcnt.player = 0;
	mapp->mapcnt.coin = 0;
	mapp->mapcnt.exit = 0;
	mapp->map.line = ft_strlen(mapp->map_ref[0]);
	map_rectangle(mapp->map_ref, mapp->map.line, mapp->map.row);
	map_chr_check(mapp);
}

t_map	map_maker(char **argv, t_data *mapp)
{
	mapp->map.line = ft_strlen(argv[1]);
	mapp->map.fd = open(argv[1], O_RDONLY);
	mapp->map.row = get_num_rows(mapp->map.fd);
	mapp->map_ref = ft_calloc(sizeof(char *), mapp->map.row + 1);
	map_saver(argv, mapp);
	map_check(mapp);
	map_print(mapp);
	return (mapp->map);
}

// int main(int argc, char **argv)
// {
// 	if (argc != 2)
// 	{
// 		printf("Error 404\n");
// 		return (0);
// 	}
// 	t_data	*mapp;
// 	mapp = ft_calloc(sizeof(t_data), 1);
// 	map_maker(argv, mapp);
// 	system("leaks -q so_long");
// 	return (0);
// }