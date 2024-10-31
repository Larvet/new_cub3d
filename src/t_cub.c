/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 06:55:32 by locharve          #+#    #+#             */
/*   Updated: 2024/10/31 11:48:39 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_err	t_cub_init(t_cub *cub)
{
	ft_bzero(cub, sizeof(cub));
	cub->raw = NULL;
	cub->err = _ok;
	cub->raw_args = ft_calloc(6 + 1, sizeof(char *));
	if (!cub->raw_args)
		cub->err = _malloc;
	cub->path = ft_calloc(4 + 1, sizeof(char *));
	if (!cub->path)
		cub->err = _malloc;
	cub->rgb[0] = -1;
	cub->rgb[1] = -1;
	cub->height = 0;
	cub->width = 0;
	cub->p_x = -1;
	cub->p_y = -1;
	cub->map = NULL;
	return (cub->err);
}

void	t_cub_print(t_cub *cub)
{
	ft_putstr_fd("\n======= T_CUB_PRINT =======\n", 1);
	ft_putstr_fd("\n-------     raw     -------\n", 1);
	strtab_print(cub->raw);
	ft_putstr_fd("\n-------   raw_args  -------\n", 1);
	strtab_print(cub->raw_args);
	ft_putstr_fd("\n-------     path    -------\n", 1);
	strtab_print(cub->path);
	ft_putstr_fd("\n-------     rgb     -------\nF = ", 1);
	ft_putnbr_fd(cub->rgb[0], 1);
	ft_putstr_fd("\tC = ", 1);
	ft_putnbr_fd(cub->rgb[1], 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("\n-------     map     -------\n", 1);
	strtab_print(cub->map);
}

void	t_cub_destroy(t_cub *cub)
{
	strtab_free(cub->raw);
	free(cub->raw_args);
	strtab_free(cub->path);
	strtab_free(cub->map);
}
