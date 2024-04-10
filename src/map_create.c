/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:09:21 by wiljimen          #+#    #+#             */
/*   Updated: 2024/04/10 15:05:36 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_rectangle(char **map, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		if (!map[i])
			ft_free(map, "Empty line somewhere\n");
		j = 0;
		while (j < width)
		{
			if ((i == 0 || i == height - 1) && map[i][j] != '1'
				&& map[i][j] != '\n')
				ft_free(map, "Bad top or bottom borders");
			else if ((j == 0 || j == width - 1) && map[i][j] != '1'
					&& map[i][j] != '\n')
				ft_free(map, "Bad lateral borders");
			j++;
		}
		if ((int)ft_strlen(map[0]) != (int)ft_strlen(map[i]))
			ft_free(map, "Map isn't rectangle");
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
		while (mapp->map_ref[i][j])
		{
			if (mapp->map_ref[i][j] != 'P' && mapp->map_ref[i][j] != 'C'
				&& mapp->map_ref[i][j] != '1' && mapp->map_ref[i][j] != '0'
				&& mapp->map_ref[i][j] != 'E' && mapp->map_ref[i][j] != 'N'
				&& mapp->map_ref[i][j] != '\n')
				ft_free(mapp->map_ref, "Bad characthers");
			j++;
		}
		i++;
	}
}

void	map_content(t_data *mapp)
{
	int	i;
	int	j;

	i = 0;
	while (mapp->map_ref[i])
	{
		j = 0;
		while (mapp->map_ref[i][j])
		{
			if (mapp->map_ref[i][j] == 'P')
				mapp->mapcnt.player += 1;
			else if (mapp->map_ref[i][j] == 'E')
				mapp->mapcnt.exit += 1;
			else if (mapp->map_ref[i][j] == 'C')
				mapp->mapcnt.coin += 1;
			else if (mapp->map_ref[i][j] == 'N')
				mapp->mapcnt.enemy += 1;
			j++;
		}
		i++;
	}
	if (mapp->mapcnt.exit != 1 || mapp->mapcnt.player != 1)
		ft_free(mapp->map_ref, "Player or Exit not equal than 1");
	if (mapp->mapcnt.coin < 1)
		ft_free(mapp->map_ref, "Coins less than 1");
}

void	map_check(t_data *mapp)
{
	mapp->mapcnt.player = 0;
	mapp->mapcnt.coin = 0;
	mapp->mapcnt.exit = 0;
	mapp->mapcnt.enemy = 0;
	// if (ft_is_readable(mapp->map_ref[0]) == false)
	// 	print_error("Empty or invalid map\n");
	mapp->map.line = ft_strlen(mapp->map_ref[0]);
	map_rectangle(mapp->map_ref, mapp->map.line, mapp->map.row);
	map_chr_check(mapp);
	map_content(mapp);
	find_p(mapp);
	valid_exit(mapp, mapp->ppl.py, mapp->ppl.px);
}
