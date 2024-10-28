/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:38:37 by locharve          #+#    #+#             */
/*   Updated: 2024/10/28 13:19:07 by locharve         ###   ########.fr       */
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
	int	fd;
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

t_err	strlist_init(t_str **list, int fd)
{
	t_str	*node;
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		node = t_str_new(line);
		if (!node)
			return (_malloc);
		t_str_addback(list, node);
		line = get_next_line(fd);
	}
	return (_ok);
}

t_err	strlist_to_tab(t_str *list, char ***tab)
{
	t_str	*head;
	size_t	list_size;
	size_t	i;

	head = list;
	list_size = t_str_listsize(list);
	*tab = ft_calloc(list_size + 1, sizeof(char *));
	if (!*tab)
		return (_malloc);
	i = 0;
	while (i < list_size && list)
	{
		(*tab)[i] = list->str;
		list = list->next;
		i++;
	}
	list = head;
	return (_ok);
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
	// cub->err = raw_check_format(cub->raw);
	return (cub->err);
}
