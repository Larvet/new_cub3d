/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_set_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:08:26 by locharve          #+#    #+#             */
/*   Updated: 2024/10/31 14:26:52 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	encode_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	parse_rgb(char *str)
{
	int	tmp[3];
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (str && str[i] && ++j < 3)
	{
		i += skip_incharset(&str[i], WHITESPACES);
		if (!ft_isdigit(str[i]))
			return (-1);
		tmp[j] = ft_atoi(&str[i]);
		if (tmp[j] < 0 || tmp[j] > 255)
			return (-2);
		i += skip_incharset(&str[i], "0123456789");
		i += skip_incharset(&str[i], WHITESPACES);
		if ((j < 2 && str[i] != ',')
			|| (j >= 2 && str[i] && is_in_str(WHITESPACES, str[i]) < 0))
			return (-3);
		i += str[i] != '\0';
	}
	if (str[i + skip_incharset(&str[i], WHITESPACES)] || j < 2)
		return (-4);
	return (encode_rgb(tmp[0], tmp[1], tmp[2]));
}

t_err	set_rgb(int *to_set, char **raw_args, char *to_cmp)
{
	int	i;
	int	j;

	i = 0;
	while (raw_args && raw_args[i])
	{
		j = skip_incharset(raw_args[i], WHITESPACES);
		if (!ft_strncmp(&raw_args[i][j], to_cmp, ft_strlen(to_cmp)))
			break ;
		i++;
	}
	j++;
	if (is_in_str(WHITESPACES, raw_args[i][j]) < 0)
		return (_missingspace);
	*to_set = parse_rgb(&raw_args[i][j]);
	if (*to_set < 0)
		return (_invalidrgb);
	else
		return (_ok);
}

t_err	t_cub_set_rgb(t_cub *cub, char **raw_args)
{
	char	**fc;
	int		i;

	fc = strtab_init(2, "F", "C");
	if (!fc)
		cub->err = _malloc;
	else
	{
		i = 0;
		while (fc[i])
		{
			cub->err = set_rgb(&cub->rgb[i], raw_args, fc[i]);
			if (cub->err)
				break ;
			i++;
		}
		strtab_free(fc);
	}
	return (cub->err);
}
