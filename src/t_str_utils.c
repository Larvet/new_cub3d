/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_str_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 07:56:15 by locharve          #+#    #+#             */
/*   Updated: 2025/01/14 14:21:38 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_str	*t_str_new(char *str)
{
	t_str	*new_t_str;

	new_t_str = ft_calloc(1, sizeof(*new_t_str));
	if (new_t_str)
	{
		new_t_str->str = str;
		new_t_str->next = NULL;
	}
	return (new_t_str);
}

void	t_str_addback(t_str **list, t_str *node)
{
	if (list)
	{
		if (*list)
			t_str_addback(&(*list)->next, node);
		else
			*list = node;
	}
}

size_t	t_str_listsize(t_str *list)
{
	if (!list)
		return (0);
	else
		return (1 + t_str_listsize(list->next));
}

void	strlist_free(t_str *list)
{
	t_str	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}
