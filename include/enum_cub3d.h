/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum_cub3d.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 08:06:24 by locharve          #+#    #+#             */
/*   Updated: 2024/10/31 14:27:04 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_CUB3D_H
# define ENUM_CUB3D_H

typedef enum e_err	// 12 - 1
{
	_ok,			// 0 = no error
	_malloc,		// malloc error
	_badext,		// file extension muste be .cub
	_isdir,			// file is a directory
	_missingspace,	// id and path/value must be separated by at least one space
	_badpath,		// path format is invalid
	_fileop,		// cannot open file
	_empty,			// empty file
	_invalidf,		// invalid arg, double arg, missing arg
	_invalidrgb,	// invalid rgb format
	_invalidmap,	// map must be only "01 "
	_unclosedmap	// map must be surrounded by 1
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