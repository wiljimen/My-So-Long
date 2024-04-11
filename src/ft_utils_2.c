/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:22:42 by wiljimen          #+#    #+#             */
/*   Updated: 2024/04/11 16:38:59 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_end_message(t_data *p, char *str)
{
	p->ppl.moves++;
	ft_printf("Moves: %d\n", p->ppl.moves);
	ft_putendl_fd(str, 1);
	ft_putchar('\n');
}

void	ft_protect_malloc(char *map)
{
	if (!map)
		free(map);
}

char	**ft_protect(char **mapp, char *temp)
{
	mapp = ft_split(temp, '\n');
	if (!mapp)
		ft_free(mapp, "Free done");
	return (mapp);
}

void	ft_open_check(int file)
{
	if (file < 0)
	{
		close(file);
		exit(EXIT_FAILURE);
	}
}
