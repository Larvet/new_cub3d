/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:02:21 by locharve          #+#    #+#             */
/*   Updated: 2023/11/06 11:47:14 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_int(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static int	is_in_str(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	trim_strlen(char const *str, char const *set, int *start, int *end)
{
	while (is_in_str(set, str[*start]))
		*start += 1;
	if (str[*start] == '\0')
		return (0);
	while (is_in_str(set, str[*end]))
		*end -= 1;
	*end += 1;
	return (*end - *start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		start;
	int		end;
	int		len_trim;
	int		i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen_int(s1) - 1;
	len_trim = trim_strlen(s1, set, &start, &end);
	trim = (char *)malloc((len_trim + 1) * sizeof(char));
	if (!trim)
		return (NULL);
	i = 0;
	while (i < len_trim)
	{
		trim[i] = s1[start];
		i++;
		start++;
	}
	trim[i] = '\0';
	return (trim);
}
