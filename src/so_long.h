/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:27:22 by wiljimen          #+#    #+#             */
/*   Updated: 2024/01/29 15:26:17 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_data;

typedef struct s_map
{
	int		row;
	int		col;
	char	**line;
	int		fd;
}			t_map;

typedef struct s_mapcnt
{
	char	player;
	char	wall;
	char	coin;
	char	exit;	
}				t_mapcnt;

int		valid_map(char **map, int width, int num);
int		map_size(char **argv);
void	ft_free(char **map, int i);
void	print_error(char *str);

#endif