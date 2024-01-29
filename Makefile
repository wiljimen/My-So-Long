# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 11:52:24 by wiljimen          #+#    #+#              #
#    Updated: 2024/01/29 14:22:38 by wiljimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

SRCS = *.c

.c.o:
	($CC) $(CFLAGS) $(MLX_FLAGS) -I $(INCLUDES) -c $< -o $@
	
INCLUDES = includes/

MLX_FLAGS = -Lmlx -lmx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) libft.a -o $(NAME) $(OBJS) $(MLX_FLAGS) -I $(INCLUDES)
