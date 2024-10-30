/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:38:37 by locharve          #+#    #+#             */
/*   Updated: 2024/10/30 11:24:45 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_err	extension_check(char *filename, char *ext)
{
	char	*ptr;

	ptr = ft_strrchr(filename, '.');
	if (!ptr || ft_strcmp(ptr, ext))
		return (_badext);
	else
		return (_ok);
}

t_err	is_path_dir(char *path)
{
	int		fd;
	t_err	err;

	fd = open(path, O_DIRECTORY);
	if (fd == -1)
		err = _ok;
	else
	{
		err = _isdir;
		close(fd);
	}
	return (err);
}

t_err	t_cub_raw_init(t_cub *cub, char *path)
{
	t_str	*slist;
	int		fd;
	t_err	err;

	slist = NULL;
	err = extension_check(path, ".cub");
	if (!err)
		err = is_path_dir(path);
	if (err)
		return (err);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		err = _fileop;
	else
	{
		err = strlist_init(&slist, fd);
		if (!err)
			err = strlist_to_tab(slist, &cub->raw);
		strlist_free(slist);
		close(fd);
	}
	return (err);
}

t_err	parsing_cub(t_cub *cub, char *path)
{
	cub->err = t_cub_raw_init(cub, path);
	if (!cub->err)
		cub->err = t_cub_raw_parse(cub);
	return (cub->err);
}
