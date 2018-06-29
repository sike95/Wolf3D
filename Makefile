# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/15 08:30:31 by mmpofu            #+#    #+#              #
#    Updated: 2017/11/23 08:17:57 by mmpofu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = wolf3d

CC = gcc

SRC = *.c

BIN = $(SRC:.c=.o)

HEAD = wolf3d.h

FLAGS = -Wall -Werror -Wextra -g -g3

LIB = -L libft -lft

TFLAGS = -lSDL2 -I includes/SDL2/ -L ~/lib

all: $(NAME)

$(NAME):
	gunzip -c SDL2-2.0.5.tar.gz | tar xf -
	cd SDL2-2.0.5; \
		mkdir build; \
		cd build; \
		../configure; \
		make
	mkdir -p ~/lib/
	cp SDL2-2.0.5/build/build/.libs/libSDL2-2.0.0.dylib ~/lib/
	ln -F -s ~/lib/libSDL2-2.0.0.dylib ~/lib/libSDL2.dylib
	mkdir -p includes/SDL2
	cp SDL2-2.0.5/include/*.h includes/SDL2/ 
	make -C libft/ fclean && make -C libft/
	clang $(FLAGS) $(TFLAGS) $(SRC) $(LIB) -o $(NAME)

run:
	 clang $(FLAGS) $(TFLAGS) $(SRC) $(LIB) -o $(NAME)
	./$(NAME)

clean:
	@rm -f $(BIN)
fclean: clean
	@rm -f $(NAME)
	rm -rf includes/SDL2
	rm -rf SDL2-2.0.5
re: fclean all
