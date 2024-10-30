/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:22:04 by locharve          #+#    #+#             */
/*   Updated: 2023/11/06 11:39:32 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (src > dest)
			*((unsigned char *)dest + i) = *((unsigned char *)src + i);
		else
			*((unsigned char *)dest + (n - 1 - i))
				= *((unsigned char *)src + (n - 1 - i));
		i++;
	}
	return ((void *)dest);
}
