/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sl_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:11:39 by wiljimen          #+#    #+#             */
/*   Updated: 2024/03/19 15:42:37 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

size_t	max_len(char *s1, char *s2)
{
	if (ft_strlen(s1) > ft_strlen(s2))
		return (ft_strlen(s1));
	else
		return (ft_strlen(s2));
}

void	print_error(char *str)
{
	ft_putendl_fd(str, 1);
	exit(EXIT_FAILURE);
}

void	ft_free(char **map, char *str)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	ft_putstr_fd(str, 1);
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
