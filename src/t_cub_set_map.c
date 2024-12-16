/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_set_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:17:09 by locharve          #+#    #+#             */
/*   Updated: 2024/12/16 14:52:49 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	skip_param_lines(char **raw, char **avtab)
{
	int	i;
	int	j;
	int	av_limit;

	i = 0;
	av_limit = strtab_size(avtab) - 1;
	while (av_limit >= 0 && raw && raw[i])
	{
		i += skip_empty_lines(&raw[i]);
		j = skip_incharset(raw[i], WHITESPACES);
		if (is_in_strtab(avtab, &raw[i][j]) < 0)
			return (-1);
		av_limit--;
		i++;
	}
	i += skip_empty_lines(&raw[i]);
	return (i);
}

t_err	check_raw_map(char **map)
{
	int	i;
	int	j;
	int	nswe_count;

	i = 0;
	j = i;
	nswe_count = 0;
	while (map && map[i] && nswe_count <= 1
		&& !str_isonly(map[i], WHITESPACES))
	{
		if (str_contains(map[i], "NSWE"))
			nswe_count++;
		else if (!str_isonly(map[i], "01 \n"))
			break ;
		i++;
	}
	if (i == j || nswe_count != 1)
		return (_invalidmap);
	i += skip_empty_lines(&map[i]);
	if (map[i])
		return (_invalidmap);
	return (_ok);
}

t_err	set_map(char ***map, char **raw)
{
	int	size;
	int	i;

	size = 0;
	while (raw && raw[size] && !str_isonly(raw[size], WHITESPACES))
		size++;
	*map = ft_calloc(size + 1, sizeof(char *));
	if (!*map)
		return (_malloc);
	i = 0;
	while (i < size && raw && raw[i])
	{
		(*map)[i] = raw[i];
		i++;
	}
	return (_ok);
}

t_err	t_cub_set_map(t_cub *cub, char **raw)
{
	char	**avtab;
	int		i;

	avtab = strtab_init(6, "NO", "SO", "EA", "WE", "F", "C");
	if (!avtab)
		cub->err = _malloc;
	else
	{
		i = skip_param_lines(raw, avtab);
		if (i < 0)
			cub->err = _invalidf;
		else
			cub->err = check_raw_map(&raw[i]);
		if (!cub->err)
			cub->err = set_map(&cub->map, &raw[i]);
		if (!cub->err)
			cub->err = smooth_map(cub, &cub->map);
		if (!cub->err)
			cub->err = check_map(cub, &cub->map);
		if (!cub->err) {
			cub->height -= 2;
			cub->width -= 2;
			set_pos(&cub->player->px_x, &cub->player->px_y, cub->map);
		}
		strtab_free(avtab);
	}
	return (cub->err);
}
