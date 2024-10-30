/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum_cub3d.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 08:06:24 by locharve          #+#    #+#             */
/*   Updated: 2024/10/30 09:41:36 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_CUB3D_H
# define ENUM_CUB3D_H

typedef enum e_err
{
	_ok,			// 0 = no error
	_malloc,		// malloc error
	_badext,		// file extension muste be .cub
	_isdir,			// file is a directory
	_fileop,		// cannot open file
	_empty,			// empty file
	_invalidf,		// invalid arg, double arg, missing arg
	_invalidrgb		// invalid rgb format
}	t_err;

typedef enum e_arg_id	// to set and get raw_args
{
	_no,
	_so,
	_ea,
	_we,
	_f,
	_c
}	t_arg_id;

#endif