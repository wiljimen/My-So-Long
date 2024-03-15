/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:19:36 by wiljimen          #+#    #+#             */
/*   Updated: 2023/12/18 14:12:14 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
		return (i);
	}
}
/*
#include <stdio.h>

int	main(void)
{
	char s;
	char *str;

	s = 's';
	str = "Hola";
	ft_putchar(s);
	printf("\n%c\n", s);
	ft_putstr(str);
	printf("\n%s\n", str);

	return (0);
}*/
