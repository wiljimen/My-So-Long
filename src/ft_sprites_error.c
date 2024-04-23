/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:28:43 by wiljimen          #+#    #+#             */
/*   Updated: 2024/04/23 12:53:51 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error_sprite(void *sprite, char *str)
{
	if (!sprite)
	{
		ft_printf("%s\n", str);
		exit(EXIT_FAILURE);
	}
}