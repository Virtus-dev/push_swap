# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 13:45:44 by arigonza          #+#    #+#              #
#    Updated: 2023/08/30 13:21:26 by arigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

PUSH_SWAP = push_swap

LIBFT = libft/libft.a

INC = -I libft/includes

SRC = main.c param_aux_ft.c push_swap.c list_utils.c \
	utils.c argv_checker.c stack_utils.c \

OBJ = ${SRC:.c=.o}

all : $(PUSH_SWAP)

$(PUSH_SWAP) : $(LIBFT) $(SRC)
	@echo "|---------------------------|"
	@echo "|  Compiling Push_swap🤖🤖  |"
	@echo "|---------------------------|"
	@gcc $(CFLAGS) -g $(INC) -o $(PUSH_SWAP) $(SRC) $(LIBFT)

$(LIBFT) :
	@make -s -C libft
	@echo "|---------------------------|"
	@echo "|    Compiling libft📚📚    |"
	@echo "|---------------------------|"

clean :
	@make -s -C libft clean
	@echo 🔥🔥 Deleting all .o files 🗑️ 🗑️

fclean : clean
	@echo executing fclean...
	@make -C libft fclean
	@rm -rf $(PUSH_SWAP)
	@echo 🔥🔥deleted executables files 🗑️ 🗑️

py : all
	python3 visualizer.py `ruby -e "puts (-250..249).to_a.shuffle.join(' ')"`

re : fclean all

phony : all clean fclean re
