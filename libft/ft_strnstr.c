/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:15:57 by locharve          #+#    #+#             */
/*   Updated: 2024/10/28 11:49:47 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_big;
	size_t	len_little;

	if (big == NULL && len == 0)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	len_big = ft_strlen(big);
	len_little = ft_strlen(little);
	if (len_little <= len_big)
	{
		while (i < len && len - i >= len_little && big[i] != '\0')
		{
			if (big[i] == little[0] && ft_strcmp(&big[i], little) == 0)
				return ((char *)big + i);
			i++;
		}
	}
	return (NULL);
}
