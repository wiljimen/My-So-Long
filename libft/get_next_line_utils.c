/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:33:56 by wiljimen          #+#    #+#             */
/*   Updated: 2023/11/20 12:48:13 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_aux(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin_aux(char const *s1, const char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen_aux(s1) + ft_strlen_aux(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	c1;

	c1 = c;
	i = 0;
	while (s[i] != c1 && s[i] != '\0')
	{
		i++;
	}
	if (s[i] == c1)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen_aux(s1);
	copy = malloc(sizeof(char) * srclen + 1);
	if (copy == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		copy[i] = (*(char *)&s1[i]);
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	slen = ft_strlen_aux(s);
	if (len > slen - start)
		len = slen - start;
	if (start >= slen)
		return (ft_strdup(""));
	sub = malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
