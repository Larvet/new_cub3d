/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnavarre <vnavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 07:04:50 by locharve          #+#    #+#             */
/*   Updated: 2024/12/11 15:24:44 by vnavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*make_str_with_char(size_t len, char c)
{
	char	*dst;
	size_t	i;

	dst = ft_calloc(len + 1, sizeof(char));
	if (dst)
	{
		i = 0;
		while (i < len)
		{
			dst[i] = c;
			i++;
		}
	}
	return (dst);
}

char	*ft_strcpy_fill(char *dst, char *src, size_t len, char fill)
{
	size_t	i;

	i = 0;
	dst[i] = ' ';
	while (dst && src && src[i] && src[i] != '\n')
	{
		dst[i + 1] = src[i];
		i++;
	}
	while (i < len - 1)
	{
		dst[i + 1] = fill;
		i++;
	}
	dst[i + 1] = '\0';
	return (dst);
}

t_err	make_map_rectangle(char ***dst, char **src, size_t len)
{
	int		i;

	i = 0;
	(*dst)[i] = make_str_with_char(len, ' ');
	if (!(*dst)[i])
		return (_malloc);
	while (*dst && src && src[i])
	{
		(*dst)[i + 1] = ft_calloc(len + 1, sizeof(char));
		if (!(*dst)[i + 1])
			return (_malloc);
		(*dst)[i + 1] = ft_strcpy_fill((*dst)[i + 1], src[i], len, ' ');
		i++;
	}
	(*dst)[i + 1] = make_str_with_char(len, ' ');
	if (!(*dst)[i + 1])
		return (_malloc);
	return (_ok);
}

void	set_pos(t_cub *cub, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map && map[y] && !str_contains(map[y], "NSWE"))
		y++;
	x = 0;
	while (map && map[y] && map[y][x]
		&& is_in_str("NSWE", map[y][x]) < 0)
		x++;
	fill_p_angle(cub, map[y][x]);
	cub->player->x = x;
	cub->player->y = y;
	cub->player->px_x = x * TILE_SIZE + TILE_SIZE / 2;
	cub->player->px_y = y * TILE_SIZE + TILE_SIZE / 2;
}

t_err	smooth_map(t_cub *cub, char ***map)
{
	char	**new_map;

	cub->width = strtab_max_len(*map) + 2;
	cub->height = strtab_size(*map) + 2;
	new_map = ft_calloc(cub->height + 1, sizeof(char *));
	if (!new_map)
		return (_malloc);
	cub->err = make_map_rectangle(&new_map, *map, cub->width);
	if (!cub->err)
		set_pos(cub, new_map);
	free(*map);
	*map = new_map;
	return (cub->err);
}
