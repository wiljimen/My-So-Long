/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:48:22 by wiljimen          #+#    #+#             */
/*   Updated: 2024/04/08 13:15:52 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_moves(t_data *p, int y, int x)
{
	if (p->map_ref[y][x] == '1' || (p->map_ref[y][x] == 'E'
		&& p->mapcnt.coin != 0))
		return ;
	else if (p->map_ref[y][x] == 'C')
		p->mapcnt.coin--;
	else if (p->map_ref[y][x] == 'E'
		&& p->mapcnt.coin == 0)
	{
		ft_putstr_fd("Mission Passed\n+Respect", 1);
		exit(EXIT_SUCCESS);
	}
	else if (p->map_ref[y][x] == 'N')
	{
		ft_putstr_fd("Wasted\n", 1);
		exit(EXIT_FAILURE);
	}
}

int	key_hook(int keycode, t_data *mapp)
{
	if (keycode == KEY_UP || keycode == KEY_W)
		ft_up_move(mapp);
	if (keycode == KEY_DOWN || keycode == KEY_S)
		ft_down_move(mapp);
	if (keycode == KEY_LEFT || keycode == KEY_A)
		ft_left_move(mapp);
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		ft_right_move(mapp);
	if (keycode == KEY_ESC)
	{
		ft_printf("Mission Failed\n");
		mlx_destroy_window(mapp->mlx, mapp->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	x_pressed(t_data *mapp)
{
	ft_printf("Mission Failed\n");
	mlx_destroy_window(mapp->mlx, mapp->win);
	exit(EXIT_SUCCESS);
}
