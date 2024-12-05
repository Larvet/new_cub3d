/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cub3d.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnavarre <vnavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:18:46 by vnavarre          #+#    #+#             */
/*   Updated: 2024/12/03 11:53:20 by vnavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CUB3D_H
# define GAME_CUB3D_H

void	game(t_cub *cub);
int	    check_inter(double agl, double *d, bool h);
double	trig_agl(double agl);
int     raycast(t_cub *cub);
bool	wall_hit(double delta_x, double delta_y, t_cub *cub);

#endif