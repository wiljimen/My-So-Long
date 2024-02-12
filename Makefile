# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 11:52:24 by wiljimen          #+#    #+#              #
#    Updated: 2024/02/12 17:02:07 by wiljimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

RM = rm -f

#MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR = libft/

SRCS = src/ft_sl_utils.c src/map_create.c

OBJS = $(SRCS:.c=.o)
	
INCLUDES = includes/libft.h src/so_long.h

all: $(NAME)

$(NAME): $(OBJS)
	make -sC $(LIBFT_DIR)
	cp ./libft/libft.a ./src/
	$(CC) $(CFLAGS) libft.a $(OBJS) -o $(NAME)

# %.o: %.c
# 	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean :
		$(RM) $(OBJS)


fclean :	clean
		make fclean -sC  $(LIBFT_DIR)
		$(RM) $(NAME) libft.a

re : fclean all

.PHONY: all clean fclean re