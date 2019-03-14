# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroi <aroi@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/14 17:42:00 by aroi              #+#    #+#              #
#    Updated: 2019/03/13 14:36:20 by aroi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra

HEADER	=	-I ./includes

FILES	=	color \
			date_func \
			ft_atoi \
			ft_atoi_base \
			ft_bzero \
			ft_cast_act \
			ft_count_digits \
			ft_count_letters \
			ft_freearr \
			ft_delarr \
			ft_is \
			ft_is_sigil \
			ft_isalnum \
			ft_isalpha \
			ft_isascii \
			ft_isdigit \
			ft_ishex \
			ft_ishexnumber \
			ft_isnum_str \
			ft_isprint \
			ft_itoa \
			ft_itoa_base \
			ft_lstadd \
			ft_lstaddend \
			ft_lstdel \
			ft_lstdelone \
			ft_lstiter \
			ft_lstmap \
			ft_lstnew \
			ft_memalloc \
			ft_memccpy \
			ft_memchr \
			ft_memcmp \
			ft_memcpy \
			ft_memdel \
			ft_memmove \
			ft_memset \
			ft_pow \
			ft_printf \
			ft_putchar \
			ft_putchar_fd \
			ft_putstr \
			ft_putstr_fd \
			ft_putendl \
			ft_putendl_fd \
			ft_putnbr \
			ft_putnbr_fd \
			ft_quicksort_chars \
			ft_strcat \
			ft_strchr \
			ft_strclr \
			ft_strcmp \
			ft_strcpy \
			ft_strdel \
			ft_strdup \
			ft_strequ \
			ft_striter \
			ft_striteri \
			ft_strjoin \
			ft_strlcat \
			ft_strlcpy \
			ft_strlen \
			ft_strmap \
			ft_strmapi \
			ft_strncat \
			ft_strncmp \
			ft_strncpy \
			ft_strnequ \
			ft_strnew \
			ft_strnstr \
			ft_strrchr \
			ft_strsplit \
			ft_strsplittolist \
			ft_strstr \
			ft_strsub \
			ft_strtrim \
			ft_sqrt \
			ft_tolower \
			ft_toupper \
			ft_lower \
			ft_upper \
			ft_uitoa \
			ft_uitoa_base \
			get_next_line \
			out_b \
			out_base \
			out_bin_dec \
			out_c \
			out_date \
			out_int \
			out_uint \
			out_n \
			out_o \
			out_s \
			out_sqrt \
			out_xp_prt_one \
			out_xp_prt_two \
			printf_func \
			qnt_of_bits \
			what_is \
			what_is_pt_two \
			ft_issign \
			ft_capitalize \
			ft_skip_whitespaces \
			ft_abs \
			ft_is_whitespace

SRC = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ = $(addprefix obj/, $(addsuffix .o, $(FILES)))

all: $(NAME)

obj/%.o: src/%.c
	@echo "\033[33mPunch in face!\033[0m"
	@$(CC) $(CFLAGS) -O3 -o $@ -c $^ $(HEADER)

$(NAME): $(OBJ)
	@echo "\033[32mOMG! SO MANY HITS! What is it performing!"
	@echo "The last blow..."
	@ar rcs $(NAME) $(OBJ)
	@echo "And the \033[1m$(NAME)\033[0m\033[32m is ready!\033[0m"

clean:
	@echo "\033[31mTaking out the trash...\033[0m"
	@rm -rf $(OBJ)

fclean: clean
	@echo "\033[1;31m$(NAME)\033[0m\033[31m is out now!\033[0m"
	@rm -rf $(NAME)

re: fclean all
