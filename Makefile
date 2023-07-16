# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 13:45:44 by arigonza          #+#    #+#              #
#    Updated: 2023/07/10 15:57:54 by arigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

PUSH_SWAP = push_swap

LIBFT = libft/libft.a

INC = -I libft/includes

SRC = main.c param_aux_ft.c push_swap.c list_utils.c \
	utils.c argv_checker.c stack_utils.c \

BONUS = checker.c

OBJ = ${SRC:.c=.o}

all : $(PUSH_SWAP)

$(PUSH_SWAP) : $(LIBFT) $(SRC)
	@echo "|---------------------------|"
	@echo "|  Compiling Push_swap🤖🤖  |"
	@echo "|---------------------------|"
	@gcc $(CFLAGS) -g $(INC) -o $(PUSH_SWAP) $(SRC) $(LIBFT) $(BONUS)

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

re : fclean all

py : all
	python3 python_visualizer.py `ruby -e "puts (-50..50).to_a.shuffle.join(' ')"`

phony : all clean fclean re py