/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:15:11 by wiljimen          #+#    #+#             */
/*   Updated: 2024/03/18 17:09:13 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_left_move(t_data *p)
{
	if (p->map_ref[p->ppl.py][p->ppl.px - 1] == '1')
		return ;
	if (p->map_ref[p->ppl.py][p->ppl.px - 1] == 'C')
		p->mapcnt.coin--;
	if (p->map_ref[p->ppl.py][p->ppl.px - 1] == 'E'
		&& p->mapcnt.coin != 0)
		return ;
	if (p->map_ref[p->ppl.py][p->ppl.px - 1] == 'E'
		&& p->mapcnt.coin == 0)
	{
		ft_putstr_fd("Mission Passed\n+Respect", 1);
		exit(EXIT_SUCCESS);
	}
	p->ppl.moves++;
	p->ppl.px--;
	p->map_ref[p->ppl.py][p->ppl.px] = 'P';
	p->map_ref[p->ppl.py][p->ppl.px + 1] = '0';
	ft_printf("Moves: %d\n", p->ppl.moves);
	img_to_window(p);
	return ;
}

void	ft_up_move(t_data *p)
{
	if (p->map_ref[p->ppl.py - 1][p->ppl.px] == '1')
		return ;
	else if (p->map_ref[p->ppl.py - 1][p->ppl.px] == 'C')
		p->mapcnt.coin--;
	else if (p->map_ref[p->ppl.py - 1][p->ppl.px] == 'E'
		&& p->mapcnt.coin != 0)
		return ;
	else if (p->map_ref[p->ppl.py - 1][p->ppl.px] == 'E'
		&& p->mapcnt.coin == 0)
	{
		ft_putstr_fd("Mission Passed\n+Respect", 1);
		exit(EXIT_SUCCESS);
	}
	p->ppl.moves++;
	p->ppl.py--;
	p->map_ref[p->ppl.py][p->ppl.px] = 'P';
	p->map_ref[p->ppl.py + 1][p->ppl.px] = '0';
	ft_printf("Moves: %d\n", p->ppl.moves);
	img_to_window(p);
	return ;
}

void	ft_down_move(t_data *p)
{
	if (p->map_ref[p->ppl.py + 1][p->ppl.px] == '1')
		return ;
	if (p->map_ref[p->ppl.py + 1][p->ppl.px] == 'C')
		p->mapcnt.coin--;
	if (p->map_ref[p->ppl.py + 1][p->ppl.px] == 'E'
		&& p->mapcnt.coin != 0)
		return ;
	if (p->map_ref[p->ppl.py + 1][p->ppl.px] == 'E'
		&& p->mapcnt.coin == 0)
	{
		ft_putstr_fd("Mission Passed\n+Respect", 1);
		exit(EXIT_SUCCESS);
	}
	p->ppl.moves++;
	p->ppl.py++;
	p->map_ref[p->ppl.py][p->ppl.px] = 'P';
	p->map_ref[p->ppl.py - 1][p->ppl.px] = '0';
	ft_printf("Moves: %d\n", p->ppl.moves);
	img_to_window(p);
	return ;
}

void	ft_right_move(t_data *p)
{
	if (p->map_ref[p->ppl.py][p->ppl.px + 1] == '1')
		return ;
	if (p->map_ref[p->ppl.py][p->ppl.px + 1] == 'C')
		p->mapcnt.coin--;
	if (p->map_ref[p->ppl.py][p->ppl.px + 1] == 'E'
		&& p->mapcnt.coin != 0)
		return ;
	if (p->map_ref[p->ppl.py][p->ppl.px + 1] == 'E'
		&& p->mapcnt.coin == 0)
	{
		ft_putstr_fd("Mission Passed\n+Respect", 1);
		exit(EXIT_SUCCESS);
	}
	p->ppl.moves++;
	p->ppl.px++;
	p->map_ref[p->ppl.py][p->ppl.px] = 'P';
	p->map_ref[p->ppl.py][p->ppl.px - 1] = '0';
	ft_printf("Moves: %d\n", p->ppl.moves);
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
				mapp->ppl.px = j;
				mapp->ppl.py = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
