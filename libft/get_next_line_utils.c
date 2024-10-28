/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:29:58 by locharve          #+#    #+#             */
/*   Updated: 2024/10/08 06:29:11 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	if (s)
	{
		i = 0;
		while (i < n)
		{
			*((unsigned char *)s + i) = 0;
			i++;
		}
	}
	return ;
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	if (str)
	{
		i = 0;
		while (str[i] && str[i] != c)
			i++;
		if (str[i] == c)
			return (&str[i + 1]);
	}
	return (NULL);
}

char	*ft_strdup(char *src)
{
	char	*dst;
	size_t	len;
	int		i;

	dst = NULL;
	if (src)
	{
		len = ft_strlen(src);
		dst = (char *)malloc((len + 1) * sizeof(char));
		if (!dst)
			return (NULL);
		i = 0;
		while (src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (dst);
}
*/
char	*ft_strcat_dst(char *dst, char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}
