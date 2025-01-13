/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnavarre <vnavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:53:05 by vnavarre          #+#    #+#             */
/*   Updated: 2025/01/09 16:04:07 by vnavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_front(t_cub *cub, bool dir)
{
	double  move_x;
	double  move_y;

	move_x = cos(cub->player->p_angle) * 50;
	move_y = sin(cub->player->p_angle) * 50;
	if (dir)
	{
		cub->player->px_x += move_x + 1;
		cub->player->px_y += move_y + 1;
	}
	else
	{
		cub->player->px_x -= move_x - 1;
		cub->player->px_y -= move_y - 1;
	}
}

void	move_side(t_cub *cub, bool dir)
{
	double  move_x;
	double  move_y;

	move_x = cos(cub->player->p_angle + M_PI / 2) * 50;
	move_y = sin(cub->player->p_angle + M_PI / 2) * 50;
	if (dir)
	{
		cub->player->px_x += move_x + 1;
		cub->player->px_y += move_y + 1;
	}
	else
	{
		cub->player->px_x -= move_x - 1;
		cub->player->px_y -= move_y - 1;
	}
}