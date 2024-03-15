/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:09:21 by wiljimen          #+#    #+#             */
/*   Updated: 2024/03/15 18:57:33 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_rectangle(char **map, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	// if (height == 0 || (int)ft_strlen(map[0]) != width)
	// 	ft_free(map, height, "Bad length");
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if ((i == 0 || i == height - 1) && map[i][j] != '1'
				&& map[i][j] != '\n')
				ft_free(map, height, "Bad top or bottom borders");
			else if ((j == 0 || j == width - 1) && map[i][j] != '1'
					&& map[i][j] != '\n')
				ft_free(map, height, "Bad lateral borders");
			j++;
		}
		if ((int)ft_strlen(map[0]) != (int)ft_strlen(map[i]))
			ft_free(map, height, "Map isn't rectangle");
		i++;
	}
}

void	map_chr_check(t_data *mapp)
{
	int	i;
	int	j;

	i = 0;
	while (mapp->map_ref[i])
	{
		j = 0;
		while (mapp->map_ref[i][j])
		{
			if(mapp->map_ref[i][j] != 'P' && mapp->map_ref[i][j] != 'C'
				&& mapp->map_ref[i][j] != '1' && mapp->map_ref[i][j] != '0'
				&& mapp->map_ref[i][j] != 'E' && mapp->map_ref[i][j] != '\n')
				{
				ft_free(mapp->map_ref, i, "Bad characthers");
				}
			j++;
		}
		i++;
	}
}

void	map_content(t_data *mapp)
{
	int	i;
	int	j;

	i = 0;
	map_chr_check(mapp);
	while (mapp->map_ref[i])
	{
		j = 0;
		while (mapp->map_ref[i][j])
		{
			if (mapp->map_ref[i][j] == 'P')
				mapp->mapcnt.player += 1;
			else if (mapp->map_ref[i][j] == 'E')
				mapp->mapcnt.exit += 1;
			else if (mapp->map_ref[i][j] == 'C')
				mapp->mapcnt.coin += 1;
			j++;
		}
		i++;
	}
	if (mapp->mapcnt.exit != 1 || mapp->mapcnt.player != 1)
		ft_free(mapp->map_ref, i, "Player or Exit not equal than 1");
	if (mapp->mapcnt.coin < 1)
		ft_free(mapp->map_ref, i, "Coins less than 1");
}

void	map_saver(char **argv, t_data *mapp)
{
	int		i;
	char	*aux;
	char	*temp;

	i = 0;
	mapp->map.fd = open(argv[1], O_RDONLY);
	aux = get_next_line(mapp->map.fd);
	temp = ft_calloc(ft_strlen(aux), sizeof(char *));
	while (aux)
	{
		temp = ft_strjoin(temp, aux);
		free(aux);
		aux = get_next_line(mapp->map.fd);
	}
	mapp->map_ref = ft_split(temp, '\n');
	mapp->map_cpy = ft_split(temp, '\n');
	close(mapp->map.fd);
}

void	map_check(t_data *mapp)
{
	mapp->mapcnt.player = 0;
	mapp->mapcnt.coin = 0;
	mapp->mapcnt.exit = 0;
	mapp->map.line = ft_strlen(mapp->map_ref[0]);
	map_rectangle(mapp->map_ref, mapp->map.line, mapp->map.row);
	map_content(mapp);
	find_p(mapp);
	valid_exit(mapp, mapp->ppl.py, mapp->ppl.px);
}

t_map	map_maker(char **argv, t_data *mapp)
{
	void	*mlx;
	mlx = mlx_init();
	
	mapp->map.line = ft_strlen(argv[1]);
	mapp->map.fd = open(argv[1], O_RDONLY);
	mapp->map.row = get_num_rows(mapp->map.fd);
	mapp->map_ref = ft_calloc(sizeof(char *), mapp->map.row + 1);
	map_saver(argv, mapp);
	map_check(mapp);
	find_p(mapp);
	return (mapp->map);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error 404\n");
		return (0);
	}
	t_data	*mapp;
	
	mapp = ft_calloc(sizeof(t_data), 1);
	mapp->img = ft_calloc(1, sizeof(t_img));
	mapp->map = map_maker(argv, mapp);
	mapp->mlx = mlx_init();
	mapp->win = mlx_new_window(mapp->mlx, mapp->map.line * 52, mapp->map.row * 52, "so_long");
	img_to_window(mapp);
	mlx_key_hook(mapp->win, key_hook, mapp);
	mlx_loop(mapp->mlx);
	system("leaks -q so_long");
	return (0);
}
