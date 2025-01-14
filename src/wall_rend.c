/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_rend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnavarre <vnavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:15:33 by vnavarre          #+#    #+#             */
/*   Updated: 2025/01/14 11:08:21 by vnavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	ft_mlx_get_pixel_color(t_image *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp >> 3));
	return (*(unsigned int *)dst);
}

void	print_c_and_f(t_cub *cub)
{
	int	x;
	int	y;
	int	rgb;

	y = 0;
	rgb = cub->rgb[0];
	while (y < SCREEN_H)
	{
		x = 0;
		if (y == SCREEN_H / 2)
			rgb = cub->rgb[1];
		while (x < SCREEN_W)
		{
			ft_mlx_pixel_put(&cub->game->img, x, y, rgb);
			x++;
		}
		y++;
	}
}

void	draw(t_cub *cub, int t_p, int b_p, int ray)
{
	double	wall_hitx;
	double	wall_hity;
	int		texture_x;
	int		texture_y;
	int		y;

	y = t_p;
	wall_hitx = cub->player->px_x + cub->ray->dist * cos(cub->ray->agl);
	wall_hity = cub->player->px_y + cub->ray->dist * sin(cub->ray->agl);
	if (!cub->ray->pflag)
		texture_x = (int)(wall_hity) % TILE_SIZE * IMG_SIZE / TILE_SIZE;
	else
		texture_x = (int)(wall_hitx) % TILE_SIZE * IMG_SIZE / TILE_SIZE;
	while (y < b_p)
	{
		get_img2(cub);
		texture_y = (y - t_p) * IMG_SIZE / (b_p - t_p);
		ft_mlx_pixel_put(&cub->game->img, ray, y,
			ft_mlx_get_pixel_color(&cub->game->actimg, texture_x, texture_y));
		y++;
	}
}

void	render(t_cub *cub, int ray)
{
	int	h_w;
	int	t_p;
	int	b_p;

	cub->ray->dist *= cos(trig_agl(cub->ray->agl - cub->player->p_angle));
	h_w = (TILE_SIZE / cub->ray->dist)
		* ((SCREEN_W / 2) / tan(cub->player->fov / 2));
	t_p = (SCREEN_H / 2) - (h_w / 2);
	b_p = (SCREEN_H / 2) + (h_w / 2);
	if (t_p < 0)
		t_p = 0;
	if (b_p > SCREEN_H)
		b_p = SCREEN_H;
	draw(cub, t_p, b_p, ray);
}
