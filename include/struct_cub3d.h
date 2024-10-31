/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_cub3d.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 06:48:43 by locharve          #+#    #+#             */
/*   Updated: 2024/10/31 10:22:18 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_CUB3D_H
# define STRUCT_CUB3D_H

typedef struct s_str
{
	char			*str;
	struct s_str	*next;
}	t_str;

typedef struct s_cub
{
	char	**raw;		// raw file
	char	**raw_args;	// contains textures and rgb

	/* ready to use */
	char	**path;		// checked textures paths ; NO, SO, EA, WE
	int		rgb[2];		// parsed rgb: F == 1; C == 0
	char	**map;		// map with every line at same length

	size_t	width;		// width and height of map (rectangle)
	size_t	height;
	int		p_x;		// player positions
	int		p_y;

	t_err	err;		// error enum
}	t_cub;


#endif