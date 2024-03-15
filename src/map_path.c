/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:51:25 by wiljimen          #+#    #+#             */
/*   Updated: 2024/03/15 16:28:35 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_coin_left(t_data *mapp)
{
	int	i;
	int	j;

	mapp->mapcnt.coin_left = 0;
	i = 0;
	while (mapp->map_cpy[i])
	{
		j = 0;
		while(mapp->map_cpy[i][j])
		{
			if (mapp->map_cpy[i][j] == 'C')
			{
				mapp->mapcnt.coin_left++;
			}
			j++;
		}
		i++;
	}
}

void	floodfill_map_coin(t_data *mapp, int y, int x)
{
	ft_coin_left(mapp);
	if (mapp->map_cpy[y][x] == '1' || mapp->map_cpy[y][x] == 'X'
		|| (mapp->map_cpy[y][x] == 'E' && mapp->mapcnt.coin_left > 0))
		return ;
	if (mapp->map_cpy[y][x] == 'C')
		mapp->mapcnt.coin_left--;
	mapp->map_cpy[y][x] = 'X';
	floodfill_map_coin(mapp, y, x + 1);
	floodfill_map_coin(mapp, y + 1, x);
	floodfill_map_coin(mapp, y, x - 1);
	floodfill_map_coin(mapp, y - 1, x);
}


void	valid_exit(t_data *mapp, int y, int x)
{
	floodfill_map_coin(mapp, y, x);
	if (mapp->mapcnt.coin_left > 0)
	{
		ft_free(mapp->map_cpy, mapp->map.row, "No valid path");
		exit(EXIT_FAILURE);
	}
}