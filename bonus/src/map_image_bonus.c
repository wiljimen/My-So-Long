/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_image_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:05:01 by wiljimen          #+#    #+#             */
/*   Updated: 2024/04/02 18:15:37 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	fill_bckgnd(t_data *mapp)
{
	int	i;
	int	j;

	i = 0;
	while (mapp->map_ref[i])
	{
		j = 0;
		while (mapp->map_ref[i][j])
		{
			ft_put_img(mapp, j * 52, i * 52,
				mapp->img->background);
			j++;
		}
		i++;
	}
}

t_img	*image_put(t_data *mapp)
{
	player_sprites(mapp);
	mapp->img->background = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/floor.xpm", &mapp->img->width, &mapp->img->height);
	mapp->img->character = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/cj.xpm", &mapp->img->width, &mapp->img->height);
	mapp->img->coin = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/Money.xpm", &mapp->img->width, &mapp->img->height);
	mapp->img->exit = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/exit-close.xpm", &mapp->img->width, &mapp->img->height);
	mapp->img->wall = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/crate.xpm", &mapp->img->width, &mapp->img->height);
	mapp->img->enemyr = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/policer.xpm", &mapp->img->width, &mapp->img->height);
	mapp->img->enemyl = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/policel.xpm", &mapp->img->width, &mapp->img->height);
	if (mapp->mapcnt.coin == 0)
		mapp->img->exit = mlx_xpm_file_to_image(mapp->mlx,
				"./sprites/exit-open.xpm",
				&mapp->img->width, &mapp->img->height);
	return (mapp->img);
}

void	img_to_window(t_data *mapp)
{
	int	i;
	int	j;

	i = 0;
	mapp->img = image_put(mapp);
	fill_bckgnd(mapp);
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
}