/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_set_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:01:27 by locharve          #+#    #+#             */
/*   Updated: 2024/10/30 12:31:15 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	start_of_map_index(char **raw_args)
{
	int	i;
	int	j;

	i = strtab_size(raw_args);
	while (i > 0 && !str_isonly(raw_args[i], "01 "))
		i--;
	j = i;
	while (j > 0 && )
}

t_err	t_cub_set_map(t_cub *cub, char **raw_args)
{
	int	i;

	i = start_of_map_index(raw_args);
	if (i < 0)
		cub->err = _invalidf; /// ?

	return (cub->err);
}