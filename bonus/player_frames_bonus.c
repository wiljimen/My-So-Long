/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_frames_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:35:48 by wiljimen          #+#    #+#             */
/*   Updated: 2024/04/19 17:37:13 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_stay_frame(t_data *p, int y, int x)
{
	if (p->frame <= 31)
		ft_put_img(p, y, x, p->img->cjwait);
	else if (p->frame < 61)
		ft_put_img(p, y, x, p->img->cjcrouch);
}

void	ft_right_frame(t_data *p, int y, int x)
{
	if (p->frame <= 1)
		ft_put_img(p, y, x, p->img->cjright);
	else if (p->frame <= 11)
		ft_put_img(p, y, x, p->img->cj2r);
	else if (p->frame < 61)
	{
		p->frame = 0;
		p->ppl.dir = -1;
		ft_stay_frame(p, y, x);
	}
}

void	ft_left_frame(t_data *p, int y, int x)
{
	if (p->frame <= 1)
		ft_put_img(p, y, x, p->img->cjleft);
	else if (p->frame <= 11)
		ft_put_img(p, y, x, p->img->cj2l);
	else if (p->frame < 61)
	{
		p->frame = 0;
		p->ppl.dir = -1;
		ft_stay_frame(p, y, x);
	}
}

void	ft_up_frame(t_data *p, int y, int x)
{
	if (p->frame <= 10)
		ft_put_img(p, y, x, p->img->cjjump);
	else if (p->frame <= 30)
		ft_put_img(p, y, x, p->img->cjcrouch);
	else if (p->frame < 61)
	{
		p->frame = 0;
		p->ppl.dir = -1;
		ft_stay_frame(p, y, x);
	}
}

void	ft_down_frame(t_data *p, int y, int x)
{
	if (p->frame <= 10)
		ft_put_img(p, y, x, p->img->cjdown);
	else if (p->frame <= 30)
		ft_put_img(p, y, x, p->img->cjwait);
	else if (p->frame < 61)
	{
		p->frame = 0;
		p->ppl.dir = -1;
		ft_stay_frame(p, y, x);
	}
}
