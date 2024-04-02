# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 11:52:24 by wiljimen          #+#    #+#              #
#    Updated: 2024/03/19 16:19:05 by wiljimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

RED		=	\033[91;1m
GREEN	=	\033[92;1m
CLEAR	=	\033[0m

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

RM = rm -f

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR = libft/

SRCS = src/ft_sl_utils.c src/map_create.c src/map_image.c src/player_moves.c \
		src/hooks.c src/map_path.c src/so_long.c


OBJS = $(SRCS:.c=.o)
	
BSRCS = bonus/src/ft_sl_utils_bonus.c \
		bonus/src/map_create_bonus.c \
		bonus/src/map_image_bonus.c \
		bonus/src/hooks_bonus.c \
		bonus/src/player_moves_bonus.c \
		bonus/src/map_path_bonus.c \
		bonus/src/so_long_bonus.c \
		bonus/src/map_sprites.c \

BOBJS = $(BSRCS:.c=.o)

INCLUDES = -I includes/libft.h -I includes/so_long.h -I MLX/mlx.h

MAKEFLAGS += --silent

all: $(NAME)

$(NAME): $(OBJS)
	@make -sC $(LIBFT_DIR)
	@make -sC MLX/
	@cp ./libft/libft.a .
	@$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) libft.a MLX/libmlx.a $(MLX_FLAGS)  -o $(NAME)
	@echo "$(GREEN)GTA San Andreas has been downloaded"
	@echo "$(GREEN)and is ready to be played"

bonus: $(BOBJS)
	@make -sC $(LIBFT_DIR)
	@make -sC MLX/
	@cp ./libft/libft.a .
	@$(CC) $(CFLAGS) $(BOBJS) $(INCLUDES) libft.a MLX/libmlx.a $(MLX_FLAGS)  -o $(NAME)
	
clean :
		@$(RM) $(OBJS) $(BOBJS)
		@echo "$(RED)did you save your game?"
		@make clean -sC  $(LIBFT_DIR)
		@make clean -sC  mlx

fclean : clean
		@make fclean -sC  $(LIBFT_DIR)
		@$(RM) $(NAME) libft.a
		@echo "$(RED)Oh shit, here we go again"

re : fclean all

.PHONY: all clean fclean re