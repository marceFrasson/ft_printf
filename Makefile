# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/20 18:13:06 by mfrasson          #+#    #+#              #
#    Updated: 2021/03/22 04:33:36 by mfrasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang
CFLAGS	= -Wall -Wextra -Werror
RM		= /bin/rm -f

NAME	= libftprintf.a

SRCS	= print_alpha.c print_digit.c ft_itoa_hex.c ft_printf.c print_hexa.c utils_a.c \
		utils_b.c utils_c.c utils_format.c

OBJS	= $(SRCS:.c=.o)

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re