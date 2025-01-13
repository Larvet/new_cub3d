/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnavarre <vnavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:24:21 by vnavarre          #+#    #+#             */
/*   Updated: 2025/01/13 15:25:23 by vnavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnavarre <vnavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:52:14 by vnavarre          #+#    #+#             */
/*   Updated: 2025/01/13 15:09:34 by vnavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_npx(t_cub *cub, double old_p, double new_p)
{
	int	x;
	int	y;
	int	buff;

	x = (int)cub->player->px_x / TILE_SIZE;
	y = (int)cub->player->px_y / TILE_SIZE;
	buff = TILE_SIZE;
	if (new_p >= old_p)
	{
		x = (int)((new_p + buff) / TILE_SIZE);
		if (cub->map[y][x] == '1')
			return (false);
		return (true);
	}
	else
	{
		x = (int)((new_p - buff) / TILE_SIZE);
		if (cub->map[y][x] == '1')
			return (false);
		return (true);
	}
	return (false);
}

bool	check_npy(t_cub *cub, double old_p, double new_p)
{
	int	x;
	int	y;
	int	buff;

	x = (int)cub->player->px_x / TILE_SIZE;
	y = (int)cub->player->px_y / TILE_SIZE;
	buff = TILE_SIZE / 4;
	if (new_p >= old_p)
	{
		y = (int)((new_p + buff) / TILE_SIZE);
		if (cub->map[y][x] == '1')
			return (false);
		return (true);
	}
	else
	{
		y = (int)((new_p - buff) / TILE_SIZE);
		if (cub->map[y][x] == '1')
			return (false);
		return (true);
	}
	return (false);
}