/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:15:11 by wiljimen          #+#    #+#             */
/*   Updated: 2024/04/16 15:55:09 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_left_move_bonus(t_data *p)
{
	if (p->map_ref[p->ppl.py][p->ppl.px - 1] == '1')
		return ;
	else if (p->map_ref[p->ppl.py][p->ppl.px - 1] == 'C')
	{
		p->mapcnt.coin--;
		if (p->mapcnt.coin == 0)
			p->map_ref[p->ppl.ey][p->ppl.ex] = 'E';
	}
	else if (p->map_ref[p->ppl.py][p->ppl.px - 1] == 'E' && p->mapcnt.coin == 0)
		ft_good_message(p, YELLOW "Mission Passed\n+Respect\n");
	else if (p->map_ref[p->ppl.py][p->ppl.px - 1] == 'N')
		ft_bad_message(p, RED "Wasted\n");
	p->ppl.moves++;
	p->ppl.px--;
	p->map_ref[p->ppl.py][p->ppl.px] = 'P';
	if (p->map_ref[p->ppl.py][p->ppl.px + 1] != 'E')
		p->map_ref[p->ppl.py][p->ppl.px + 1] = '0';
	ft_printf(CLEAR "Moves: %d\n", p->ppl.moves);
	img_to_window(p);
}

void	ft_up_move_bonus(t_data *p)
{
	if (p->map_ref[p->ppl.py - 1][p->ppl.px] == '1')
		return ;
	else if (p->map_ref[p->ppl.py - 1][p->ppl.px] == 'C')
	{
		p->mapcnt.coin--;
		if (p->mapcnt.coin == 0)
			p->map_ref[p->ppl.ey][p->ppl.ex] = 'E';
	}
	else if (p->map_ref[p->ppl.py - 1][p->ppl.px] == 'E' && p->mapcnt.coin == 0)
		ft_good_message(p, YELLOW "Mission Passed\n+Respect\n");
	if (p->map_ref[p->ppl.py - 1][p->ppl.px] == 'N')
		ft_bad_message(p, RED "Wasted\n");
	p->ppl.moves++;
	p->ppl.py--;
	p->map_ref[p->ppl.py][p->ppl.px] = 'P';
	if (p->map_ref[p->ppl.py + 1][p->ppl.px] != 'E')
		p->map_ref[p->ppl.py + 1][p->ppl.px] = '0';
	ft_printf(CLEAR "Moves: %d\n", p->ppl.moves);
	img_to_window(p);
}

void	ft_down_move_bonus(t_data *p)
{
	if (p->map_ref[p->ppl.py + 1][p->ppl.px] == '1')
		return ;
	else if (p->map_ref[p->ppl.py + 1][p->ppl.px] == 'C')
	{
		p->mapcnt.coin--;
		if (p->mapcnt.coin == 0)
			p->map_ref[p->ppl.ey][p->ppl.ex] = 'E';
	}
	else if (p->map_ref[p->ppl.py + 1][p->ppl.px] == 'E' && p->mapcnt.coin == 0)
		ft_good_message(p, YELLOW "Mission Passed\n+Respect\n");
	else if (p->map_ref[p->ppl.py + 1][p->ppl.px] == 'N')
		ft_bad_message(p, RED "Wasted\n");
	p->ppl.moves++;
	p->ppl.py++;
	p->map_ref[p->ppl.py][p->ppl.px] = 'P';
	if (p->map_ref[p->ppl.py - 1][p->ppl.px] != 'E')
		p->map_ref[p->ppl.py - 1][p->ppl.px] = '0';
	ft_printf(CLEAR "Moves: %d\n", p->ppl.moves);
	img_to_window(p);
}

void	ft_right_move_bonus(t_data *p)
{
	if (p->map_ref[p->ppl.py][p->ppl.px + 1] == '1')
		return ;
	else if (p->map_ref[p->ppl.py][p->ppl.px + 1] == 'C')
	{
		p->mapcnt.coin--;
		if (p->mapcnt.coin == 0)
			p->map_ref[p->ppl.ey][p->ppl.ex] = 'E';
	}
	else if (p->map_ref[p->ppl.py][p->ppl.px + 1] == 'E' && p->mapcnt.coin == 0)
		ft_good_message(p, YELLOW "Mission Passed\n+Respect\n");
	else if (p->map_ref[p->ppl.py][p->ppl.px + 1] == 'N')
		ft_bad_message(p, RED "Wasted\n");
	p->ppl.moves++;
	p->ppl.px++;
	p->map_ref[p->ppl.py][p->ppl.px] = 'P';
	if (p->map_ref[p->ppl.py][p->ppl.px - 1] != 'E')
		p->map_ref[p->ppl.py][p->ppl.px - 1] = '0';
	ft_printf(CLEAR "Moves: %d\n", p->ppl.moves);
	img_to_window(p);
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
				mapp->ppl.px = j;
				mapp->ppl.py = i;
			}
			else if (mapp->map_ref[i][j] == 'E')
			{
				mapp->ppl.ex = j;
				mapp->ppl.ey = i;
			}
			j++;
		}
		i++;
	}
}
