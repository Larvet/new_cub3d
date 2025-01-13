/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnavarre <vnavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:41:19 by vnavarre          #+#    #+#             */
/*   Updated: 2025/01/09 16:21:20 by vnavarre         ###   ########.fr       */
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

void	key_hook_move(int keycode, t_cub *cub)
{
	// probleme: le joueur se deplace trop avec + ou - 1
	// > mettre en double ?
	if (keycode == 119)
	{
		cub->player->x += 1;
		move_front(cub, true);
	}
	else if (keycode == 97) // A
	{
		cub->player->y -= 1;
		move_side(cub, false);
	}
	else if (keycode == 115) // S
	{
		cub->player->x -= 1;
		move_front(cub, false);	
	}
	else if (keycode == 100) // D
	{
		cub->player->y += 1;
		move_side(cub, true);
	}
}

void	key_hook_rotate(int keycode, t_cub *cub)
{
	if (keycode == 65361)
	{
		cub->player->p_angle -= 0.05;
	}
	else if (keycode == 65363)
	{
		cub->player->p_angle += 0.05;
	}
}

int	key_hook(int keycode, t_cub *cub)
{
	// W 119 XK_W
	// A 97 XK_A
	// S 115 XK_S
	// D 100 XK_D
	
	// up 65362 XK_Up // OSEF
	// left 65361 XK_Left
	// down 65364 XK_Down // OSEF
	// right 65363 XK_Right
	
//	printf("keycode = %d\n", keycode);
	if (keycode == 65307) { // XK_Escape	
		t_cub_destroy(cub);
	}
	else if (keycode == 119 || keycode == 97
		|| keycode == 115 || keycode == 100)
		key_hook_move(keycode, cub);
	else if (keycode == 65361 || keycode == 65363)
		key_hook_rotate(keycode, cub);
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
///	mlx_key_hook(cub->game->win, key_hook, cub);
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
//	mlx_mouse_hide(cub->game->mlx, cub->game->win);
	mlx_hook(cub->game->win, 17, 4, close_cub, cub);
//	mlx_key_hook(cub->game->win, key_hook, cub); //////
	mlx_hook(cub->game->win, 2, 1L<<0, key_hook, cub);
	mlx_loop_hook(cub->game->mlx, game_start, cub);
	mlx_loop(cub->game->mlx);
}
