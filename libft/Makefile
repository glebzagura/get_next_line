# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gzagura <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/04 18:04:09 by gzagura           #+#    #+#              #
#    Updated: 2017/12/04 18:05:25 by gzagura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS		= -Wall -Werror -Wextra -I./
NAME		= libft.a
CFILES		= $(wildcard ft_*.c)

.PHONY: norm all re clean fclean test

all: $(NAME)

$(NAME): $(CFILES)
	gcc -c $^ $(CFLAGS)
	ar crs $@ *.o

clean:
	rm -fr *.o
	find . -type f -name "*~" -print -delete

fclean: clean
	rm -fr $(NAME)

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader $(CFILES)

test: test.c $(NAME)
	gcc -o $@ $^ $(CFLAGS)

