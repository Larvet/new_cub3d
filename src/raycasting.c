/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnavarre <vnavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:12:21 by vnavarre          #+#    #+#             */
/*   Updated: 2024/12/09 16:11:38 by vnavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	y_step_sign(double agl, double *y_step)
{
	if (agl > 0 && agl < M_PI)
	{
		if (*y_step < 0)
			*y_step *= -1;
	}
	else
	{
		if (*y_step > 0)
			*y_step *= -1;
	}
}

void	x_step_sign(double agl, double *x_step)
{
	if (agl > (M_PI / 2) && agl < ((3 * M_PI) / 2))
	{
		if (*x_step < 0)
			*x_step *= -1;
	}
	else
	{
		if (*x_step > 0)
			*x_step *= -1;
	}
}

double  h_distance(t_cub *cub, double agl)
{
	double	x_step;
	double	y_step;
	double	delta_x;
	double	delta_y;
	int		dp;

	x_step = TILE_SIZE / tan(agl);
	y_step = TILE_SIZE;
	delta_y = floor(cub->player->px_y / TILE_SIZE) * TILE_SIZE;
	dp = check_inter(agl, &delta_y, true);
	delta_x = cub->player->px_x + (delta_y - cub->player->px_y) * tan(agl);
	x_step_sign(agl, &x_step);
	y_step_sign(agl, &y_step);
	while (!wall_hit(delta_x, delta_y, cub))
	{
		delta_x += x_step;
		delta_y += y_step;
	}
	return (sqrt(pow(delta_x - cub->player->px_x, 2) + pow(delta_y - cub->player->px_y, 2)));
}

double  v_distance(t_cub *cub, double agl)
{
	double	x_step;
	double	y_step;
	double	delta_x;
	double	delta_y;
	int		dp;

	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(agl);
	printf("px = %d ; py = %d\n", cub->player->px_x, cub->player->px_y);
	delta_x = floor(cub->player->px_x / TILE_SIZE) * TILE_SIZE;
	dp = check_inter(agl, &delta_x, false);
	delta_y = cub->player->px_y + (delta_x - cub->player->px_x) * tan(agl);
	x_step_sign(agl, &x_step);
	y_step_sign(agl, &y_step);
	while (!wall_hit(delta_x, delta_y, cub))
	{
		delta_x += x_step;
		delta_y += y_step;
	}
	return (sqrt(pow(delta_x - cub->player->px_x, 2) + pow(delta_y - cub->player->px_y, 2)));
}

int raycast(t_cub *cub)
{
	int		ray;
	double	v_dist;
	double	h_dist;

	ray = 0;
	cub->ray->agl = cub->player->p_angle - (cub->player->fov / 2);
	while (ray < SCREEN_W)
	{
		cub->ray->pflag = 0;
		v_dist = v_distance(cub, trig_agl(cub->ray->agl));
		h_dist = h_distance(cub, trig_agl(cub->ray->agl));
		printf("v_d = %f ; h_d = %f\n", v_dist, h_dist);
		if (v_dist == 0 || h_dist == 0)
			return (-1);
		if (v_dist <= h_dist)
			cub->ray->dist = v_dist;
		else
		{
			cub->ray->pflag = 1;
			cub->ray->dist = h_dist;
		}
		render(cub, ray);
		cub->ray->agl = trig_agl(cub->ray->agl + cub->player->fov / SCREEN_W);
		ray++;
	}
	return (0);
}
