/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 07:04:50 by locharve          #+#    #+#             */
/*   Updated: 2024/10/31 11:13:10 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strcpy_fill(char *dst, char *src, size_t len, char fill)
{
	size_t	i;

	i = 0;
	while (dst && src && src[i] && src[i] != '\n')
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = fill;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

t_err	make_map_rectangle(char ***dst, char **src, size_t len)
{
	int		i;

	i = 0;
	while (*dst && src && src[i])
	{
		(*dst)[i] = ft_calloc(len + 1, sizeof(char));
		if (!(*dst)[i])
		{
			strtab_free(*dst);
			return (_malloc);
		}
		(*dst)[i] = ft_strcpy_fill((*dst)[i], src[i], len, ' ');
		i++;
	}
	return (_ok);
}

void	set_pos(int *p_x, int *p_y, char **map)
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
	*p_x = x;
	*p_y = y;
}

t_err	smooth_map(t_cub *cub, char ***map)
{
	char	**new_map;

	cub->width = strtab_max_len(*map);
	cub->height = strtab_size(*map);
	new_map = ft_calloc(cub->height + 1, sizeof(char *));
	if (!new_map)
		return (_malloc);
	cub->err = make_map_rectangle(&new_map, *map, cub->width);
	if (!cub->err)
		set_pos(&cub->p_x, &cub->p_y, new_map);
	free(*map);
	*map = new_map;
	return (cub->err);
}
