/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtab_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:25:21 by locharve          #+#    #+#             */
/*   Updated: 2024/11/05 10:40:40 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	skip_empty_lines(char **strtab)
{
	int	i;

	i = 0;
	while (strtab && strtab[i] && str_isonly(strtab[i], WHITESPACES))
		i++;
	return (i);
}

int	is_in_strtab(char **tab, char *str)
{
	int	i;

	i = 0;
	while (tab && str && tab[i]
		&& ft_strncmp(str, tab[i], ft_strlen(tab[i])))
		i++;
	if (tab && i && !tab[i])
		i = -1;
	else if (tab && str && tab[i]
		&& ft_strncmp(str, tab[i], ft_strlen(tab[i]))
		&& is_in_str(WHITESPACES, str[ft_strlen(tab[i])]) < 0)
		i = -2;
	return (i);
}

char	**strtab_replace(char **strtab, char to_find, char to_replace)
{
	int	i;
	int	j;

	i = 0;
	while (strtab && strtab[i])
	{
		j = 0;
		while (strtab[i][j])
		{
			if (strtab[i][j] == to_find)
				strtab[i][j] = to_replace;
			j++;
		}
		i++;
	}
	return (strtab);
}
