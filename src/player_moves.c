/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:15:11 by wiljimen          #+#    #+#             */
/*   Updated: 2024/03/08 16:45:39 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_left_move(t_data *p)
{
	if (p->map_ref[p->ppl.player_y][p->ppl.player_x - 1] == '1')
		return ;
	if (p->map_ref[p->ppl.player_y][p->ppl.player_x - 1] == 'C')
		p->mapcnt.coin--;
	if (p->map_ref[p->ppl.player_y][p->ppl.player_x - 1] == 'E'
		&& p->mapcnt.coin != 0)
		return ;
	if (p->map_ref[p->ppl.player_y][p->ppl.player_x - 1] == 'E'
		&& p->mapcnt.coin == 0)
	{
		printf("Mission Passed\n+Respect");
		exit(EXIT_SUCCESS);
	}
	p->ppl.moves++;
	p->ppl.player_x--;
	p->map_ref[p->ppl.player_y][p->ppl.player_x] = 'P';
	p->map_ref[p->ppl.player_y][p->ppl.player_x + 1] = '0';
	printf("Moves: %d\n", p->ppl.moves);
	img_to_window(p);
	return ;
}

void	ft_up_move(t_data *p)
{
	
	if (p->map_ref[p->ppl.player_y - 1][p->ppl.player_x] == '1')
		return ;
	else if (p->map_ref[p->ppl.player_y - 1][p->ppl.player_x] == 'C')
		p->mapcnt.coin--;
	else if (p->map_ref[p->ppl.player_y - 1][p->ppl.player_x] == 'E'
		&& p->mapcnt.coin != 0)
		return ;
	else if (p->map_ref[p->ppl.player_y - 1][p->ppl.player_x] == 'E'
		&& p->mapcnt.coin == 0)
	{
		printf("Mission Passed\n+Respect");
		exit(EXIT_SUCCESS);
	}
	p->ppl.moves++;
	p->ppl.player_y--;
	p->map_ref[p->ppl.player_y][p->ppl.player_x] = 'P';
	p->map_ref[p->ppl.player_y + 1][p->ppl.player_x] = '0';
	printf("Moves: %d\n", p->ppl.moves);
	img_to_window(p);
	return ;
}

void	ft_down_move(t_data *p)
{
	if (p->map_ref[p->ppl.player_y + 1][p->ppl.player_x] == '1')
		return ;
	if (p->map_ref[p->ppl.player_y + 1][p->ppl.player_x] == 'C')
		p->mapcnt.coin--;
	if (p->map_ref[p->ppl.player_y + 1][p->ppl.player_x] == 'E'
		&& p->mapcnt.coin != 0)
		return ;
	if (p->map_ref[p->ppl.player_y + 1][p->ppl.player_x] == 'E'
		&& p->mapcnt.coin == 0)
	{
		printf("Mission Passed\n+Respect");
		exit(EXIT_SUCCESS);
	}
	p->ppl.moves++;
	p->ppl.player_y++;
	p->map_ref[p->ppl.player_y][p->ppl.player_x] = 'P';
	p->map_ref[p->ppl.player_y - 1][p->ppl.player_x] = '0';
	printf("Moves: %d\n", p->ppl.moves);
	img_to_window(p);
	return ;
}

void	ft_right_move(t_data *p)
{
	if (p->map_ref[p->ppl.player_y][p->ppl.player_x + 1] == '1')
		return ;
	if (p->map_ref[p->ppl.player_y][p->ppl.player_x + 1] == 'C')
		p->mapcnt.coin--;
	if (p->map_ref[p->ppl.player_y][p->ppl.player_x + 1] == 'E'
		&& p->mapcnt.coin != 0)
		return ;
	if (p->map_ref[p->ppl.player_y][p->ppl.player_x + 1] == 'E'
		&& p->mapcnt.coin == 0)
	{
		printf("Mission Passed\n+Respect");
		exit(EXIT_SUCCESS);
	}
	p->ppl.moves++;
	p->ppl.player_x++;
	p->map_ref[p->ppl.player_y][p->ppl.player_x] = 'P';
	p->map_ref[p->ppl.player_y][p->ppl.player_x - 1] = '0';
	printf("Moves: %d\n", p->ppl.moves);
	img_to_window(p);
	return ;
}

void	find_p(t_data *mapp)
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
			{
				mapp->ppl.player_x = j;
				mapp->ppl.player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
