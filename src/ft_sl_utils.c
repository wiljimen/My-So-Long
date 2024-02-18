/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sl_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:11:39 by wiljimen          #+#    #+#             */
/*   Updated: 2024/02/13 14:44:22 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *str)
{
	ft_putendl_fd(str, 1);
	exit(0);
}

void	ft_free(char **map, int i)
{
	while (i >= 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
	print_error("Free done c:");
	exit(EXIT_FAILURE);
}

int	get_num_rows(int fd)
{
	char	*map;
	int		i;

	i = 0;
	if (fd < 0)
		return (0);
	map = get_next_line(fd);
	while (map)
	{
		i++;
		free(map);
		map = get_next_line(fd);
	}
	close(fd);
	return (i);
}

void	map_print(t_data *mapp)
{
	int	i;

	i = 0;
	while (mapp->map_ref[i])
	{
		printf("%s", mapp->map_ref[i]);
		i++;
	}
}
