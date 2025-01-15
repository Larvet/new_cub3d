/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_cub3d.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 07:56:28 by locharve          #+#    #+#             */
/*   Updated: 2025/01/15 16:20:59 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_CUB3D_H
# define DEFINE_CUB3D_H

# define WHITESPACES "\t\n\v\f\r "

# define NBR_ERROR 14

# define ERR_MALLOC "Memory allocation failed\n"
# define ERR_BADARG "The program needs one argument to launch\n"
# define ERR_BADEXT "File extension muste be .cub\n"
# define ERR_ISDIR "Path leads to a directory. It must lead to a file\n"
# define ERR_MISSINGSPACE "Texture and color IDs must be separated from their \
path/values by at least one space\n"
# define ERR_BADPATH "Invalid texture path format\n"
# define ERR_FILEOP "Cannot open file\n"
# define ERR_EMPTY "File is empty\n"
# define ERR_INVALIDF "Invalid file header. It must contain the IDs : \
\"NO\", \"SO\", \"EA\", \"WE\" (followed by paths to textures), \"F\", \"C\" \
(followed by RGB codes: <0-255> , <0-255> , <0-255>)\n"
# define ERR_INVALIDRGB "Invalid RGB: must be formated as follows: \
<F/C> <0-255> , <0-255> , <0-255>\n"
# define ERR_INVALIDMAP "Map must contain \"01 \" characters only, \
plus one character among \"NSWE\"\n"
# define ERR_UNCLOSEDMAP "Map must be closed (surrounded by \"1\")\n"
# define ERR_BADTEXTURE "Texture file is no valid .xpm file\n"
# define ERR_FFLIMIT "Floodfill limit: cannot handle so much space characters\n"
# define FFLIMIT 10000
# define SCREEN_W 1920
# define SCREEN_H 1080
# define EXIT 41
# define UP 119
# define DOWN 115
# define RIGHT 100
# define LEFT 97
# define RIGHT_ROTATE 65363
# define LEFT_ROTATE 65361
# define FOV 60
# define TILE_SIZE 300
# define IMG_SIZE 300

#endif