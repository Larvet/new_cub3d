/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_check_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:17:09 by locharve          #+#    #+#             */
/*   Updated: 2024/10/30 12:31:10 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubd.h"

int	is_valid_map(char **raw)
{
	int	i;

	i = strtab_size(raw) - 1;
	while (i > 0 && !str_isonly(raw[i], WHITESPACES))
}

t_err	t_cub_check_map(t_cub *cub, char **raw)
{
	int	i;
	int	param_count;

	i = 0;
	param_count = 0;
	while (raw_args && raw_args[i] && param_count < 6
		&& !str_isonly(raw_args[i], "01 "))
	{
		if (!str_isonly(raw_args[i], WHITESPACES))
			param_count++;
		if (param_count > 6)
			break ;
		i++;
	}
	if (!is_valid_map(raw_args))
		return (_invalidmap); //////
	if (param_count > 6)
		return (_invalidf);
	return (_ok);
}