/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:09:48 by locharve          #+#    #+#             */
/*   Updated: 2025/01/14 14:12:24 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_hook_move(int keycode, t_cub *cub)
{
	if (keycode == 119)
	{
		cub->player->x += 1;
		move_front(cub, true);
	}
	else if (keycode == 97)
	{
		cub->player->y -= 1;
		move_side(cub, false);
	}
	else if (keycode == 115)
	{
		cub->player->x -= 1;
		move_front(cub, false);
	}
	else if (keycode == 100)
	{
		cub->player->y += 1;
		move_side(cub, true);
	}
}

void	key_hook_rotate(int keycode, t_cub *cub)
{
	if (keycode == 65361)
		cub->player->p_angle -= 0.05;
	else if (keycode == 65363)
		cub->player->p_angle += 0.05;
	if (cub->player->p_angle < 0)
		cub->player->p_angle += 2 * M_PI;
	else if (cub->player->p_angle > 2 * M_PI)
		cub->player->p_angle -= 2 * M_PI;
}

int	key_hook(int keycode, t_cub *cub)
{
	if (keycode == 65307)
		t_cub_destroy(cub);
	else if (keycode == 119 || keycode == 97
		|| keycode == 115 || keycode == 100)
		key_hook_move(keycode, cub);
	else if (keycode == 65361 || keycode == 65363)
		key_hook_rotate(keycode, cub);
	return (0);
}