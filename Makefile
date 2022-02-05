# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 12:10:58 by jmabel            #+#    #+#              #
#    Updated: 2021/12/12 11:24:27 by jmabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	libftprintf.a

SRCS_DIR_lib	=	./ft_libft_utils/
SRCS_DIR_spec	=	./ft_printf_specifier/
SRCS_DIR_lib_B	=	./ft_libft_utils_bonus/
SRCS_DIR_spec_B	=	./ft_printf_specifier_bonus/

SRCS 			=	ft_printf.c\
					$(SRCS_DIR_spec)ft_single_character.c			$(SRCS_DIR_spec)ft_string_of_characters.c\
					$(SRCS_DIR_spec)ft_pointer_argument.c			$(SRCS_DIR_spec)ft_decimal_integer.c\
					$(SRCS_DIR_spec)ft_unsigned_decimal.c			$(SRCS_DIR_spec)ft_hexadecimal_lowercase.c\
					$(SRCS_DIR_spec)ft_hexadecimal_uppercase.c		$(SRCS_DIR_spec)ft_percent_sign.c\
					$(SRCS_DIR_lib)ft_longlen.c						$(SRCS_DIR_lib)ft_putchar_fd.c\
					$(SRCS_DIR_lib)ft_putnbr_fd.c					$(SRCS_DIR_lib)ft_putstr_fd.c\
					$(SRCS_DIR_lib)ft_strlen.c						$(SRCS_DIR_lib)ft_putnbr_unsigned.c

SRCS_B			= 	ft_printf_bonus.c\
					$(SRCS_DIR_spec_B)ft_parsers_bonus.c			$(SRCS_DIR_spec_B)ft_percent_sign_bonus.c\
					$(SRCS_DIR_spec_B)ft_single_character_bonus.c	$(SRCS_DIR_spec_B)ft_string_of_characters_bonus.c\
					$(SRCS_DIR_spec_B)ft_pointer_argument_bonus.c	$(SRCS_DIR_spec_B)ft_hexademical_bonus.c\
					$(SRCS_DIR_spec_B)ft_decimal_integer_bonus.c	$(SRCS_DIR_spec_B)ft_precision_bonus.c\
					$(SRCS_DIR_spec_B)ft_modified_width_bonus.c		$(SRCS_DIR_spec_B)ft_unsigned_decimal_bonus.c\
					$(SRCS_DIR_spec_B)ft_hexadecimal_lowercase_bonus.c\
					$(SRCS_DIR_spec_B)ft_hexadecimal_uppercase_bonus.c\
					$(SRCS_DIR_spec_B)ft_percent_sign_bonus.c\
					$(SRCS_DIR_lib_B)ft_isdigit_bonus.c				$(SRCS_DIR_lib_B)ft_putstr_fd_bonus.c\
					$(SRCS_DIR_lib_B)ft_putchar_fd_bonus.c			$(SRCS_DIR_lib_B)ft_strlen_bonus.c\
					$(SRCS_DIR_lib_B)ft_atoi_bonus.c				$(SRCS_DIR_lib_B)ft_fillstrbysymb_bonus.c\
					$(SRCS_DIR_lib_B)ft_strjoin_bonus.c				$(SRCS_DIR_lib_B)ft_substr_bonus.c\
					$(SRCS_DIR_lib_B)ft_strdup_bonus.c					$(SRCS_DIR_lib_B)ft_longlen_bonus.c\
					$(SRCS_DIR_lib_B)ft_itoa_bonus.c\

HEADER 			=	ft_printf.h
HEADER_B		=	ft_printf_bonus.h

OBJ 			= 	$(SRCS:%.c=%.o)
OBJ_B			=	$(SRCS_B:%.c=%.o)
RM 				= 	rm -rf
CC 				= 	cc 
CFLAGS 			= 	-Wall -Wextra -Werror

.PHONY			:	all clean fclean re bonus

all				:	$(NAME)

$(NAME)			:	$(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o				: %.c $(HEADER) $(HEADER_B)
	$(CC) $(CFLAGS) -c $< -o $@

bonus			: $(OBJ_B)
	make OBJ="$(OBJ_B)" all

clean 			:
	$(RM) $(OBJ) $(OBJ_B)

fclean			: clean
	$(RM) $(NAME)
	
re			: fclean all
