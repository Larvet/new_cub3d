/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnavarre <vnavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:01:50 by vnavarre          #+#    #+#             */
/*   Updated: 2025/01/14 11:01:01 by vnavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	trig_agl(double agl)
{
	if (agl < 0)
		agl += (2 * M_PI);
	if (agl > (2 * M_PI))
		agl -= (2 * M_PI);
	return (agl);
}

int	check_inter(double agl, double *d, bool h)
{
	if (h)
	{
		if (agl > 0 && agl < M_PI)
		{
			*d += TILE_SIZE;
			return (-1);
		}
	}
	else
	{
		if (!(agl > (M_PI / 2) && agl < ((3 * M_PI) / 2)))
		{
			*d += TILE_SIZE;
			return (-1);
		}
	}
	return (1);
}

bool	wall_hit(double delta_x, double delta_y, t_cub *cub)
{
	int	x;
	int	y;

	if (delta_x <= 0 || delta_y <= 0)
		return (true);
	x = floor(delta_x / TILE_SIZE);
	y = floor(delta_y / TILE_SIZE);
	if (x >= (int)cub->width || y >= (int)cub->height || x <= 0 || y <= 0)
		return (true);
	if (cub->map[y] && x <= (int)ft_strlen(cub->map[y]))
		if (cub->map[y][x] == '1')
			return (true);
	return (false);
}
