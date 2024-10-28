/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:32:21 by locharve          #+#    #+#             */
/*   Updated: 2023/11/06 11:35:05 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	divide_n(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static int	abs_val(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

static char	*fill_string(char *result, int n, int len, int minus)
{
	result[len] = '\0';
	len--;
	if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		result[len] = (abs_val(n % 10)) + 48;
		n /= 10;
		len--;
	}
	if (minus)
		result[0] = '-';
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	int		minus;

	len = 0;
	minus = 0;
	if (n < 0)
	{
		len = 1;
		minus = 1;
	}
	len += divide_n(n);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result = fill_string(result, n, len, minus);
	return (result);
}
