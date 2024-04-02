/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:51:25 by wiljimen          #+#    #+#             */
/*   Updated: 2024/04/01 15:17:36 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	map_saver(char **argv, t_data *mapp)
{
	int		i;
	char	*aux;
	char	*temp;

	i = 0;
	mapp->map.fd = open(argv[1], O_RDONLY);
	aux = get_next_line(mapp->map.fd);
	temp = ft_calloc(ft_strlen(aux), sizeof(char *));
	while (aux)
	{
		temp = ft_strjoin(temp, aux);
		free(aux);
		aux = get_next_line(mapp->map.fd);
	}
	mapp->map_ref = ft_split(temp, '\n');
	mapp->map_cpy = ft_split(temp, '\n');
	close(mapp->map.fd);
}

void	ft_coin_left(t_data *mapp)
{
	int	i;
	int	j;

	mapp->mapcnt.coin_left = 0;
	mapp->mapcnt.exit_count = 0;
	i = 0;
	while (mapp->map_cpy[i])
	{
		j = 0;
		while (mapp->map_cpy[i][j])
		{
			if (mapp->map_cpy[i][j] == 'C')
				mapp->mapcnt.coin_left++;
			else if (mapp->map_cpy[i][j] == 'E')
				mapp->mapcnt.exit_count++;
			j++;
		}
		i++;
	}
}

void	floodfill_map_coin(t_data *mapp, int y, int x)
{
	if (mapp->map_cpy[y][x] == '1' || mapp->map_cpy[y][x] == 'X')
		return ;
	if (mapp->map_cpy[y][x] == 'C')
		mapp->mapcnt.coin_left--;
	if (mapp->map_cpy[y][x] == 'E')
		mapp->mapcnt.exit_count--;
	mapp->map_cpy[y][x] = 'X';
	floodfill_map_coin(mapp, y, x + 1);
	floodfill_map_coin(mapp, y + 1, x);
	floodfill_map_coin(mapp, y, x - 1);
	floodfill_map_coin(mapp, y - 1, x);
}

void	valid_exit(t_data *mapp, int y, int x)
{
	ft_coin_left(mapp);
	floodfill_map_coin(mapp, y, x);
	if (mapp->mapcnt.coin_left > 0 || mapp->mapcnt.exit_count > 0)
	{
		ft_free(mapp->map_cpy, "No valid path");
		exit(EXIT_FAILURE);
	}
}
