/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_raw_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnavarre <vnavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 07:57:17 by locharve          #+#    #+#             */
/*   Updated: 2025/01/14 11:03:30 by vnavarre         ###   ########.fr       */
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

t_err	t_cub_raw_parse(t_cub *cub)
{
	if (!t_cub_set_raw_args(cub, cub->raw)
		&& !t_cub_set_path(cub, cub->raw_args)
		&& !t_cub_set_rgb(cub, cub->raw_args)
		&& !t_cub_set_map(cub, cub->raw))
	{
		printf("okkkkkkkk\n");
	}
	return (cub->err);
}
