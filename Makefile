# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/28 05:03:25 by cfeijoo           #+#    #+#              #
#    Updated: 2013/12/19 19:07:57 by cfeijoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
INCLUDEFOLDER = -I./includes/ -I./libft/includes/
LIBFOLDER = -L/usr/X11/lib/ -L./libft/
LIBS = -lmlx -lXext -lX11 -lft
CFLAGS = -Wall -Werror -Wextra

CC = gcc
CFILES = main.c			\
		 blend_color.c	\
		 draw_vector.c

OFILES = $(CFILES:.c=.o)

$(NAME) : clean
	make -C libft/ re
	$(CC) -c $(INCLUDEFOLDER) $(CFLAGS) $(CFILES)
	$(CC) $(LIBFOLDER) $(LIBS) $(INCLUDEFOLDER) $(CFLAGS) $(OFILES) -o $(NAME)

clean :
	if [ -f $(OFILES) ];	\
		then rm $(OFILES);	\
	fi
