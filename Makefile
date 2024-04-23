# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 11:52:24 by wiljimen          #+#    #+#              #
#    Updated: 2024/04/23 13:19:04 by wiljimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

RED		=	\033[91;1m
GREEN	=	\033[92;1m
CLEAR	=	\033[0m

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address

RM = rm -f

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR = libft/

BSRCS = bonus/ft_utils_bonus.c bonus/map_create_bonus.c bonus/map_image_bonus.c \
		bonus/player_moves_bonus.c bonus/hooks_bonus.c bonus/map_path_bonus.c \
		bonus/so_long_bonus.c bonus/ft_utils_two_bonus.c bonus/player_frames_bonus.c \
		bonus/ft_sprites_error_bonus.c
		
SRCS = src/ft_utils.c src/map_create.c src/map_image.c src/player_moves.c src/ft_sprites_error.c \
		src/hooks.c src/map_path.c src/so_long.c src/ft_utils_two.c

BOBJS = $(BSRCS:.c=.o)

OBJS = $(SRCS:.c=.o)

INCLUDES = -I includes/libft.h -I includes/so_long.h -I MLX/mlx.h

MAKEFLAGS += --silent

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	@make all -sC $(LIBFT_DIR)
	@make all -sC MLX/
	@cp ./libft/libft.a .
	@$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) libft.a MLX/libmlx.a $(MLX_FLAGS)  -o $(NAME)
	@echo "$(GREEN)GTA San Andreas has been downloaded"
	@echo "$(GREEN)and is ready to be played"

$(NAME_BONUS): $(BOBJS)
	@make -sC $(LIBFT_DIR)
	@make -sC MLX/
	@cp ./libft/libft.a .
	@$(CC) $(CFLAGS) $(BOBJS) $(INCLUDES) libft.a MLX/libmlx.a $(MLX_FLAGS)  -o $(NAME_BONUS)
	@echo "$(GREEN)Mods installed"
	@echo "$(GREEN)and are ready to be played"
	
clean :
		@$(RM) $(OBJS) $(BOBJS)
		@echo "$(RED)did you save your game?"
		@make clean -sC  $(LIBFT_DIR)
		@make clean -sC  mlx

fclean : clean
		@make fclean -sC  $(LIBFT_DIR)
		@$(RM) $(NAME) $(NAME_BONUS) libft.a
		@echo "$(RED)Oh shit, here we go again"

re : fclean all

.PHONY: all clean fclean re