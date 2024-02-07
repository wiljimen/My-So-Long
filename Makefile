# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 11:52:24 by wiljimen          #+#    #+#              #
#    Updated: 2024/02/02 12:32:51 by wiljimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

#MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR = libft/

SRCS = src/ft_sl_utils.c src/map_create.c

OBJS = $(SRC:.o=.c)
	
#INCLUDES = includes/libft.h

all: $(NAME)

$(NAME): $(OBJS)
		make -sC $(LIBFT_DIR)
		mv ./libft/libft.a .
		$(CC) $(CFLAGS) libft.a -o $(OBJS)

clean :
		make clean -sC  $(LIBFT_DIR)
		$(RM) $(OBJS)


fclean :	clean
		$(RM) $(NAME) libft.a

re : fclean all

.PHONY: all clean fclean re