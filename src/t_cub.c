/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 06:55:32 by locharve          #+#    #+#             */
/*   Updated: 2025/01/14 13:38:24 by locharve         ###   ########.fr       */
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

static t_err	t_cub_init_alloc(t_cub *cub)
{
	cub->raw_args = ft_calloc(6 + 1, sizeof(char *));
	if (!cub->raw_args)
		return (_malloc);
	cub->path = ft_calloc(4 + 1, sizeof(char *));
	if (!cub->path)
		return (_malloc);
	cub->player = ft_calloc(sizeof(t_player), 1);
	if (!cub->player)
		return (_malloc);
	cub->ray = ft_calloc(sizeof(t_ray), 1);
	if (!cub->ray)
		return (_malloc);
	cub->game = ft_calloc(1, sizeof(t_game));
	if (!cub->game)
		return (_malloc);
	return (_ok);
}

t_err	t_cub_init(t_cub *cub)
{
	ft_bzero(cub, sizeof(cub));
	cub->err = t_cub_init_alloc(cub);
	if (cub->err)
		return (cub->err);
	cub->raw = NULL;
	cub->err = _ok;
	cub->rgb[0] = -1;
	cub->rgb[1] = -1;
	cub->height = 0;
	cub->width = 0;
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

static void	t_game_destroy(t_game *game)
{
	if (game->win)
	{
		mlx_clear_window(game->mlx, game->win);
		mlx_destroy_window(game->mlx, game->win);
	}
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	if (game->no_img.img)
		mlx_destroy_image(game->mlx, game->no_img.img);
	if (game->ea_img.img)
		mlx_destroy_image(game->mlx, game->ea_img.img);
	if (game->so_img.img)
		mlx_destroy_image(game->mlx, game->so_img.img);
	if (game->we_img.img)
		mlx_destroy_image(game->mlx, game->we_img.img);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
}

void	t_cub_destroy(t_cub *cub)
{
	if (cub->game)
		t_game_destroy(cub->game);
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
	if (cub->ray)
		free(cub->ray);
	exit(0);
}
