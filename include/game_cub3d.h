/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cub3d.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:18:46 by vnavarre          #+#    #+#             */
/*   Updated: 2025/01/14 14:11:54 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CUB3D_H
# define GAME_CUB3D_H

void	game(t_cub *cub);
int	    check_inter(double agl, double *d, bool h);
double	trig_agl(double agl);
int     raycast(t_cub *cub);
bool	wall_hit(double delta_x, double delta_y, t_cub *cub);
void	print_c_and_f(t_cub *cub);
void	render(t_cub *cub, int ray);
void	creat_image(t_image *img, void *mlx, int width, int height);
void	move_front(t_cub *cub, bool dir);
void	get_img2(t_cub *cub);
void	move_side(t_cub *cub, bool dir);
bool	check_npx(t_cub *cub, double old_p, double new_p);
bool	check_npy(t_cub *cub, double old_p, double new_p);
void	key_hook_move(int keycode, t_cub *cub);
void	key_hook_rotate(int keycode, t_cub *cub);
int		key_hook(int keycode, t_cub *cub);

#endif