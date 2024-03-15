/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:04:57 by wiljimen          #+#    #+#             */
/*   Updated: 2023/12/18 15:01:51 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_counter(va_list args, const char type)
{
	int		counter;

	counter = 0;
	if (type == 'c')
		counter += ft_putchar(va_arg(args, int));
	else if (type == 's')
		counter += ft_putstr(va_arg(args, char *));
	else if (type == 'p')
		counter += ft_put_ptr(va_arg(args, int *));
	else if (type == 'd' || type == 'i')
		counter += ft_putnbr(va_arg(args, int));
	else if (type == 'u')
		counter += ft_putunbr(va_arg(args, unsigned int));
	else if (type == 'x')
		counter += ft_hexa_lower(va_arg(args, unsigned int));
	else if (type == 'X')
		counter += ft_hexa_upper(va_arg(args, unsigned int));
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
				counter += write(1, "%%", 1);
			else
				counter += ft_printf_counter(args, str[i]);
		}
		else
			counter += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (counter);
}

/*
#include <stdio.h>
int	main(void)
{
	char c = 'S';
	char *str = "Hola";
	int	n = 7;
	int nnegative = -7;
	unsigned int num = 123456;
	int *ptr = &n;
	
	
	ft_printf("Mi Printf: c: %c %%: %% s: %s i: %i d: %d u: %u
	x: %x X: %X p: %p\n\n", c, str, n, nnegative, num, num, num, ptr);
	printf("Printf Original: c: %c %%: %% s: %s i: %i d: %d u: %u
	x: %x X: %X p: %p\n", c, str, n, nnegative, num, num, num, ptr);
	ft_printf("%d", INT_MIN);
	return(0);
}*/
