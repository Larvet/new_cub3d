/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_str_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:22:43 by locharve          #+#    #+#             */
/*   Updated: 2025/01/14 14:22:00 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_err	strlist_init(t_str **list, int fd)
{
	t_str	*node;
	char	*line;

	line = get_next_line(fd);
		printf("line = %s\n", line); /////
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
