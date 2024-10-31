/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:40:55 by locharve          #+#    #+#             */
/*   Updated: 2024/10/31 10:42:45 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	skip_incharset(char *str, char *set)
{
	int	i;

	i = 0;
	while (str && set && str[i] && is_in_str(set, str[i]) >= 0)
		i++;
	return (i);
}

int	skip_outcharset(char *str, char *set)
{
	int	i;

	i = 0;
	while (str && str[i] && set && is_in_str(set, str[i]) < 0)
		i++;
	return (i);
}
