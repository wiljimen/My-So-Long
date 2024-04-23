/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:05:01 by wiljimen          #+#    #+#             */
/*   Updated: 2024/04/23 13:16:25 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_bckgnd(t_data *mapp)
{
	int	i;
	int	j;

	i = 0;
	find_p(mapp);
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
	mapp->img->background = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/floor.xpm", &mapp->img->width, &mapp->img->height);
	ft_error_sprite(mapp->img->background, RED "Error in Sprite: background");
	mapp->img->cjwait = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/cjwait.xpm", &mapp->img->width, &mapp->img->height);
	ft_error_sprite(mapp->img->cjwait, RED "Error in Sprite: cjwait");
	mapp->img->coin = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/money.xpm", &mapp->img->width, &mapp->img->height);
	ft_error_sprite(mapp->img->coin, RED "Error in Sprite: coin");
	mapp->img->exit = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/floor.xpm", &mapp->img->width, &mapp->img->height);
	ft_error_sprite(mapp->img->exit, RED "Error in Sprite: exit");
	mapp->img->wall = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/crate.xpm", &mapp->img->width, &mapp->img->height);
	ft_error_sprite(mapp->img->wall, RED "Error in Sprite: wall");
	if (mapp->mapcnt.coin == 0)
	{
		mapp->img->exit = mlx_xpm_file_to_image(mapp->mlx,
				"./sprites/exit-car.xpm", &mapp->img->width, &mapp->img->height);
		ft_error_sprite(mapp->img->exit, RED"Error in Sprite: exit (coin = 0)");
	}
	return (mapp->img);
}

void	which_image(t_data *mapp, int i, int j)
{
	if (mapp->map_ref[i][j] == 'P')
		ft_put_img(mapp, j * 52, i * 52, mapp->img->cjwait);
	else if (mapp->map_ref[i][j] == 'E')
		ft_put_img(mapp, j * 52, i * 52, mapp->img->exit);
	else if (mapp->map_ref[i][j] == 'C')
		ft_put_img(mapp, j * 52, i * 52, mapp->img->coin);
	else if (mapp->map_ref[i][j] == '1')
		ft_put_img(mapp, j * 52, i * 52, mapp->img->wall);
	else if (mapp->map_ref[i][j] == '0')
		ft_put_img(mapp, j * 52, i * 52, mapp->img->background);
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
