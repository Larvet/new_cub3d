/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:29:42 by locharve          #+#    #+#             */
/*   Updated: 2024/10/07 10:23:02 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_fill_line(char *new_l, int fd);
char	*ft_read_file(char *line, int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strcut(char *src, int c);
//void	ft_bzero(void *s, size_t n);
//size_t	ft_strlen(char *str);
//char	*ft_strchr(char *str, int c);
//char	*ft_strdup(char *src);
char	*ft_strcat_dst(char *dst, char *s1, char *s2);

#endif
