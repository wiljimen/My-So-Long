/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:58:50 by wiljimen          #+#    #+#             */
/*   Updated: 2024/03/18 19:10:41 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

void	check_args(int argc, char **argv)
{
	char	*ber;

	if (argc == 1)
		print_error("Error, not map found");
	if (argc != 2)
		print_error("More or less arguments than 2");
	if (ft_strrchr(argv[1], '.'))
	{
		ber = ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]));
		if (ft_strlen(ber) != 4)
			print_error("Bad extension, try with a .ber file");
		if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber",
				max_len(ft_strrchr(argv[1], '.'), ".ber")) != 0)
			print_error("Bad extension, try with a .ber file");
		if (!ft_strncmp(argv[1], ".ber", ft_strlen(argv[1])))
			print_error("There's nothing before .ber, try with another file");
	}
	else
		print_error("Bad extension, try with a .ber file");
}

int	main(int argc, char **argv)
{
	t_data	*mapp;

	check_args(argc, argv);
	mapp = ft_calloc(sizeof(t_data), 1);
	mapp->img = ft_calloc(1, sizeof(t_img));
	mapp->map = map_maker(argv, mapp);
	mapp->mlx = mlx_init();
	mapp->win = mlx_new_window(mapp->mlx, mapp->map.line * 52,
			mapp->map.row * 52, "so_long");
	img_to_window(mapp);
	mlx_hook(mapp->win, KEY_CLOSE_WIN, 0, x_pressed, mapp);
	mlx_key_hook(mapp->win, key_hook, mapp);
	mlx_loop(mapp->mlx);
	system("leaks -q so_long");
	return (0);
}
