/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_cub3d.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 06:48:43 by locharve          #+#    #+#             */
/*   Updated: 2025/01/14 14:29:42 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_CUB3D_H
# define STRUCT_CUB3D_H

typedef struct s_str
{
	char			*str;
	struct s_str	*next;
}	t_str;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}				t_image;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_image	actimg;
	t_image	img;
	t_image	no_img;
	t_image	so_img;
	t_image	we_img;
	t_image	ea_img;
}	t_game;

typedef struct s_ray
{
	double	agl;
	int		pflag;
	double	dist;
}	t_ray;

typedef struct s_player
{
	double	px_x;
	double	px_y;
	int		x;
	int		y;
	double	fov;
	double	p_angle;
	bool	move[6];
}	t_player;

typedef struct s_cub
{
	char		**raw;
	char		**raw_args;
	char		**path;
	int			rgb[2];
	char		**map;
	size_t		width;
	size_t		height;
	t_err		err;
	t_player	*player;
	t_game		*game;
	t_ray		*ray;
}	t_cub;

#endif