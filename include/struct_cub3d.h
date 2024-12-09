/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_cub3d.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnavarre <vnavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 06:48:43 by locharve          #+#    #+#             */
/*   Updated: 2024/12/09 14:35:42 by vnavarre         ###   ########.fr       */
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
	t_image actimg;
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
	int		px_x;
	int		px_y;
	int		x;
	int		y;
	double	fov;
	double	p_angle;
}	t_player;

typedef struct s_cub
{
	char		**raw;		// raw file
	char		**raw_args;	// contains textures and rgb

	/* ready to use */
	char		**path;		// checked textures paths ; NO, SO, EA, WE
	int			rgb[2];		// parsed rgb: F == 1; C == 0
	char		**map;		// map with every line at same length

	size_t		width;		// width and height of map (rectangle)
	size_t		height;

	t_err		err;		// error enum

	/* game */
	t_player	*player;
	t_game		*game;
	t_ray		*ray;
}	t_cub;


#endif