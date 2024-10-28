# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: locharve <locharve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 05:30:41 by locharve          #+#    #+#              #
#    Updated: 2024/10/28 13:14:09 by locharve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC_DIR = ./src
OBJ_DIR = ./obj

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm

HEADERS = -I ./include -I ./libft -I ./minilibx-linux
MLX = minilibx-linux/libmlx_Linux.a
LIBFT = ./libft/libft.a

# ls -1 *.c | sed -z 's/\n/ \\\n\t\t\t/g'
SRC = main.c \
	parsing_cub.c \
	print_error.c \
	str_utils.c \
	strtab_utils.c \
	t_cub.c \
	t_str_utils.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: mlx libft $(NAME)
	@echo "\001\e[1;32m\002Compilation OK \001\e[0m\002"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@test -d $(OBJS_DIR) || mkdir $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

$(NAME): $(OBJ)
	@echo "\001\e[1;32m\002Compiling cub3d \001\e[0m\002"
	@$(CC) $(OBJ) $(LIBFT) $(HEADERS) $(MLXFLAGS) -o $(NAME)

mlx :
	@test -d minilibx-linux || (wget https://cdn.intra.42.fr/document/document/21665/minilibx-linux.tgz \
		&& tar -xvf minilibx-linux.tgz && make -C minilibx-linux && rm minilibx-linux.tgz)

libft:
	@make --no-print-directory -C ./libft -s

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libft
