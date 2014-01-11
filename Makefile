# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/28 05:03:25 by cfeijoo           #+#    #+#              #
#    Updated: 2014/01/11 17:20:15 by cfeijoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

INCLUDEFOLDERS = -I./includes/ -I./libft/includes/ -I./guava/includes/
LIBFOLDERS = -L./guava/ -L./libft/ -L/usr/X11/lib/ -L/usr/X11/include
LIBS =  -lft -lmlx -lXext -lX11 -lguava

CC = cc
CFLAGS = -Wall -Werror -Wextra

CFILES =	main.c			\
			get_map_data.c

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME) :
	$(CC) -c $(CFILES) $(INCLUDEFOLDERS) $(CFLAGS)
	$(CC) $(OFILES) $(INCLUDEFOLDERS) $(LIBFOLDERS) $(LIBS) $(CFLAGS) -o $(NAME)

updatelibs :
	cd libft/ && git pull
	make -C libft/ re
	cd guava/ && git pull
	make -C guava/ re

complibs :
	make -C libft/ re
	make -C guava/ re

clean :
	rm -f $(OFILES)

fclean : clean
	rm -f $(NAME)

re : fclean all
