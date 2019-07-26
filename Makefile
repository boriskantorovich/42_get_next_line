# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/26 18:02:18 by dfisher           #+#    #+#              #
#    Updated: 2019/07/20 21:15:14 by dfisher          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
CC = gcc
CCFLAGS = -Wall -Werror -Wextra
SRCS = 	*.c libft/libft.a
OBJ = ${SRC:.c=.o}
INCLUDES = . -I ./libft/includes
OPTIONS = -g $(SRCS) -I $(INCLUDES)

all: $(NAME)

$(NAME):
	$(CC) $(CCFLAGS) $(OPTIONS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
