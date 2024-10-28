/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:51:29 by locharve          #+#    #+#             */
/*   Updated: 2024/10/16 08:54:36 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!ft_isascii(c))
		return ((char *)s);
	while (s && s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (s && s[i] == c)
		return ((char *)s + i);
	return (NULL);
}
*/
// GNL
char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (s)
	{
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		if (s[i] == c)
			return ((char *)&s[i + 1]);
	}
	return (NULL);
}
