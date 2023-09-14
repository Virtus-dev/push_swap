# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 13:45:44 by arigonza          #+#    #+#              #
#    Updated: 2023/09/14 19:02:26 by arigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

PUSH_SWAP = push_swap

BONUS = checker

LIBFT = libft/libft.a

INC = -I libft/includes

SRC = main.c parsing/param_aux_ft.c push_swap.c stack_utils/list_utils.c \
	utils.c parsing/argv_checker.c stack_utils/stack_utils.c \
	position/position_manager.c position/target_manager.c sorting/sorting.c \
	cost.c

SRC_BONUS = checkers/checker.c parsing/param_aux_ft.c push_swap.c stack_utils/list_utils.c \
	utils.c parsing/argv_checker.c stack_utils/stack_utils.c \
	position/position_manager.c position/target_manager.c sorting/sorting.c \
	cost.c

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

all : $(PUSH_SWAP)

$(PUSH_SWAP) : $(LIBFT) $(OBJ)
	@echo "|---------------------------|"
	@echo "|  Compiling Push_swap🤖🤖  |"
	@echo "|---------------------------|"
	@gcc $(CFLAGS) $(INC) -o $(PUSH_SWAP) $(SRC) $(LIBFT)

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
	@rm -rf $(BONUS)
	@rm $(OBJ)
	@echo 🔥🔥deleted executables files 🗑️ 🗑️

py : all
	python3 visualizer.py `ruby -e "puts (-249..250).to_a.shuffle.join(' ')"`

re : fclean all

phony : all clean fclean re

$(BONUS) :	$(OBJ_BONUS) $(LIBFT)
	@echo "COMPILING BONUS"
	@gcc $(CFLAGS) $(INC) -o checker $(SRC_BONUS) $(LIBFT)