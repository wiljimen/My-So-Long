/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:37:23 by wiljimen          #+#    #+#             */
/*   Updated: 2023/09/28 12:57:33 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				len;
	unsigned char	c1;

	c1 = c;
	len = ft_strlen(s);
	while (s[len] != c1 && len != 0)
	{
		len--;
	}
	if (s[len] == c1)
		return ((char *)s + len);
	return (NULL);
}
