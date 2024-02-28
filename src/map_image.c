/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:05:01 by wiljimen          #+#    #+#             */
/*   Updated: 2024/02/28 16:35:33 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_bckgnd(t_data *mapp)
{
	t_img	img;
	int	i;
	int	j;

	i = 0;
	while (mapp->map_ref[i])
	{
		j = 0;
		while (mapp->map_ref[i][j])
		{
			if (mapp->map_ref[i][j] == '0' || mapp->map_ref[i][j] == '1')
			{
				mlx_put_image_to_window(mapp->mlx, mapp->win, img.background, 
					img.height * 52, img.width * 52);
			}
			j++;
		}
		i++;
	}
}

void	image_put(void *mlx)
{
	t_img	img;
	
	img.background = mlx_xpm_file_to_image(mlx,
			"../sprites/FLOOR.xpm", &img.width, &img.height);
	img.character = mlx_xpm_file_to_image(mlx,
			"../sprites/CJ.xpm", &img.width, &img.height);
	img.coin = mlx_xpm_file_to_image(mlx,
			"../sprites/FLOOR.xpm", &img.width, &img.height);
	img.exit = mlx_xpm_file_to_image(mlx,
			"../sprites/Porsche.xpm", &img.width, &img.height);
}

void	which_image(t_data *mapp, int i, int j)
{
	t_img img;
	
	if (mapp->map_ref[i][j] == 'P')
		mlx_put_image_to_window(mapp->mlx, mapp->win, img.character, 
				img.height * 52, img.width * 52);
	else if (mapp->map_ref[i][j] == 'E')
		mlx_put_image_to_window(mapp->mlx, mapp->win, img.exit, 
			img.height * 52, img.width * 52);
	else if (mapp->map_ref[i][j] == 'C')
		mlx_put_image_to_window(mapp->mlx, mapp->win, img.exit, 
			img.height * 52, img.width * 52);
	else if (mapp->map_ref[i][j] == '1')
		mlx_put_image_to_window(mapp->mlx, mapp->win, img.wall, 
			img.height * 52, img.width * 52);
	else if (mapp->map_ref[i][j] == '0')
		mlx_put_image_to_window(mapp->mlx, mapp->win, img.background, 
			img.height * 52, img.width * 52);
}

void	img_to_window(t_data *mapp)
{
	int	i;
	int	j;

	i = 0;
	image_put(mapp->mlx);
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