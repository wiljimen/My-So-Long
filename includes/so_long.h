/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:27:22 by wiljimen          #+#    #+#             */
/*   Updated: 2024/03/18 19:10:19 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

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
	int coin_left;
	int	exit_count;
}		t_mapcnt;

// All player movements, including how many moves
// have we done.
typedef struct s_ppl
{
	int	moves;
	int	py;
	int	px;
}		t_ppl;

// All paths
typedef struct s_img
{
	void	*character;
	void	*coin;
	void	*exit;
	void	*wall;
	void	*background;
	int		width;
	int		height;
}			t_img;

// All data required, include map and mapcontent
typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**map_ref;
	char		**map_cpy;
	t_map		map;
	t_mapcnt	mapcnt;
	t_ppl		ppl;
	t_img		*img;
}				t_data;

//All Sprites 
# define PLAYER "./sprites/CJ-PARAO.xpm";
# define FLOOR "./sprites/FLOOR.xpm";
# define CRATE "./sprite/CRATE.xpm";
# define PORSCHE "./sprite/Porsche.xpm";
# define MONEY "./sprite/Money.xpm";

// All Keycodes
#define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_UP 126
#define KEY_LEFT 123
#define KEY_DOWN 125
#define KEY_RIGHT 124
#define KEY_CLOSE_WIN 17

// All Colors

#define RED  "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"

void	ft_free(char **map, int i, char *str);
void	print_error(char *str);
void	ft_error(t_data *mlx);
int		get_num_rows(int fd);
size_t	max_len(char *s1, char *s2);
void	map_rectangle(char **map, int width, int height);
void	map_content(t_data *mapp);
void	map_chr_check(t_data *mapp);
void	map_saver(char **argv, t_data *mapp);
void	map_check(t_data *mapp);
void	ft_coin_left(t_data *mapp);
void	floodfill_map_coin(t_data *mapp, int y, int x);
void	valid_exit(t_data *mapp, int y, int x);
void	map_print(t_data *mapp);
t_map	map_maker(char **argv, t_data *mapp);
void	ft_left_move(t_data *P);
void	ft_up_move(t_data *P);
void	ft_down_move(t_data *P);
void	ft_right_move(t_data *P);
t_img	*image_put(t_data *mapp);
void	which_image(t_data *mapp, int i, int j);
void	img_to_window(t_data *mapp);
void	fill_bckgnd(t_data *mapp);
void	find_p(t_data *mapp);
int		key_hook(int keycode, t_data *mapp);
int		x_pressed(t_data *mapp);

#endif