/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_cub3d.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 06:48:43 by locharve          #+#    #+#             */
/*   Updated: 2024/10/28 12:07:40 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_CUB3D_H
# define STRUCT_CUB3D_H

typedef enum e_err
{
	_ok,		// 0 = no error
	_malloc,	// malloc error
	_badext,	// file extension muste be .cub
	_isdir,		// file is a directory
	_fileop		// cannot open file
}	t_err;

typedef struct s_str
{
	char			*str;
	struct s_str	*next;
}	t_str;

typedef struct s_cub
{
	char	**raw; // raw file
	t_err	err;
}	t_cub;


#endif