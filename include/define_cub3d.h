/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_cub3d.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 07:56:28 by locharve          #+#    #+#             */
/*   Updated: 2024/10/30 11:15:44 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_CUB3D_H
# define DEFINE_CUB3D_H

# define WHITESPACES "\t\n\v\f\r "

# define NBR_ERROR 7 // mettre a jour avec le nombre de t_error

# define ERR_MALLOC "Memory allocation failed\n"
# define ERR_BADEXT "File extension muste be .cub\n"
# define ERR_ISDIR "Path leads to a directory. It must lead to a file\n"
# define ERR_FILEOP "Cannot open file\n"
# define ERR_EMPTY "File is empty\n"
# define ERR_INVALIDF "Invalid file header. It must contain the IDs : \
\"NO\", \"SO\", \"EA\", \"WE\" (followed by paths to textures), \"F\", \"C\" \
(followed by RGB codes: <0-255> , <0-255> , <0-255>)\n"
# define ERR_INVALIDRGB "Invalid RGB: must be formated as follows: \
<F/C> <0-255> , <0-255> , <0-255>\n"

#endif