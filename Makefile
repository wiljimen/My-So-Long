# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 11:52:24 by wiljimen          #+#    #+#              #
#    Updated: 2024/02/01 16:40:01 by wiljimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR = libft/

SRCS = ft_sl_utils.c map_create.c

OBJS = $(SRC:.o=.c)
	
INCLUDES = includes/libft.h

all: $(NAME)

$(NAME): $(OBJS)
		make -sC $(LIBFT_DIR)
		mv ./libft/libft.a .
		$(CC) $(MLX_FLAGS) $(CFLAGS) libft.a -o $(OBJS) -I $(INCLUDES) -o $(NAME)

clean :
		make clean -sC  $(LIBFT_DIR)
		$(RM) $(OBJS)


fclean :	clean
		$(RM) $(NAME) libft.a

re : fclean all

.PHONY: all clean fclean re