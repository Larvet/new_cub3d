/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnavarre <vnavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:41:19 by vnavarre          #+#    #+#             */
/*   Updated: 2024/12/12 11:14:15 by vnavarre         ###   ########.fr       */
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

int	key_hook(int keycode, t_cub *cub)
{
	if (keycode == 65307)
		t_cub_destroy(cub);
	return (0);
}

int	get_img(t_image *dst, t_cub *cub, char *path)
{
	if(dst->img)
		return (-1);
	dst->img = mlx_xpm_file_to_image(cub->game->mlx, path, &dst->width, &dst->height);
	if (!dst->img)
		return (-1);
	dst->addr = mlx_get_data_addr(dst->img, &dst->bpp, &dst->line_len, &dst->endian);
	return (0);
}

/*int	mouse_hook(int mouse, void *param)
{
	t_cub *cub;

	cub = (t_cub*)param;
	if (mouse == 3)
	{
		mlx_mouse_show(cub->game->mlx, cub->game->win);
	}
	if (mouse == 1)
	{
		mlx_mouse_hide(cub->game->mlx, cub->game->win);
	}
	return (0);
}*/

/*int	expose_hook(int exp, void *param)
{
	t_cub *cub;

	cub = (t_cub*)param;
	if (exp == 0)
		//fonction pour exit(cub)
	return (0);
}*/

int	game_start(void *param)
{
	t_cub	*cub;

	cub = (t_cub*)param;
	if (cub->game->img.img)
		mlx_destroy_image(cub->game->mlx, cub->game->img.img);
	//mlx_clear_window(cub->game->mlx, cub->game->win);
	creat_image(&cub->game->img, cub->game->mlx, SCREEN_W, SCREEN_H);
	print_C_and_F(cub);  
	mlx_key_hook(cub->game->win, key_hook, cub);
	//mlx_mouse_hook(cub->game->win, mouse_hook, cub);
	//mlx_expose_hook(cub->game->win, expose_hook, cub);
	raycast(cub);
	mlx_put_image_to_window(cub->game->mlx, cub->game->win, cub->game->img.img, 0, 0);
	return (0);
}

void	game(t_cub *cub)
{
	cub->game = ft_calloc(1, sizeof(t_game));
	//init_image(cub);
	cub->game->mlx = mlx_init();
	if (!cub->game->mlx)
		return ;
	cub->game->win = mlx_new_window(cub->game->mlx, SCREEN_W, SCREEN_H, "cub3d");
	if (!cub->game->win)
		return ;
	get_img(&cub->game->no_img, cub, cub->path[0]);
	get_img(&cub->game->so_img, cub, cub->path[1]);
	get_img(&cub->game->we_img, cub, cub->path[2]);
	get_img(&cub->game->ea_img, cub, cub->path[3]);
	mlx_mouse_hide(cub->game->mlx, cub->game->win);
	mlx_hook(cub->game->win, 17, 4, close_cub, cub);
	mlx_loop_hook(cub->game->mlx, game_start, cub);
	mlx_loop(cub->game->mlx);
}
