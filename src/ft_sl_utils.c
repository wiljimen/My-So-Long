/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sl_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:11:39 by wiljimen          #+#    #+#             */
/*   Updated: 2024/02/08 12:56:41 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write (fd, &s[i], 1);
		i++;
	}
	write (fd, "\n", 1);
}

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

void	ft_error(t_data *mlx)
{
	print_error("Some characters are wrong, ");
	print_error("try with another map");
	exit(EXIT_FAILURE);
}