/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_set_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:12:53 by locharve          #+#    #+#             */
/*   Updated: 2025/01/14 14:52:48 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_err	crop_and_check_path(char **new_path, char *raw_path)
{
	int		i;
	int		j;
	int		fd;

	i = 0;
	while (raw_path && raw_path[i] && is_in_str(WHITESPACES, raw_path[i]) < 0)
		i++;
	j = i;
	while (raw_path && raw_path[j] && is_in_str(WHITESPACES, raw_path[j]) >= 0)
		j++;
	if (raw_path[j] && raw_path[j] != '\n')
		return (_badpath);
	*new_path = ft_strndup(raw_path, i);
	if (!new_path)
		return (_malloc);
	if (extension_check(new_path, ".xpm"))
		return (_badext);
	if (is_path_dir(*new_path))
		return (_isdir);
	fd = open(*new_path, O_RDONLY);
	if (fd == -1)
		return (_fileop);
	close(fd);
	return (_ok);
}

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
	if (is_in_str(WHITESPACES, raw_args[i][j]) < 0)
		return (_missingspace);
	j += skip_incharset(&raw_args[i][j], WHITESPACES);
	return (crop_and_check_path(to_set, &raw_args[i][j]));
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
