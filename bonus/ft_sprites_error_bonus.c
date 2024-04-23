/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites_error_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:28:43 by wiljimen          #+#    #+#             */
/*   Updated: 2024/04/23 14:18:25 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error_sprite(void *sprite, char *str)
{
	if (!sprite)
	{
		ft_printf("%s\n", str);
		exit(EXIT_FAILURE);
	}
}

t_img	*player_sprites1(t_data *mapp)
{
	mapp->img->cjright = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/cjright.xpm", &mapp->img->width, &mapp->img->height);
	ft_error_sprite(mapp->img->cjright, RED "Error in Sprite: cjright");
	mapp->img->cj2r = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/cj2r.xpm", &mapp->img->width, &mapp->img->height);
	ft_error_sprite(mapp->img->cj2r, RED "Error in Sprite: cj2r");
	mapp->img->cjleft = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/cjleft.xpm", &mapp->img->width, &mapp->img->height);
	ft_error_sprite(mapp->img->cjleft, RED"Error in Sprite: cjleft");
	mapp->img->cj2l = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/cj2l.xpm", &mapp->img->width, &mapp->img->height);
	ft_error_sprite(mapp->img->cj2l, RED "Error in Sprite: cj2l");
	return (mapp->img);
}

t_img	*map_sprites(t_data *mapp)
{
	player_sprites(mapp);
	mapp->img->background = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/floor.xpm", &mapp->img->width, &mapp->img->height);
	ft_error_sprite(mapp->img->background, RED "Error in Sprite: background");
	mapp->img->coin = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/money.xpm", &mapp->img->width, &mapp->img->height);
	ft_error_sprite(mapp->img->coin, RED "Error in Sprite: coin");
	mapp->img->exit = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/floor.xpm", &mapp->img->width, &mapp->img->height);
	ft_error_sprite(mapp->img->exit, RED "Error in Sprite: exit");
	mapp->img->wall = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/crate.xpm", &mapp->img->width, &mapp->img->height);
	ft_error_sprite(mapp->img->wall, RED "Error in Sprite: wall");
	mapp->img->policer = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/policer.xpm", &mapp->img->width, &mapp->img->height);
	ft_error_sprite(mapp->img->policer, RED "Error in Sprite: policer");
	mapp->img->policel = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/policel.xpm", &mapp->img->width, &mapp->img->height);
	ft_error_sprite(mapp->img->policel, RED "Error in Sprite: policel");
	return (mapp->img);
}
