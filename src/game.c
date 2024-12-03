/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnavarre <vnavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:41:19 by vnavarre          #+#    #+#             */
/*   Updated: 2024/12/03 15:03:43 by vnavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*int	key_hook(void *param)
{

}*/

int	mouse_hook(int mouse, void *param)
{
	t_cub *cub;

	cub = (t_cub*)param;
	if (mouse == 3)
	{
		mlx_mouse_hide(cub->game->mlx, cub->game->win);
	}
	if (mouse == 1)
	{
		mlx_mouse_show(cub->game->mlx, cub->game->win);
	}
	return (0);
}

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
	//mlx_key_hook(cub->game->win, key_hook, cub);
	mlx_mouse_hook(cub->game->win, mouse_hook, cub);
	//mlx_expose_hook(cub->game->win, expose_hook, cub);
	raycast(cub);
	return (0);
}

void	game(t_cub *cub)
{
	int height;
	int widht;

	cub->game = ft_calloc(1, sizeof(t_game));
	cub->game->mlx = mlx_init();
	if (!cub->game->mlx)
		return ;
	cub->game->win = mlx_new_window(cub->game->mlx, SCREEN_W, SCREEN_H, "cub3d");
	if (!cub->game->win)
		return ;
	cub->game->no_img = mlx_xpm_file_to_image(cub->game->mlx, cub->path[0], &widht, &height);
	cub->game->so_img = mlx_xpm_file_to_image(cub->game->mlx, cub->path[1], &widht, &height);
	cub->game->we_img = mlx_xpm_file_to_image(cub->game->mlx, cub->path[2], &widht, &height);
	cub->game->ea_img = mlx_xpm_file_to_image(cub->game->mlx, cub->path[3], &widht, &height);
	mlx_mouse_hide(cub->game->mlx, cub->game->win);
	mlx_loop_hook(cub->game->mlx, game_start, cub);
	mlx_loop(cub->game->mlx);
}
