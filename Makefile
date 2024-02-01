# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 11:52:24 by wiljimen          #+#    #+#              #
#    Updated: 2024/02/01 16:31:46 by wiljimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR = libft/

# CAMBIAR :D
SRCS = *.c

OBJS = $(SRC:.o=.c)

#.c.o:
#	($CC) $(CFLAGS) $(MLX_FLAGS) -I $(INCLUDES) -c $< -o $@
	
INCLUDES = includes/

all: $(NAME)

$(NAME): $(OBJS)
		make -sC $(LIBFT_DIR)
		cp ./libft/libft.a .
#		$(CC) $(MLX_FLAGS) libft.a -o $(OBJS) -I $(INCLUDES) -o $(NAME)

#%.o: %.c
#		$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean :
		make -sC clean $(LIBFT_DIR)


fclean :	clean
		$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re