/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 07:42:14 by locharve          #+#    #+#             */
/*   Updated: 2025/01/15 16:20:56 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_err	print_error(t_err err)
{
	char	**tab;
	int		i;

	if (err)
	{
		tab = strtab_init(NBR_ERROR, ERR_MALLOC, ERR_BADARG, ERR_BADEXT,
				ERR_ISDIR, ERR_MISSINGSPACE, ERR_BADPATH, ERR_FILEOP,
				ERR_EMPTY, ERR_INVALIDF, ERR_INVALIDRGB, ERR_INVALIDMAP,
				ERR_UNCLOSEDMAP, ERR_BADTEXTURE, ERR_FFLIMIT);
		if (tab)
		{
			i = 0;
			while (i < NBR_ERROR && i < (int)err - 1)
				i++;
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd(tab[i], 2);
			strtab_free(tab);
		}
		else
		{
			ft_putstr_fd("Error\nMemory allocation failed\n", 2);
			return (_malloc);
		}
	}
	return (err);
}
