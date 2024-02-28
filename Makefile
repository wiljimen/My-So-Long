# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 11:52:24 by wiljimen          #+#    #+#              #
#    Updated: 2024/02/28 16:45:27 by wiljimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

# MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

MLX_FLAGS = -framework OpenGL -framework AppKit

LIBFT_DIR = libft/

SRCS = src/ft_sl_utils.c src/map_create.c src/map_image.c src/player_moves.c

OBJS = $(SRCS:.c=.o)
	
INCLUDES = -I libft/libft.h -I includes/so_long.h -I MLX/mlx.h

all: $(NAME)

$(NAME): $(OBJS)
	make -sC $(LIBFT_DIR)
	cp ./libft/libft.a .
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) libft.a MLX/libmlx.a $(MLX_FLAGS)  -o $(NAME)

clean :
		$(RM) $(OBJS)

fclean :	clean
		make fclean -sC  $(LIBFT_DIR)
		$(RM) $(NAME) libft.a

re : fclean all

.PHONY: all clean fclean re