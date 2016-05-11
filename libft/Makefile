# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabril <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 12:46:26 by pabril            #+#    #+#              #
#    Updated: 2016/04/20 11:57:36 by pabril           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_atoi.c \
	  ft_atol.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_isupper.c \
	  ft_islower.c \
	  ft_isspace.c \
	  ft_isnumeric.c \
	  ft_itoa.c \
	  ft_lstadd.c \
	  ft_lstpushback.c \
	  ft_lstdel.c \
	  ft_lstdelone.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_lstnew.c \
	  ft_memalloc.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memdel.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar.c \
	  ft_putchar_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strclr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdel.c \
	  ft_strdup.c \
	  ft_strequ.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strnequ.c \
	  ft_strnew.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strsplit.c \
	  ft_strstr.c \
	  ft_strsub.c \
	  ft_strtrim.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_printf.c \
	  ft_print.c \
	  ft_print2.c \
	  check_arguments.c \
	  ft_flags_ops.c \
	  ft_string_case.c \
	  n_case.c \
	  ft_ptr_case.c \
	  ft_percent_case.c \
	  ft_wide_chars.c \
	  ft_number_case.c \
	  ft_noflag_signed_nb.c \
	  ft_handle_numbers.c \
	  ft_handle_unsigned.c \
	  ft_printxo.c \
	  ft_strlen_wide.c \
	  ft_len_numbers.c \
	  ft_putcharn.c \
	  ft_power.c \
	  ft_abs.c \
	  ft_ceil.c \
	  ft_cos.c \
	  ft_degtorad.c \
	  ft_fabs.c \
	  ft_fact.c \
	  ft_floor.c \
	  ft_fmod.c \
	  ft_pow.c \
	  ft_labs.c \
	  ft_modf.c \
	  ft_radtodeg.c \
	  ft_sin.c \
	  ft_tan.c \
	  get_next_line.c

INC = includes/libft.h includes/ft_printf.h includes/get_next_line.h

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@echo "building library"
	@$(CC) $(FLAGS) -c $(SRC) -I includes
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@echo "delete *.o"
	@rm -f *.o

fclean: clean
	@echo "delete $(NAME)"
	@rm -f libft.a

re: fclean all

