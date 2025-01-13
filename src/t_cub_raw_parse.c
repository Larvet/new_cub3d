/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_raw_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 07:57:17 by locharve          #+#    #+#             */
/*   Updated: 2024/10/31 14:27:02 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	swap_str(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

t_err	t_cub_get_args(t_cub *cub, char **raw, char **avtab, int av_limit)
{
	int	i;
	int	j;
	int	k;
	int	av_i;

	i = 0;
	k = 0;
	while (av_limit >= 0 && raw && raw[i])
	{
		i += skip_empty_lines(&raw[i]);
		if (!raw[i])
			return (_empty);
		j = skip_incharset(raw[i], WHITESPACES);
		av_i = is_in_strtab(avtab, &raw[i][j]);
		if (av_i < 0 || av_i > av_limit)
			return (_invalidf);
		cub->raw_args[k] = raw[i];
		swap_str(&avtab[av_i], &avtab[av_limit]);
		av_limit--;
		i++;
		k++;
	}
	return (_ok);
}

t_err	t_cub_set_raw_args(t_cub *cub, char **raw)
{
	char	**avtab;
	int		av_limit;

	avtab = strtab_init(6, "NO", "SO", "EA", "WE", "F", "C");
	if (!avtab)
		cub->err = _malloc;
	else
	{
		av_limit = strtab_size(avtab) - 1;
		cub->err = t_cub_get_args(cub, raw, avtab, av_limit);
		strtab_free(avtab);
	}
	return (cub->err);
}

double	get_dir_vector(char** map)
{
	int	i;
	int	j;
	char	c;

	i = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j] && is_in_str("NSWE", map[i][j]) < 0)
			j++;
		if (map[i][j])
			break ;
		i++;
	}
	c = map[i][j];
	if (c == 'N')
		return (N_DIR); // (PI / 2);
	else if (c == 'S')
		return (S_DIR); // (3 * PI / 2);
	else if (c == 'W')
		return (W_DIR); // (PI);
	else
		return (E_DIR); // (2 * PI);
}

t_err	t_cub_raw_parse(t_cub *cub)
{
	if (!t_cub_set_raw_args(cub, cub->raw)
		&& !t_cub_set_path(cub, cub->raw_args)
		&& !t_cub_set_rgb(cub, cub->raw_args)
		&& !t_cub_set_map(cub, cub->raw))
	{
		cub->player->dir_vector = get_dir_vector(cub->map);
		printf("okkkkkkkk\tplayer dir = %f\n", cub->player->dir_vector); //
	}
	return (cub->err);
}
