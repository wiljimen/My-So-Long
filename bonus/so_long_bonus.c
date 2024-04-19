/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:51:43 by wiljimen          #+#    #+#             */
/*   Updated: 2024/04/19 17:59:38 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	ft_is_readable(char *file)
{
	int	fd;
	int	flag;

	fd = open(file, O_RDONLY);
	if (read(fd, 0, 0) < 0)
		flag = false;
	else
		flag = true;
	close(fd);
	return (flag);
}

t_map	map_maker(char **argv, t_data *mapp)
{
	mapp->map.line = ft_strlen(argv[1]);
	mapp->map.fd = open(argv[1], O_RDONLY);
	mapp->map.row = get_num_rows(mapp->map.fd);
	mapp->map_ref = ft_calloc(sizeof(char *), mapp->map.row + 1);
	map_saver(argv, mapp);
	map_check(mapp);
	find_p(mapp);
	ft_printf(CLEAR "Moves: %d\n", mapp->ppl.moves);
	mapp->mlx = mlx_init();
	mapp->win = mlx_new_window(mapp->mlx, mapp->map.line * 52,
			mapp->map.row * 52, "so_long");
	fill_bckgnd(mapp);
	return (mapp->map);
}

void	check_args(int argc, char **argv)
{
	char	*ber;

	if (argc == 1)
		print_error(RED "Error, not map found");
	if (argc != 2)
		print_error(RED "More or less arguments than 2");
	if (ft_is_readable(argv[1]) == false)
		print_error(RED "Empty file or not readable");
	if (ft_strrchr(argv[1], '.'))
	{
		ber = ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]));
		if (ft_strlen(ber) != 4)
			print_error(RED "Bad extension, try with a .ber file");
		if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber",
				max_len(ft_strrchr(argv[1], '.'), ".ber")) != 0)
			print_error(RED "Bad extension, try with a .ber file");
		if (!ft_strncmp(argv[1], ".ber", ft_strlen(argv[1])))
			print_error(RED "There's nothing before .ber");
	}
	else
		print_error(RED "Bad extension, try with a .ber file");
}

int	ft_frames(t_data *mapp)
{
	mlx_clear_window(mapp->mlx, mapp->win);
	fill_bckgnd(mapp);
	img_to_window_bonus(mapp);
	mapp->frame++;
	if (mapp->frame >= 60)
		mapp->frame = 0;
	mapp->frame_police++;
	if (mapp->frame_police >= 60)
		mapp->frame_police = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*mapp;

	check_args(argc, argv);
	mapp = ft_calloc(sizeof(t_data), 1);
	if (!mapp)
		print_error("Bad map calloc");
	mapp->img = ft_calloc(1, sizeof(t_img));
	if (!mapp->img)
		print_error("Bad image calloc");
	mapp->map = map_maker(argv, mapp);
	mapp->img = image_put(mapp);
	img_to_window_bonus(mapp);
	mlx_hook(mapp->win, KEY_CLOSE_WIN, 0, x_pressed, mapp);
	mlx_key_hook(mapp->win, key_hook, mapp);
	mlx_loop_hook(mapp->mlx, ft_frames, mapp);
	mlx_loop(mapp->mlx);
	return (0);
}
