/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:19:43 by wiljimen          #+#    #+#             */
/*   Updated: 2023/12/18 14:14:46 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648 || nb == INT_MIN)
	{
		i += write(1, "-2", 2);
		i += ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		i += write(1, "-", 1);
		nb = -nb;
		i += ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	else
	{
		i += ft_putchar(nb + 48);
	}
	return (i);
}

int	ft_putunbr(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb > 9)
	{
		i += ft_putunbr(nb / 10);
		i += ft_putunbr(nb % 10);
	}
	else
		i += ft_putchar(nb + 48);
	return (i);
}
/*
#include <stdio.h>

int	main(void)
{	
	int n = 200;
	
	printf("\n%d", ft_putnbr(n));
}*/
