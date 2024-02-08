/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:27:22 by wiljimen          #+#    #+#             */
/*   Updated: 2024/02/08 18:04:30 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

	typedef struct s_map
	{
		int		row;
		int		line;
		int		fd;

	}			t_map;

	typedef struct s_mapcnt
	{
		int	player;
		int	coin;
		int	exit;	
	}				t_mapcnt;

	typedef struct s_data
	{
		void		*mlx_ptr;
		void		*win_ptr;
		char		**map_ref;
		t_map		map;
		t_mapcnt	*mapcnt;
	}			t_data;

void	ft_free(char **map, int i);
void	print_error(char *str);
void	ft_error(t_data *mlx);
int		get_num_rows(int fd);
void	map_rectangle(char **map, int width, int height);
void	map_chr_check(t_data *mapp);

#endif