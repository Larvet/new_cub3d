/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnavarre <vnavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:09:48 by locharve          #+#    #+#             */
/*   Updated: 2025/01/14 15:13:56 by vnavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_keybool(t_cub *cub, int keycode, bool b)
{
	if (keycode == 119)
		cub->player->move[_up] = b;
	if (keycode == 97)
		cub->player->move[_leftside] = b;
	if (keycode == 115)
		cub->player->move[_down] = b;
	if (keycode == 100)
		cub->player->move[_rightside] = b;
	if (keycode == 65361)
		cub->player->move[_leftrotate] = b;
	if (keycode == 65363)
		cub->player->move[_rightrotate] = b;
}

int	key_hook_true(int keycode, t_cub *cub)
{
	if (keycode == 65307)
		t_cub_destroy(cub);
	if (keycode == 119 || keycode == 97 || keycode == 115
		|| keycode == 100 || keycode == 65361 || keycode == 65363)
		set_keybool(cub, keycode, true);
	return (0);
}

int	key_hook_false(int keycode, t_cub *cub)
{
	if (keycode == 65307)
		t_cub_destroy(cub);
	if (keycode == 119 || keycode == 97 || keycode == 115
		|| keycode == 100 || keycode == 65361 || keycode == 65363)
		set_keybool(cub, keycode, false);
	return (0);
}
