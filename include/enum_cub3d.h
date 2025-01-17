/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum_cub3d.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnavarre <vnavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 08:06:24 by locharve          #+#    #+#             */
/*   Updated: 2025/01/16 13:47:22 by vnavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_CUB3D_H
# define ENUM_CUB3D_H

typedef enum e_err
{
	_ok,
	_malloc,
	_badarg,
	_badext,
	_isdir,
	_missingspace,
	_badpath,
	_fileop,
	_empty,
	_invalidf,
	_invalidrgb,
	_invalidmap,
	_unclosedmap,
	_badtexture,
	_fflimit
}	t_err;

typedef enum e_arg_id
{
	_no,
	_so,
	_ea,
	_we,
	_f,
	_c
}	t_arg_id;

typedef enum e_move
{
	_up,
	_down,
	_leftside,
	_rightside,
	_leftrotate,
	_rightrotate
}	t_move;

#endif