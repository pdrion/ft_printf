#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 14:19:39 by pdrion            #+#    #+#              #
#    Updated: 2020/11/11 23:06:46 by pdrion           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= libftprintf.a

SRCS		=	ft_printf.c\
				ft_libft.c\


OBJS		= $(SRCS:.c=.o)

CC			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror

all:		$(NAME)
f:			all
			gcc libftprintf.a

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re: fclean all
