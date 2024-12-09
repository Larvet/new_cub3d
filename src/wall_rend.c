/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_rend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnavarre <vnavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:15:33 by vnavarre          #+#    #+#             */
/*   Updated: 2024/12/09 17:07:52 by vnavarre         ###   ########.fr       */
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

void	print_C_and_F(t_cub *cub)
{
	int	x;
	int	y;
	int	rgb;

	y = 0;
	rgb = cub->rgb[0];
	while(y < SCREEN_H)
	{
		x = 0;
		if (y == SCREEN_H / 2)
			rgb = cub->rgb[1];
		while (x < SCREEN_W)
		{
			mlx_pixel_put(cub->game->mlx, cub->game->win, x, y, rgb);
			x++;
		}
		y++;
	}
}

void get_img2(t_cub *cub)
{
	cub->ray->agl = trig_agl(cub->ray->agl);
	if (cub->ray->pflag == 0)
	{
		if (cub->ray->agl > M_PI / 2 && cub->ray->agl < 3 * (M_PI / 2))
			cub->game->actimg = cub->game->we_img;
		else
			cub->game->actimg = cub->game->ea_img;
	}
	else
	{
		if (cub->ray->agl > 0 && cub->ray->agl < M_PI)
			cub->game->actimg = cub->game->so_img;
		else
			cub->game->actimg = cub->game->no_img;
	}
}

void	draw(t_cub *cub, int t_p, int b_p, int ray)
{
	int 	wall_hitx;
	int 	wall_hity;
	double	texture_x;
	double	texture_y;
	int		y;

	y = 0;
	(void)ray;
	wall_hitx = cub->player->px_x + cub->ray->dist * cos(cub->ray->agl);
	wall_hity = cub->player->px_y + cub->ray->dist * sin(cub->ray->agl);
	printf("dist = %f\n", cub->ray->dist);
	if (cub->ray->pflag == 1)
		texture_x = (int)wall_hitx % TILE_SIZE * IMG_SIZE / TILE_SIZE;
	else
		texture_x = (int)wall_hity % TILE_SIZE * IMG_SIZE / TILE_SIZE;
	while (y < b_p)
	{
		get_img2(cub);
		texture_y = (y - t_p) * IMG_SIZE / (t_p - b_p);
		mlx_pixel_put(cub->game->mlx, cub->game->win, texture_x, texture_y, 255);
		y++;
	}
}

void	render(t_cub *cub, int ray)
{
	int	h_w;
	int	t_p;
	int	b_p;

	cub->ray->dist *= cos(trig_agl(cub->ray->agl - cub->player->p_angle));
	h_w = ((SCREEN_W / 2) / (tan(cub->player->fov / 2)) * (TILE_SIZE / cub->ray->dist));
	t_p = (SCREEN_H / 2) - (h_w / 2);
	b_p = (SCREEN_H / 2) + (h_w / 2);
	if (t_p < 0)
		t_p = 0;
	if (b_p > SCREEN_H)
		b_p = SCREEN_H;
	draw(cub, t_p, b_p, ray);
}
