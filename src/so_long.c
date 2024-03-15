/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:58:50 by wiljimen          #+#    #+#             */
/*   Updated: 2024/03/15 18:41:15 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// t_map	map_maker(char **argv, t_data *mapp)
// {
// 	void	*mlx;
// 	mlx = mlx_init();
	
// 	mapp->map.line = ft_strlen(argv[1]);
// 	mapp->map.fd = open(argv[1], O_RDONLY);
// 	mapp->map.row = get_num_rows(mapp->map.fd);
// 	mapp->map_ref = ft_calloc(sizeof(char *), mapp->map.row + 1);
// 	map_saver(argv, mapp);
// 	map_check(mapp);
// 	find_p(mapp);
// 	return (mapp->map);
// }

// int main(int argc, char **argv)
// {
// 	if (argc != 2)
// 	{
// 		printf("Error 404\n");
// 		return (0);
// 	}
// 	t_data	*mapp;
	
// 	mapp = ft_calloc(sizeof(t_data), 1);
// 	mapp->img = ft_calloc(1, sizeof(t_img));
// 	mapp->map = map_maker(argv, mapp);
// 	mapp->mlx = mlx_init();
// 	mapp->win = mlx_new_window(mapp->mlx, mapp->map.line * 52, mapp->map.row * 52, "so_long");
// 	img_to_window(mapp);
// 	mlx_key_hook(mapp->win, key_hook, mapp);
// 	mlx_loop(mapp->mlx);
// 	system("leaks -q so_long");
// 	return (0);
// }