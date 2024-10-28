/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 07:42:14 by locharve          #+#    #+#             */
/*   Updated: 2024/10/28 13:13:14 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(t_err err)
{
	char	**tab;
	int		i;

	if (err)
	{
		tab = strtab_init(NBR_ERROR, ERR_MALLOC, ERR_BADEXT, ERR_ISDIR, ERR_FILEOP);
		if (tab)
		{
			i = 0;
			while (i < NBR_ERROR && i < (int)err - 1)
				i++;
			ft_putstr_fd("Error\n\t", 2);
			ft_putstr_fd(tab[i], 2);
		}
		strtab_free(tab);
	}
}
