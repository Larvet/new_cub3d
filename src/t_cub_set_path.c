/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_set_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:12:53 by locharve          #+#    #+#             */
/*   Updated: 2024/10/30 11:33:06 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_err	set_path(char **to_set, char **raw_args, char *to_cmp)
{
	int		i;
	int		j;

	i = 0;
	while (raw_args && raw_args[i])
	{
		j = skip_incharset(raw_args[i], WHITESPACES);
		if (!ft_strncmp(&raw_args[i][j], to_cmp, ft_strlen(to_cmp)))
			break ;
		i++;
	}
	j += 2;
	j += skip_incharset(&raw_args[i][j], WHITESPACES);
	*to_set = ft_strdup(&raw_args[i][j]);
	if (!*to_set)
		return (_malloc);
	else
		return (_ok);
}

t_err	t_cub_set_path(t_cub *cub, char **raw_args)
{
	char	**nswe;
	int		i;

	nswe = strtab_init(4, "NO", "SO", "WE", "EA");
	if (!nswe)
		cub->err = _malloc;
	else
	{
		i = 0;
		while (nswe[i])
		{
			cub->err = set_path(&cub->path[i], raw_args, nswe[i]);
			if (cub->err)
				break ;
			i++;
		}
		strtab_free(nswe);
	}
	return (cub->err);
}
