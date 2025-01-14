/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:13:28 by locharve          #+#    #+#             */
/*   Updated: 2025/01/14 14:06:54 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	cub;

	if (argc == 2)
	{
		if (!print_error(t_cub_init(&cub))
			&& !print_error(parsing_cub(&cub, argv[1])))
		{
			game(&cub);
		}
		t_cub_destroy(&cub);
	}
	else
		print_error(_badarg);
	return (0);
}
