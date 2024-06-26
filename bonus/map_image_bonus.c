/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_image_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:52:43 by wiljimen          #+#    #+#             */
/*   Updated: 2024/04/23 14:17:08 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_bckgnd(t_data *mapp)
{
	int	i;
	int	j;

	i = 0;
	mapp->img = image_put(mapp);
	while (mapp->map_ref[i])
	{
		j = 0;
		while (mapp->map_ref[i][j])
		{
			ft_put_img(mapp, j * 52, i * 52, mapp->img->background);
			j++;
		}
		i++;
	}
}

t_img	*image_put(t_data *mapp)
{
	player_sprites(mapp);
	map_sprites(mapp);
	if (mapp->mapcnt.coin == 0)
	{
		mapp->img->exit = mlx_xpm_file_to_image(mapp->mlx,
				"./sprites/exit-car.xpm",
				&mapp->img->width, &mapp->img->height);
		ft_error_sprite(mapp->img->exit, RED "Error in Sprite: exit(coin = 0)");
	}
	return (mapp->img);
}

void	which_image(t_data *mapp, int i, int j)
{
	if (mapp->map_ref[i][j] == 'P')
		ft_player(mapp, j * 52, i * 52);
	else if (mapp->map_ref[i][j] == 'E')
		ft_put_img(mapp, j * 52, i * 52, mapp->img->exit);
	else if (mapp->map_ref[i][j] == 'C')
		ft_put_img(mapp, j * 52, i * 52, mapp->img->coin);
	else if (mapp->map_ref[i][j] == '1')
		ft_put_img(mapp, j * 52, i * 52, mapp->img->wall);
	else if (mapp->map_ref[i][j] == '0')
		ft_put_img(mapp, j * 52, i * 52, mapp->img->background);
	else if (mapp->map_ref[i][j] == 'N')
		police_moves(mapp, j * 52, i * 52);
}

void	img_to_window_bonus(t_data *mapp)
{
	int	i;
	int	j;

	i = 0;
	while (mapp->map_ref[i])
	{
		j = 0;
		while (mapp->map_ref[i][j])
		{
			which_image(mapp, i, j);
			j++;
		}
		i++;
	}
	moves_counter_img(mapp);
}

void	moves_counter_img(t_data *mapp)
{
	char	*moves;

	moves = ft_itoa(mapp->ppl.moves);
	mlx_string_put(mapp->mlx, mapp->win, 10, 20, 0x000000, "Moves:");
	mlx_string_put(mapp->mlx, mapp->win, 60, 20, 0x000000, moves);
	free(moves);
}
