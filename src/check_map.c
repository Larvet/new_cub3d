/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:59:07 by locharve          #+#    #+#             */
/*   Updated: 2025/01/14 13:46:03 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	flood_fill(t_cub *cub, char ***map, int x, int y)
{
	if (y < 0 || y >= (int)cub->height
		|| x < 0 || x >= (int)cub->width)
		return (1);
	else if ((*map)[y][x] == '1' || (*map)[y][x] == 'X')
		return (1);
	else if ((*map)[y][x] == ' ')
	{
		(*map)[y][x] = 'X';
		return (flood_fill(cub, map, x - 1, y)
			&& flood_fill(cub, map, x + 1, y)
			&& flood_fill(cub, map, x, y - 1)
			&& flood_fill(cub, map, x, y + 1));
	}
	else
		return (0);
}

t_err	crop_map(char ***map, size_t width, size_t height)
{
	char	**new_map;
	size_t	i;

	new_map = ft_calloc(height - 2 + 1, sizeof(char *));
	if (!new_map)
		return (_malloc);
	i = 0;
	while (i + 1 < height - 1 && (*map)[i + 1])
	{
		new_map[i] = ft_strndup(&((*map)[i + 1][1]), width - 2);
		if (!new_map[i])
			break ;
		i++;
	}
	strtab_free(*map);
	*map = new_map;
	if (i + 1 < height - 1)
		return (_malloc);
	return (_ok);
}

t_err	check_map(t_cub *cub, char ***map)
{
	int	y;
	int	x;
	int	tmp;

	y = 0;
	while ((*map)[y])
	{
		x = skip_outcharset((*map)[y], " ");
		while ((*map)[y][x])
		{
			tmp = flood_fill(cub, map, x, y);
			while (tmp < 0)
				tmp = flood_fill(cub, map, x, y);
			if (!tmp)
				return (_unclosedmap);
	//		if ((*map)[y][x] && !flood_fill(cub, map, x, y))
	//			return (_unclosedmap);
			x += skip_outcharset(&(*map)[y][x], WHITESPACES);
		}
		y++;
	}
	*map = strtab_replace(*map, 'X', '0');
	return (crop_map(map, cub->width, cub->height));
}
