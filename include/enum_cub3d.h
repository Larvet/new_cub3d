/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum_cub3d.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 08:06:24 by locharve          #+#    #+#             */
/*   Updated: 2025/01/14 14:28:07 by locharve         ###   ########.fr       */
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
	_unclosedmap
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

#endif