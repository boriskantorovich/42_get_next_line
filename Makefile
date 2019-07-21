# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/26 18:02:18 by dfisher           #+#    #+#              #
#    Updated: 2019/07/21 20:05:09 by dfisher          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
NAME_ALT = b.out
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_NAME = get_next_line.c main.c
OBJ_NAME = ${SRC_NAME:%.c=%.o}
LDFLAGS = -Llibft
LDLIBS = -lft

HEADER_DIR = -I. -Ilibft

all: $(NAME)

alt: $(NAME_ALT)

$(NAME_ALT):
	gcc -Wall -Wextra -Werror all_in.c main.c -Llibft -lft -I. -Ilibft -o $(NAME_ALT)

$(NAME):
	$(CC) $(CFLAGS) $(SRC_NAME) $(LDFLAGS) $(LDLIBS) $(HEADER_DIR)

clean:
	rm -fv $(OBJ_NAME)

fclean: clean
	rm -fv $(NAME)

re: fclean all
