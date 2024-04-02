/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:00:10 by wiljimen          #+#    #+#             */
/*   Updated: 2024/04/02 18:33:01 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_put_img(t_data *map, int y, int x, void *img)
{
	mlx_put_image_to_window(map->mlx, map->win, img, y, x);
}

t_img	*player_sprites(t_data *mapp)
{
	mapp->img->cjright = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/cright.xpm", &mapp->img->width, &mapp->img->height);
	mapp->img->cj1right = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/c1right.xpm", &mapp->img->width, &mapp->img->height);
	mapp->img->cjleft = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/cjleft.xpm", &mapp->img->width, &mapp->img->height);
	mapp->img->cj1left = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/cj1left.xpm", &mapp->img->width, &mapp->img->height);
	mapp->img->cjjump = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/cjjump.xpm", &mapp->img->width, &mapp->img->height);
	mapp->img->cjcrouch = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/cjcrouch.xpm", &mapp->img->width, &mapp->img->height);
	return (mapp->img);
}

void ft_sleep(int seconds)
{
    int i;
	
	i = 0;
    while (i < seconds * 1000000)
		i++;
}

// void animate_police(t_data *mapp, int j, int i)
// {
//     ft_put_img(mapp, mapp-> * 52, i * 52, mapp->img->enemyr);
// 	printf("%d\n%d\n\n\n", i, j);
// 	ft_sleep(1);
//     ft_put_img(mapp, j * 52, i * 52, mapp->img->enemyl);
// 	ft_sleep(1);
// }

// void	animate_police_loop(t_data *mapp)
// {
//     mlx_loop_hook(mapp->mlx, animate_police, mapp);
// }

int	random_num(void)
{
	static int	n;
	
	n = 0;
	n++;
	return (n);
}

void	which_image(t_data *mapp, int i, int j)
{
	int randn;
		
	randn = random_num();
	if (mapp->map_ref[i][j] == 'P')
		ft_put_img(mapp, j * 52, i * 52, mapp->img->character);
	else if (mapp->map_ref[i][j] == 'E')
		ft_put_img(mapp, j * 52, i * 52, mapp->img->exit);
	else if (mapp->map_ref[i][j] == 'C')
		ft_put_img(mapp, j * 52, i * 52, mapp->img->coin);
	else if (mapp->map_ref[i][j] == '1')
		ft_put_img(mapp, j * 52, i * 52, mapp->img->wall);
	else if (mapp->map_ref[i][j] == '0')
		ft_put_img(mapp, j * 52, i * 52, mapp->img->background);
	else if (mapp->map_ref[i][j] == 'N')
	{
		if(random_num() % 2 == 0)
		{
			ft_put_img(mapp, j * 52, i * 52, mapp->img->enemyl);
		}
		else
		{
			ft_put_img(mapp, j * 52, i * 52, mapp->img->enemyr);
		}
	}
}
