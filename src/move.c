/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:53:05 by vnavarre          #+#    #+#             */
/*   Updated: 2025/01/15 12:30:07 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_front(t_cub *cub, bool dir)
{
	double	move_x;
	double	move_y;
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
	double	move_x;
	double	move_y;
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

void	rotate(t_cub *cub)
{
	if (cub->player->move[_leftrotate])
		cub->player->p_angle -= 0.05;
	if (cub->player->move[_rightrotate])
		cub->player->p_angle += 0.05;
	if (cub->player->p_angle < 0)
		cub->player->p_angle += 2 * M_PI;
	else if (cub->player->p_angle > 2 * M_PI)
		cub->player->p_angle -= 2 * M_PI;
}

void	move(t_cub *cub)
{
	if (cub->player->move[_up] && !cub->player->move[_down])
		move_front(cub, true);
	if (cub->player->move[_down] && !cub->player->move[_up])
		move_front(cub, false);
	if (cub->player->move[_leftside] && !cub->player->move[_rightside])
		move_side(cub, false);
	if (cub->player->move[_rightside] && !cub->player->move[_leftside])
		move_side(cub, true);
	if ((cub->player->move[_leftrotate] && !cub->player->move[_rightrotate])
		|| (cub->player->move[_rightrotate] && !cub->player->move[_leftrotate]))
		rotate(cub);
}
