/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtab_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 07:29:36 by locharve          #+#    #+#             */
/*   Updated: 2024/10/29 12:46:15 by locharve         ###   ########.fr       */
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

	printf("str = %s\n", str);
	i = 0;
	while (tab && str && tab[i]
		&& ft_strncmp(str, tab[i], ft_strlen(tab[i])))
		i++;
	if (tab && i && !tab[i])
		i = -1;
	else if (tab && str && tab[i]
		&& ft_strncmp(str, tab[i], ft_strlen(tab[i]))
		&& !is_in_str(WHITESPACES, str[ft_strlen(tab[i])]))
		i = -2;
	return (i);
}

size_t	strtab_max_len(char **strtab)
{
	size_t	i;
	size_t	max;
	size_t	tmp;

	i = 0;
	max = 0;
	while (strtab && strtab[i])
	{
		tmp = ft_strlen(strtab[i]);
		if (str_contains(strtab[i], "\n"))
			--tmp;
		if (max < tmp)
			max = tmp;
		i++;
	}
	return (max);
}

size_t	strtab_size(char **tab)
{
	size_t	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

size_t	strtab_print(char **tab)
{
	ssize_t	tmp;
	size_t	count;
	size_t	len;
	int		i;

	count = 0;
	i = 0;
	while (tab && tab[i])
	{
		len = ft_strlen(tab[i]);
		tmp = write(1, tab[i], len);
		if (tmp < 0)
			break ;
		if (tab[i][len - 1] != '\n')
		{
			count += tmp;
			tmp = write(1, "\n", 1);
			if (tmp < 0)
				break ;
			count += tmp;
		}
		i++;
	}
	return (count);
}

void	strtab_free(char **strtab)
{
	int	i;

	i = 0;
	while (strtab && strtab[i])
	{
		free(strtab[i]);
		i++;
	}
	if (strtab)
		free(strtab);
}

char	**strtab_init(size_t size, ...)
{
	va_list	p;
	char	**strtab;
	size_t	i;

	strtab = ft_calloc(size + 1, sizeof(char *));
	if (strtab)
	{
		va_start(p, size);
		i = -1;
		while (++i < size)
		{
			strtab[i] = ft_strdup(va_arg(p, char *));
			if (!strtab[i])
			{
				strtab_free(strtab);
				break ;
			}
		}
		va_end(p);
	}
	return (strtab);
}
