/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:15:11 by wiljimen          #+#    #+#             */
/*   Updated: 2024/02/28 16:41:28 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_left_move(t_data *P)
{
	if (P->map_ref[P->ppl.player_y][P->ppl.player_x - 1] == '1')
		return ;
	if (P->map_ref[P->ppl.player_y][P->ppl.player_x - 1] == 'C')
		P->mapcnt.coin--;
	if (P->map_ref[P->ppl.player_y][P->ppl.player_x - 1] == 'E'
		&& P->mapcnt.coin != 0)
		return ;
	if (P->map_ref[P->ppl.player_y][P->ppl.player_x - 1] == 'E'
		&& P->mapcnt.coin == 0)
		exit(EXIT_SUCCESS);
	P->ppl.moves++;
	P->ppl.player_x--;
	P->map_ref[P->ppl.player_y][P->ppl.player_x + 1] = 'P';
	P->map_ref[P->ppl.player_y][P->ppl.player_x] = '0';
	return ;
}

void	ft_up_move(t_data *P)
{
	if (P->map_ref[P->ppl.player_y - 1][P->ppl.player_x] == '1')
		return ;
	if (P->map_ref[P->ppl.player_y - 1][P->ppl.player_x] == 'C')
		P->mapcnt.coin--;
	if (P->map_ref[P->ppl.player_y - 1][P->ppl.player_x] == 'E'
		&& P->mapcnt.coin != 0)
		return ;
	if (P->map_ref[P->ppl.player_y - 1][P->ppl.player_x] == 'E'
		&& P->mapcnt.coin == 0)
		exit(EXIT_SUCCESS);
	P->ppl.moves++;
	P->ppl.player_y--;
	P->map_ref[P->ppl.player_y - 1][P->ppl.player_x] = 'P';
	P->map_ref[P->ppl.player_y][P->ppl.player_x] = '0';
	return ;
}

void	ft_down_move(t_data *P)
{
	if (P->map_ref[P->ppl.player_y + 1][P->ppl.player_x] == '1')
		return ;
	if (P->map_ref[P->ppl.player_y + 1][P->ppl.player_x] == 'C')
		P->mapcnt.coin--;
	if (P->map_ref[P->ppl.player_y + 1][P->ppl.player_x] == 'E'
		&& P->mapcnt.coin != 0)
		return ;
	if (P->map_ref[P->ppl.player_y + 1][P->ppl.player_x] == 'E'
		&& P->mapcnt.coin == 0)
		exit(EXIT_SUCCESS);
	P->ppl.moves++;
	P->ppl.player_y++;
	P->map_ref[P->ppl.player_y + 1][P->ppl.player_x] = 'P';
	P->map_ref[P->ppl.player_y][P->ppl.player_x] = '0';
	return ;
}

void	ft_right_move(t_data *P)
{
	if (P->map_ref[P->ppl.player_y][P->ppl.player_x + 1] == '1')
		return ;
	if (P->map_ref[P->ppl.player_y][P->ppl.player_x + 1] == 'C')
		P->mapcnt.coin--;
	if (P->map_ref[P->ppl.player_y][P->ppl.player_x + 1] == 'E'
		&& P->mapcnt.coin != 0)
		return ;
	if (P->map_ref[P->ppl.player_y][P->ppl.player_x + 1] == 'E'
		&& P->mapcnt.coin == 0)
		exit(EXIT_SUCCESS);
	P->ppl.moves++;
	P->ppl.player_x++;
	P->map_ref[P->ppl.player_y][P->ppl.player_x + 1] = 'P';
	P->map_ref[P->ppl.player_y][P->ppl.player_x] = '0';
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
