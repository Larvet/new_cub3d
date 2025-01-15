# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: locharve <locharve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 05:30:41 by locharve          #+#    #+#              #
#    Updated: 2025/01/15 16:26:30 by locharve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

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
	check_map.c \
	parsing_cub.c \
	print_error.c \
	smooth_map.c \
	str_utils.c \
	str_utils2.c \
	strtab_utils.c \
	strtab_utils2.c \
	t_cub.c \
	t_cub_raw_parse.c \
	t_cub_set_map.c \
	t_cub_set_path.c \
	t_cub_set_rgb.c \
	t_str_utils.c \
	t_str_utils2.c \
	game.c \
	raycasting.c \
	raycasting_utils.c \
	wall_rend.c \
	wall_utils.c \
	move.c \
	move_utils.c \
	hooks.c
	

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: mlx libft $(NAME)
	@echo "\001\e[1;32m\002Compilation OK \001\e[0m\002"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@test -d $(OBJ_DIR) || mkdir $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

$(NAME): $(OBJ)
	@echo "\001\e[1;32m\002Compiling cub3d \001\e[0m\002"
	@$(CC) $(OBJ) $(LIBFT) $(HEADERS) $(MLXFLAGS) -o $(NAME)

mlx :
	@test -d minilibx-linux || (wget https://cdn.intra.42.fr/document/document/25837/minilibx-linux.tgz \
		&& tar -xvf minilibx-linux.tgz && make -C minilibx-linux && rm minilibx-linux.tgz)
	@make --no-print-directory -C ./minilibx-linux -s
libft:
	@make --no-print-directory -C ./libft -s

clean:
	@rm -rf $(OBJ_DIR)
	@make clean --no-print-directory -C ./libft -s
	@make clean --no-print-directory -C ./minilibx-linux -s

fclean: clean
	@rm -rf $(NAME)

re: clean all

c: all clean

.PHONY: all, clean, fclean, re, libft

# https://cdn.intra.42.fr/document/document/21665/minilibx-linux.tgz