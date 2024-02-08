# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 11:52:24 by wiljimen          #+#    #+#              #
#    Updated: 2024/02/08 16:39:12 by wiljimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

#MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR = libft/

SRCS = src/ft_sl_utils.c src/map_create.c

OBJS = $(SRC:.o=.c)
	
INCLUDES = includes/libft.h src/so_long.h

all: $(NAME)

$(NAME): $(OBJS)
	make -sC $(LIBFT_DIR)
	cp ./libft/libft.a .
	$(CC) $(FLAGS) libft.a $(OBJS) -o $(NAME)

%.o: %.c
	${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o $@

clean :
		make clean -sC  $(LIBFT_DIR)
		$(RM) $(OBJS)


fclean :	clean
		make fclean -sC  $(LIBFT_DIR)
		$(RM) $(NAME) libft.a

re : fclean all

.PHONY: all clean fclean re