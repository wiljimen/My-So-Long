/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:48:22 by wiljimen          #+#    #+#             */
/*   Updated: 2024/03/08 16:44:32 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
		printf("Mission Failed\n");
		exit(EXIT_SUCCESS);
	}
	// printf("Moves: %d\n", mapp->ppl.moves);
	return (0);
}