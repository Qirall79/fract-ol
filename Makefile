# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbelfatm <wbelfatm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/09 18:54:41 by wbelfatm          #+#    #+#              #
#    Updated: 2023/12/09 20:29:39 by wbelfatm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast
RM = rm -f

NAME = fractol
SRCS = src/main.c src/draw.c src/hooks.c src/in_set.c src/parse.c\
	src/utils.c src/init.c src/colors.c src/colors_2.c
OBJS = ${SRCS:.c=.o}

LIBMLX = ./MLX42
HEADERS = -I $(LIBMLX)/include
LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c fractol.h
	@$(CC) -c $(CFLAGS) $< -o $@ $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	
clean:
	@$(RM) $(OBJS)
	@$(RM) -r $(LIBMLX)/build

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: libmlx all clean fclean re 