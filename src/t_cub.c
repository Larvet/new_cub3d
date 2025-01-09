/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 06:55:32 by locharve          #+#    #+#             */
/*   Updated: 2025/01/09 09:44:25 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*void	init_image(t_cub *cub)
{
	cub->game->no_img = ft_calloc(sizeof(t_image), 1);
	cub->game->so_img = ft_calloc(sizeof(t_image), 1);
	cub->game->ea_img = ft_calloc(sizeof(t_image), 1);
	cub->game->we_img = ft_calloc(sizeof(t_image), 1);
}*/

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
	cub->player = ft_calloc(sizeof(t_player), 1);
	cub->ray = ft_calloc(sizeof(t_ray), 1);
	cub->player->px_x = -1;
	cub->player->px_y = -1;
	cub->player->p_angle = 2 * M_PI;
	cub->player->fov = (FOV * M_PI) / 180;
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
	if (cub->game->win)
	{
		mlx_clear_window(cub->game->mlx, cub->game->win);
		mlx_destroy_window(cub->game->mlx, cub->game->win);
	}
	if (cub->game->img.img)
		mlx_destroy_image(cub->game->mlx, cub->game->img.img);
	if (cub->game->no_img.img)
		mlx_destroy_image(cub->game->mlx, cub->game->no_img.img);
	if (cub->game->ea_img.img)
		mlx_destroy_image(cub->game->mlx, cub->game->ea_img.img);
	if (cub->game->so_img.img)
		mlx_destroy_image(cub->game->mlx, cub->game->so_img.img);
	if (cub->game->we_img.img)
		mlx_destroy_image(cub->game->mlx, cub->game->we_img.img);
	if (cub->raw)
		strtab_free(cub->raw);
	if (cub->raw_args)
		free(cub->raw_args);
	if (cub->path)
		strtab_free(cub->path);
	if (cub->map)
		strtab_free(cub->map);
	if (cub->player)
		free(cub->player);
//	free(cub->game->win);
	free(cub->ray);
	mlx_destroy_display(cub->game->mlx);
	free(cub->game->mlx); //
	free(cub->game);
	exit(0);
}
