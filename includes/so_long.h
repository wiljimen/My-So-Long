/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:27:22 by wiljimen          #+#    #+#             */
/*   Updated: 2024/02/28 16:39:01 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"

// Map size
typedef struct s_map
{
	int		row;
	int		line;
	int		fd;
}			t_map;

// Map content
typedef struct s_mapcnt
{
	int	player;
	int	coin;
	int	exit;
}		t_mapcnt;

// All player movements, including how many moves
// have we done.
typedef struct s_ppl
{
	int	moves;
	int	player_y;
	int	player_x;
}		t_ppl;

// All paths
typedef struct s_img
{
	void	*character;
	void	*coin;
	void	*exit;
	void	*wall;
	void	*background;
	int		height;
	int		width;
}			t_img;

// All data required, include map and mapcontent
typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**map_ref;
	t_map		map;
	t_mapcnt	mapcnt;
	t_ppl		ppl;
	t_img		img;
}				t_data;

#define PLAYER "./sprites/CJ-PARAO.xpm";
#define FLOOR "./sprites/FLOOR.xpm";
#define CRATE "./sprite/Crate-Pro.xpm";
#define PORSCHE "./sprite/Porsche.xpm";

void	ft_free(char **map, int i);
void	print_error(char *str);
void	ft_error(t_data *mlx);
int		get_num_rows(int fd);
void	map_rectangle(char **map, int width, int height);
void	map_chr_check(t_data *mapp);
void	map_saver(char **argv, t_data *mapp);
void	map_check(t_data *mapp);
void	map_print(t_data *mapp);
t_map	map_maker(char **argv, t_data *mapp);
void	ft_left_move(t_data *P);
void	ft_up_move(t_data *P);
void	ft_down_move(t_data *P);
void	ft_right_move(t_data *P);
void	image_put(void *mlx);
void	which_image(t_data *mapp, int i, int j);
void	img_to_window(t_data *mapp);
void	fill_bckgnd(t_data *mapp);
void	find_p(t_data *mapp);

#endif