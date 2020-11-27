#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/30 18:47:17 by pdrion            #+#    #+#              #
#    Updated: 2020/11/27 19:22:31 by pdrion           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

C = gcc

NAME		= libft.a

FLAGS = -Wall -Wextra -Werror

DIR_S = srcs

DIR_O = obj

HEADER = ../includes

SOURCES		= ft_memset.c \
			  ft_bzero.c \
			  ft_memcpy.c \
			  ft_memccpy.c \
			  ft_memmove.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_strlen.c \
			  ft_isalpha.c \
			  ft_isdigit.c \
			  ft_isalnum.c \
			  ft_isascii.c \
			  ft_isprint.c \
			  ft_toupper.c \
			  ft_tolower.c \
			  ft_strchr.c \
			  ft_strrchr.c \
			  ft_strncmp.c \
			  ft_strlcpy.c \
			  ft_strlcat.c \
			  ft_strnstr.c \
			  ft_atoi.c \
			  ft_calloc.c \
			  ft_strdup.c \
			  ft_substr.c \
			  ft_strtrim.c \
			  ft_strjoin.c \
			  ft_split.c \
			  ft_itoa.c \
			  ft_strmapi.c \
			  ft_putchar_fd.c \
			  ft_putstr_fd.c \
			  ft_putendl_fd.c \
			  ft_putnbr_fd.c \
			  ft_lstnew.c \
			  ft_lstadd_front.c \
			  ft_lstsize.c \
			  ft_lstlast.c \
			  ft_lstadd_back.c \
			  ft_lstdelone.c \
			  ft_lstclear.c \
			  ft_lstiter.c \
			  ft_lstmap.c \

SRCS = $(addprefix /,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SRCS:.c=.o))

RM			= rm -rf

all:		$(NAME)

$(NAME):	$(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[1;34mLibft\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/libft.h
	@mkdir -p obj
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@$(RM) $(OBJS)
	@$(RM) $(DIR_O)
	@echo "\033[1;34mLibft \t\033[1;33mCleaning\t\033[0;32m[OK]\033[0m"

fclean:		clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean re norme all clean
