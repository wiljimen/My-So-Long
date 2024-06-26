/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:59:22 by wiljimen          #+#    #+#             */
/*   Updated: 2024/04/23 12:58:10 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_data *mapp)
{
	if (keycode == KEY_UP || keycode == KEY_W)
		ft_up_move_bonus(mapp);
	if (keycode == KEY_DOWN || keycode == KEY_S)
		ft_down_move_bonus(mapp);
	if (keycode == KEY_LEFT || keycode == KEY_A)
		ft_left_move_bonus(mapp);
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		ft_right_move_bonus(mapp);
	if (keycode == KEY_ESC)
	{
		ft_printf(RED "Mission Failed\n");
		mlx_destroy_window(mapp->mlx, mapp->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	x_pressed(t_data *mapp)
{
	ft_printf(RED "Mission Failed\n");
	mlx_destroy_window(mapp->mlx, mapp->win);
	exit(EXIT_SUCCESS);
}

void	ft_player(t_data *p, int y, int x)
{
	if (p->ppl.dir == KEY_RIGHT)
		ft_right_frame(p, y, x);
	else if (p->ppl.dir == KEY_LEFT)
		ft_left_frame(p, y, x);
	else if (p->ppl.dir == KEY_UP)
		ft_up_frame(p, y, x);
	else if (p->ppl.dir == KEY_DOWN)
		ft_down_frame(p, y, x);
	else
		ft_stay_frame(p, y, x);
}

void	police_moves(t_data *p, int y, int x)
{
	if (p->frame_police <= 31)
		ft_put_img(p, y, x, p->img->policel);
	else if (p->frame_police < 61)
		ft_put_img(p, y, x, p->img->policer);
}

t_img	*player_sprites(t_data *mapp)
{
	player_sprites1(mapp);
	mapp->img->cjjump = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/cjjump.xpm", &mapp->img->width, &mapp->img->height);
	ft_error_sprite(mapp->img->cjjump, RED "Error in Sprite: cjjump");
	mapp->img->cjcrouch = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/cjcrouch.xpm", &mapp->img->width, &mapp->img->height);
	ft_error_sprite(mapp->img->cjcrouch, RED "Error in Sprite: cjcrouch");
	mapp->img->cjwait = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/cjwait.xpm", &mapp->img->width, &mapp->img->height);
	ft_error_sprite(mapp->img->cjwait, RED "Error in Sprite: cjwait");
	mapp->img->cjdown = mlx_xpm_file_to_image(mapp->mlx,
			"./sprites/cjdown.xpm", &mapp->img->width, &mapp->img->height);
	ft_error_sprite(mapp->img->cjdown, RED "Error in Sprite: cjdown");
	return (mapp->img);
}
