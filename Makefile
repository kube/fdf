# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/28 05:03:25 by cfeijoo           #+#    #+#              #
#    Updated: 2013/12/28 18:57:38 by cfeijoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
INCLUDEFOLDER = -I./includes/ -I./libft/includes/
LIBFOLDER = -L./libft/ -L/usr/X11/lib/ -L/usr/X11/include
LIBS = -lmlx -lXext -lX11 -lft
CFLAGS = -g -Wall -Werror -Wextra -O4

CC = gcc
CFILES = main.c					\
		 blend_colors.c			\
		 transformations.c		\
		 get_map_data.c			\
		 get_next_line.c		\
		 display_vector.c		\
		 fade.c					\
		 cossin.c				\
		 draw_aa_vector.c		\
		 draw_vector.c

OFILES = $(CFILES:.c=.o)

$(NAME) :
	$(CC) -c $(CFILES) $(INCLUDEFOLDER) $(LIBFOLDER) $(LIBS) $(CFLAGS)
	$(CC) $(OFILES) $(INCLUDEFOLDER) $(LIBFOLDER) $(LIBS) $(CFLAGS) -o $(NAME)

updatelib :
	cd libft/ && git pull
	make -C libft/ re

complib :
	make -C libft/ re

clean :
	rm -f $(OFILES)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)