/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_raw_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 07:57:17 by locharve          #+#    #+#             */
/*   Updated: 2024/10/29 12:46:06 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	skip_incharset(char *str, char *set)
{
	int	i;

	i = 0;
	while (str && set && str[i] && is_in_str(set, str[i]) != -1)
		i++;
	return (i);
}

void	swap_str(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int	t_cub_set_raw_args(t_cub *cub, char **raw)
{
	char	**avtab;
	int	i;
	int	j;
	int	k;
	int	av_i;
	int	av_limit;

	i = 0;
	k = 0;
	avtab = strtab_init(6, "NO", "SO", "EA", "WE", "F", "C");
	if (!avtab)
		cub->err = _malloc;
	else
	{
		av_limit = strtab_size(avtab) - 1;
		while (av_limit >= 0 && raw && raw[i])
		{
			i += skip_empty_lines(&raw[i]);
			if (!raw[i])
			{
				cub->err = _empty;
				break ;
			}
			j = skip_incharset(raw[i], WHITESPACES);
			av_i = is_in_strtab(avtab, &raw[i][j]);
			if (av_i < 0)
			{
				cub->err = _invalidarg;
				break ;
			}
			else if (av_i > av_limit)
			{
				cub->err = _doublearg;
				break ;
			}
			cub->raw_args[k] = raw[i];
			swap_str(&avtab[av_i], &avtab[av_limit]);
			av_limit--;
			i++;
			k++;
		}
		strtab_free(avtab);
	}
	return (i);
}

t_err	t_cub_raw_parse(t_cub *cub)
{
	int	i;

	i = t_cub_set_raw_args(cub, cub->raw);
//	if (!cub->err)
//		i = t_cub_set_map(cub, &cub->raw[i]); //
	// checker les lignes restantes apres la map
	return (cub->err);
}