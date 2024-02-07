/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:27:22 by wiljimen          #+#    #+#             */
/*   Updated: 2024/02/07 17:34:09 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_data;

typedef struct s_map
{
	int		row_count;
	int		all_size;
	int		col_count;
	char	*line;
	int		fd;
}			t_map;

typedef struct s_ptr
{
	t_map	map;

}			t_ptr;

typedef struct s_mapcnt
{
	char	player;
	char	wall;
	char	coin;
	char	exit;	
}				t_mapcnt;

int		map_size(char **argv);
void	ft_free(char **map, int i);
void	print_error(char *str);
int		valid_map(char **map, int width, int height);
int		map_check(char **map);

#endif