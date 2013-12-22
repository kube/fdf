# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/28 05:03:25 by cfeijoo           #+#    #+#              #
#    Updated: 2013/12/22 16:37:53 by cfeijoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
INCLUDEFOLDER = -I./includes/ -I./libft/includes/ -I./getNextLine/
LIBFOLDER = -L/usr/X11/lib/ -L./libft/
LIBS = -lmlx -lXext -lX11 -lft
CFLAGS = -Wall -Werror -Wextra -O4

CC = gcc
CFILES = main.c					\
		 blend_colors.c			\
		 transformations.c		\
		 get_next_line.c		\
		 draw_vector.c

OFILES = $(CFILES:.c=.o)

$(NAME) : 
	$(CC) -c $(INCLUDEFOLDER) $(CFLAGS) $(CFILES)
	$(CC) $(LIBFOLDER) $(LIBS) $(INCLUDEFOLDER) $(CFLAGS) $(OFILES) -o $(NAME)

updatelib :
	cd libft/ && git pull
	make -C libft/ re

clean :
	rm -f $(OFILES)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)