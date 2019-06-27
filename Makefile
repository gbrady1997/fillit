# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabrady <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/03 19:23:33 by gabrady           #+#    #+#              #
#    Updated: 2019/06/04 12:44:58 by gabrady          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = fillit.h

CFILES =	check_file.c \
					check_tetri.c \
					compare_tetri.c \
					embiggen_square.c \
					error_put.c \
					find_length_height.c \
					main.c \
					make_square.c \
					put_tet.c \
					read_tetri.c \
					recursive_solve.c \
					solved.c \
					take_tet.c \

OFILES =	check_file.o \
					check_tetri.o \
					compare_tetri.o \
					embiggen_square.o \
					error_put.o \
					find_length_height.o \
					main.o \
					make_square.o \
					put_tet.o \
					read_tetri.o \
					recursive_solve.o \
					solved.o \
					take_tet.o \

LIBFT = libft.a

LCFILES = ./libft/ft_memset.c \
		 ./libft/ft_bzero.c \
		 ./libft/ft_memcpy.c \
		 ./libft/ft_memccpy.c \
		 ./libft/ft_memmove.c \
		 ./libft/ft_memchr.c \
		 ./libft/ft_memcmp.c \
		 ./libft/ft_strlen.c \
		 ./libft/ft_strdup.c \
		 ./libft/ft_strcpy.c \
		 ./libft/ft_strncpy.c \
		 ./libft/ft_strcat.c \
		 ./libft/ft_strncat.c \
		 ./libft/ft_strlcat.c \
		 ./libft/ft_strchr.c \
		 ./libft/ft_strrchr.c \
		 ./libft/ft_strstr.c \
		 ./libft/ft_strnstr.c \
		 ./libft/ft_strcmp.c \
		 ./libft/ft_strncmp.c \
		 ./libft/ft_atoi.c \
		 ./libft/ft_isalpha.c \
		 ./libft/ft_isdigit.c \
		 ./libft/ft_isalnum.c \
		 ./libft/ft_isascii.c \
		 ./libft/ft_isprint.c \
		 ./libft/ft_toupper.c \
		 ./libft/ft_tolower.c \
		 ./libft/ft_memalloc.c \
		 ./libft/ft_memdel.c \
		 ./libft/ft_strnew.c \
		 ./libft/ft_strdel.c \
		 ./libft/ft_strclr.c \
		 ./libft/ft_striter.c \
		 ./libft/ft_striteri.c \
		 ./libft/ft_strmap.c \
		 ./libft/ft_strmapi.c \
		 ./libft/ft_strequ.c \
		 ./libft/ft_strnequ.c \
		 ./libft/ft_strsub.c \
		 ./libft/ft_strjoin.c \
		 ./libft/ft_strtrim.c \
		 ./libft/ft_strsplit.c \
		 ./libft/ft_itoa.c \
		 ./libft/ft_putchar.c \
		 ./libft/ft_putstr.c \
		 ./libft/ft_putendl.c \
		 ./libft/ft_putnbr.c \
		 ./libft/ft_putchar_fd.c \
		 ./libft/ft_putstr_fd.c \
		 ./libft/ft_putendl_fd.c \
		 ./libft/ft_putnbr_fd.c \
		 ./libft/ft_lstnew.c \
		 ./libft/ft_lstdelone.c \
		 ./libft/ft_lstdel.c \
		 ./libft/ft_lstadd.c \
		 ./libft/ft_lstiter.c \
		 ./libft/ft_lstmap.c \
		 ./libft/get_next_line2.c \
		 ./libft/add_new_line.c \

LOFILES = ./ft_memset.o \
		  ./ft_bzero.o \
		  ./ft_memcpy.o \
		  ./ft_memccpy.o \
		  ./ft_memmove.o \
		  ./ft_memchr.o \
		  ./ft_memcmp.o \
		  ./ft_strlen.o \
		  ./ft_strdup.o \
		  ./ft_strcpy.o \
		  ./ft_strncpy.o \
		  ./ft_strcat.o \
		  ./ft_strncat.o \
		  ./ft_strlcat.o \
		  ./ft_strchr.o \
		  ./ft_strrchr.o \
		  ./ft_strstr.o \
		  ./ft_strnstr.o \
		  ./ft_strcmp.o \
		  ./ft_strncmp.o \
		  ./ft_atoi.o \
		  ./ft_isalpha.o \
		  ./ft_isdigit.o \
		  ./ft_isalnum.o \
		  ./ft_isascii.o \
		  ./ft_isprint.o \
		  ./ft_toupper.o \
		  ./ft_tolower.o \
		  ./ft_memalloc.o \
		  ./ft_memdel.o \
		  ./ft_strnew.o \
		  ./ft_strdel.o \
		  ./ft_strclr.o \
		  ./ft_striter.o \
		  ./ft_striteri.o \
		  ./ft_strmap.o \
		  ./ft_strmapi.o \
		  ./ft_strequ.o \
		  ./ft_strnequ.o \
		  ./ft_strsub.o \
		  ./ft_strjoin.o \
		  ./ft_strtrim.o \
		  ./ft_strsplit.o \
		  ./ft_itoa.o \
		  ./ft_putchar.o \
		  ./ft_putstr.o \
		  ./ft_putendl.o \
		  ./ft_putnbr.o \
		  ./ft_putchar_fd.o \
		  ./ft_putstr_fd.o \
		  ./ft_putendl_fd.o \
		  ./ft_putnbr_fd.o \
		  ./ft_lstnew.o \
		  ./ft_lstdelone.o \
		  ./ft_lstdel.o \
		  ./ft_lstadd.o \
		  ./ft_lstiter.o \
		  ./ft_lstmap.o \
		  ./get_next_line2.o \
		  ./add_new_line.o \

LHEADER = libft/libft.h

all: $(NAME)

$(NAME): $(LOFILES)
	ar rc $(LIBFT) $(LOFILES)
	ranlib $(LIBFT)
	$(CC) $(CFLAGS) -I=$(HEADER) -o $(NAME) $(CFILES) $(LIBFT)

$(LOFILES): $(LCFILES)
	$(CC) -c $(CFLAGS) -I=$(LHEADER) $(LCFILES)

clean:
	rm -rf $(OFILES) $(LOFILES)

fclean:
	rm -rf $(NAME) $(LIBFT) $(OFILES) $(LOFILES)

re: fclean all

.PHONY: clean fclean all re
