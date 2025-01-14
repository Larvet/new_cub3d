/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnavarre <vnavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:41:19 by vnavarre          #+#    #+#             */
/*   Updated: 2025/01/14 15:15:36 by vnavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_cub(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	t_cub_destroy(cub);
	return (0);
}

int	get_img(t_image *dst, t_cub *cub, char *path)
{
	if (dst->img)
		return (-1);
	dst->img = mlx_xpm_file_to_image(cub->game->mlx,
			path, &dst->width, &dst->height);
	if (!dst->img)
		return (-1);
	dst->addr = mlx_get_data_addr(dst->img,
			&dst->bpp, &dst->line_len, &dst->endian);
	return (0);
}

int	game_start(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	if (cub->game->img.img)
		mlx_destroy_image(cub->game->mlx, cub->game->img.img);
	move(cub);
	creat_image(&cub->game->img, cub->game->mlx, SCREEN_W, SCREEN_H);
	print_c_and_f(cub);
	raycast(cub);
	mlx_put_image_to_window(cub->game->mlx,
		cub->game->win, cub->game->img.img, 0, 0);
	return (0);
}

void	game(t_cub *cub)
{
	cub->game->mlx = mlx_init();
	if (!cub->game->mlx)
		return ;
	if (get_img(&cub->game->no_img, cub, cub->path[0]) != 0
		|| get_img(&cub->game->so_img, cub, cub->path[1]) != 0
		|| get_img(&cub->game->we_img, cub, cub->path[2]) != 0
		|| get_img(&cub->game->ea_img, cub, cub->path[3]) != 0)
	{
		print_error(_badtexture);
		t_cub_destroy(cub);
	}
	cub->game->win = mlx_new_window(cub->game->mlx,
			SCREEN_W, SCREEN_H, "cub3d");
	if (!cub->game->win)
		return ;
	mlx_hook(cub->game->win, 17, 4, close_cub, cub);
	mlx_hook(cub->game->win, 2, 1L << 0, key_hook_true, cub);
	mlx_hook(cub->game->win, 3, 1L << 1, key_hook_false, cub);
	mlx_loop_hook(cub->game->mlx, game_start, cub);
	mlx_loop(cub->game->mlx);
}
