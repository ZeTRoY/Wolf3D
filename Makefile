# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroi <aroi@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/04 15:35:03 by aroi              #+#    #+#              #
#    Updated: 2019/03/12 17:34:11 by aroi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	wolf3d
FLAGS	=	-Wall -Werror -Wextra

FILES	=	main \
			initialisation \
			events \
			error

HEADERS	=	-I ./includes/ -I ./libft/includes \
			-I ./frameworks/SDL2.framework/Headers \
			-I ./frameworks/SDL2_image.framework/Headers \
			-I ./frameworks/SDL2_ttf.framework/Headers

FRAMEWORKS = -F ./frameworks -rpath ./frameworks -framework SDL2 \
			-framework SDL2_image -framework SDL2_ttf

SRC		=	$(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ		=	$(addprefix obj/, $(addsuffix .o, $(FILES)))

obj/%.o: src/%.c
	gcc -o $@ -c $^ $(HEADERS)

all: $(NAME)

$(NAME): libft/libft.a $(OBJ)
	gcc $(OBJ) $(FLAGS) $(HEADERS) $(FRAMEWORKS) -L libft -lft -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
