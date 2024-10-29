/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cub3d.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 07:56:56 by locharve          #+#    #+#             */
/*   Updated: 2024/10/29 12:46:21 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_CUB3D_H
# define PARSING_CUB3D_H

/* print_error.c */
t_err	print_error(t_err err);

/* parsing_cub.c */
t_err	extension_check(char *filename, char *ext);
t_err	is_path_dir(char *path);
t_err	strlist_init(t_str **list, int fd);
t_err	strlist_to_tab(t_str *list, char ***tab);
t_err	t_cub_raw_init(t_cub *cub, char *path);
t_err	parsing_cub(t_cub *cub, char *path);

/* str_utils.c */
int	is_in_str(char *str, char c);
int	str_isonly(const char *str, char *set);
int	str_contains(const char *str, char *set);
int	str_contains_n(const char *str, char *set);

/* strtab_utils.c */
int	skip_empty_lines(char **strtab);
int	is_in_strtab(char **tab, char *str);
size_t	strtab_max_len(char **strtab);
size_t	strtab_size(char **tab);
size_t	strtab_print(char **tab);
void	strtab_free(char **strtab);
char	**strtab_init(size_t size, ...);

/* t_cub.c */
t_err	t_cub_init(t_cub *cub);
void	t_cub_print(t_cub *cub);
void	t_cub_destroy(t_cub *cub);

/* t_cub_raw_parse.c */
int		skip_incharset(char *str, char *set);
void	swap_str(char **s1, char **s2);
int		t_cub_set_raw_args(t_cub *cub, char **raw);
t_err	t_cub_raw_parse(t_cub *cub);

/* t_str_utils.c */
t_str	*t_str_new(char *str);
void	t_str_addback(t_str **list, t_str *node);
size_t	t_str_listsize(t_str *list);
void	strlist_free(t_str *list);

#endif