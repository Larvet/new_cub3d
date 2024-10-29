/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_cub3d.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 06:48:43 by locharve          #+#    #+#             */
/*   Updated: 2024/10/29 12:46:20 by locharve         ###   ########.fr       */
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
	char	**path;		// checked textures paths ; NO, SO, EA, WE
	int		floor_rgb;	// parsed rgb
	int		ceiling_rgb;
	char	**map;		// map with every line at same length
	
	t_err	err;		// error enum
}	t_cub;


#endif