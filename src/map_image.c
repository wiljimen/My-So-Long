/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:05:01 by wiljimen          #+#    #+#             */
/*   Updated: 2024/03/15 15:16:10 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
			mlx_put_image_to_window(mapp->mlx, mapp->win,
				mapp->img->background, j * 52, i * 52);
			j++;
		}
		i++;
	}
}

t_img	*image_put(t_data *mapp)
{
	mapp->img->background = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/floor.xpm", &mapp->img->width, &mapp->img->height);
	mapp->img->character = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/cjhd.xpm", &mapp->img->width, &mapp->img->height);
	mapp->img->coin = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/Money.xpm", &mapp->img->width, &mapp->img->height);
	mapp->img->exit = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/exit-close.xpm", &mapp->img->width, &mapp->img->height);
	mapp->img->wall = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/CRATE.xpm", &mapp->img->width, &mapp->img->height);
	if (mapp->mapcnt.coin == 0)
		mapp->img->exit = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/exit-open.xpm", &mapp->img->width, &mapp->img->height);
	return (mapp->img);
}

void	which_image(t_data *mapp, int i, int j)
{
	if (mapp->map_ref[i][j] == 'P')
		mlx_put_image_to_window(mapp->mlx, mapp->win, mapp->img->character,
			j * 52, i * 52);
	else if (mapp->map_ref[i][j] == 'E')
		mlx_put_image_to_window(mapp->mlx, mapp->win, mapp->img->exit,
			j * 52, i * 52);
	else if (mapp->map_ref[i][j] == 'C')
		mlx_put_image_to_window(mapp->mlx, mapp->win, mapp->img->coin,
			j * 52, i * 52);
	else if (mapp->map_ref[i][j] == '1')
		mlx_put_image_to_window(mapp->mlx, mapp->win, mapp->img->wall,
			j * 52, i * 52);
	else if (mapp->map_ref[i][j] == '0')
		mlx_put_image_to_window(mapp->mlx, mapp->win, mapp->img->background,
			j * 52, i * 52);
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
}
