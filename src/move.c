/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnavarre <vnavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:53:05 by vnavarre          #+#    #+#             */
/*   Updated: 2025/01/13 15:31:44 by vnavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_front(t_cub *cub, bool dir)
{
	double  move_x;
	double  move_y;
	double	npx;
	double	npy;

	move_x = cos(cub->player->p_angle) * 50;
	move_y = sin(cub->player->p_angle) * 50;
	npx = cub->player->px_x;
	npy = cub->player->px_y;
	if (dir)
	{
		npx += move_x + 1;
		npy += move_y + 1;
	}
	else
	{
		npx -= move_x - 1;
		npy -= move_y - 1;
	}
	if (check_npx(cub, cub->player->px_x, npx))
		cub->player->px_x = npx;
	if (check_npy(cub, cub->player->px_y, npy))
		cub->player->px_y = npy;
}

void	move_side(t_cub *cub, bool dir)
{
	double  move_x;
	double  move_y;
	double	npx;
	double	npy;

	move_x = cos(cub->player->p_angle + M_PI / 2) * 25;
	move_y = sin(cub->player->p_angle + M_PI / 2) * 25;
	npx = cub->player->px_x;
	npy = cub->player->px_y;
	if (dir)
	{
		npx += move_x + 1;
		npy += move_y + 1;
	}
	else
	{
		npx -= move_x - 1;
		npy -= move_y - 1;
	}
	if (check_npx(cub, cub->player->px_x, npx))
		cub->player->px_x = npx;
	if (check_npy(cub, cub->player->px_y, npy))
		cub->player->px_y = npy;
}
