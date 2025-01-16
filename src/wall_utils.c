/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnavarre <vnavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:19:06 by vnavarre          #+#    #+#             */
/*   Updated: 2025/01/16 13:52:31 by vnavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	creat_image(t_image *img, void *mlx, int width, int height)
{
	img->img = mlx_new_image(mlx, width, height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_len, &img->endian);
}

void	get_img2(t_cub *cub)
{
	cub->ray->agl = trig_agl(cub->ray->agl);
	if (cub->ray->pflag == 0)
	{
		if (cub->ray->agl > M_PI / 2 && cub->ray->agl < 3 * (M_PI / 2))
			cub->game->actimg = cub->game->ea_img;
		else
			cub->game->actimg = cub->game->we_img;
	}
	else
	{
		if (cub->ray->agl > 0 && cub->ray->agl < M_PI)
			cub->game->actimg = cub->game->no_img;
		else
			cub->game->actimg = cub->game->so_img;
	}
}

void	crop_texture(t_cub *cub, int *texture_x, int *texture_y, bool h)
{
	double	factor;

	factor = ((cub->h_w - SCREEN_H) / TILE_SIZE) >> 1;
	if (factor > 0)
	{

		if (h)
		{
			if (*texture_x >= SCREEN_W >> 1)
				*texture_x -= factor;
			else
				*texture_x += factor;
		}
		else
		{
			if (*texture_y >= SCREEN_H >> 1)
				*texture_y -= factor;
			else
				*texture_y += factor;
		}
	}
}
