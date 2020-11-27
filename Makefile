#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/27 16:36:46 by pdrion            #+#    #+#              #
#    Updated: 2020/11/27 23:54:03 by pdrion           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

C = gcc

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

DIR_S = srcs

DIR_O = obj

HEADER = includes

SOURCES =	ft_printf.c\
			ft_libft.c\
			ft_parser.c\
			ft_format.c\
			ft_str_treatment.c\
			ft_nbr_treatment.c\
			ft_printf_initialize.c\

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[32m      :::::::::  :::::::::  ::::::::::: ::::    ::: ::::::::::: :::::::::: "
	@echo "\033[32m     :+:    :+: :+:    :+:     :+:     :+:+:   :+:     :+:     :+:         "
	@echo "\033[32m    +:+    +:+ +:+    +:+     +:+     :+:+:+  +:+     +:+     +:+          "
	@echo "\033[32m   +#++:++#+  +#++:++#:      +#+     +#+ +:+ +#+     +#+     :#::+::#      "
	@echo "\033[32m  +#+        +#+    +#+     +#+     +#+  +#+#+#     +#+     +#+            "
	@echo "\033[32m #+#        #+#    #+#     #+#     #+#   #+#+#     #+#     #+#             "
	@echo "\033[32m###        ###  :::::::::##:::###:::#    ####     ###     ###              "
	@echo "\033[32m               :+:    :+: :+:   :+:                                        "
	@echo "\033[32m              +:+    +:+  +:+ +:+                                          "
	@echo "\033[32m             +#++:++#+    +#++:                                            "
	@echo "\033[32m            +#+    +#+    +#+                                              "
	@echo "\033[32m           #+#    #+#    #+#                                               "
	@echo "\033[32m      :::::::::##:::::::::# :::::::::  ::::::::::: ::::::::  ::::    :::   "
	@echo "\033[32m     :+:    :+: :+:    :+: :+:    :+:     :+:    :+:    :+: :+:+:   :+:    "
	@echo "\033[32m    +:+    +:+ +:+    +:+ +:+    +:+     +:+    +:+    +:+ :+:+:+  +:+     "
	@echo "\033[32m   +#++:++#+  +#+    +:+ +#++:++#:      +#+    +#+    +:+ +#+ +:+ +#+      "
	@echo "\033[32m  +#+        +#+    +#+ +#+    +#+     +#+    +#+    +#+ +#+  +#+#+#       "
	@echo "\033[32m #+#        #+#    #+# #+#    #+#     #+#    #+#    #+# #+#   #+#+#        "
	@echo "\033[32m###        #########  ###    ### ########### ########  ###    ####         "
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)	
	@ranlib $(NAME)
	@echo "\033[1;34mft_printf\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/ft_printf.h
	@mkdir -p obj
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<


norme:
	@echo "\033[1;34mft_printf\t\033[1;33mNorminette\t\033[0;32m[Libft source]\033[0m"
	@~/.norminette/norminette.rb ./libft/srcs/
	@echo "\033[1;34mft_printf\t\033[1;33mNorminette\t\033[0;32m[ft_printf source]\033[0m"
	@~/.norminette/norminette.rb $(DIR_S)
	@echo "\033[1;34mft_printf\t\033[1;33mNorminette\t\033[0;32m[Headers]\033[0m"
	@~/.norminette/norminette.rb $(HEADER)


m:
	@make all
	@$(CC) $(NAME)  main.c -fsanitize=address
	@./a.out
t:
	@make all
	@$(CC) $(NAME)  testeur.c -fsanitize=address
	@./a.out

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)
	@echo "\033[1;34mft_printf \t\033[1;33mCleaning\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: fclean re norme all clean

