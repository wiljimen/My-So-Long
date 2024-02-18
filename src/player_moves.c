/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:15:11 by wiljimen          #+#    #+#             */
/*   Updated: 2024/02/18 17:30:50 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	return (P->ppl);
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
	return (P->ppl);
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
	return (P->ppl);
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
	return (P->ppl);
}
