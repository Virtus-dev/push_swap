# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 13:45:44 by arigonza          #+#    #+#              #
#    Updated: 2023/09/19 16:57:56 by arigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

FSANITIZE = -fsanitize=address -g

PUSH_SWAP = push_swap

BONUS = bonus

LIBFT = libft/libft.a

INC = -I libft/includes

SRC = push_swap.c parsing/param_aux_ft.c moves/a_moves.c moves/b_moves.c moves/double_moves.c \
	stack_utils/list_utils.c \
	utils.c parsing/argv_checker.c stack_utils/stack_utils.c \
	position/position_manager.c position/target_manager.c sorting/sorting.c \
	cost.c

SRC_BONUS = checkers/checker.c moves/bonus_a_moves.c moves/bonus_b_moves.c moves/bonus_double_moves.c \


OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

all : $(PUSH_SWAP)

$(PUSH_SWAP) : $(LIBFT) $(OBJ) main.o
	@echo "|---------------------------|"
	@echo "|  Compiling Push_swap🤖🤖  |"
	@echo "|---------------------------|"
	@gcc $(CFLAGS) $(INC) -o $(PUSH_SWAP) $(SRC) main.c $(LIBFT)

$(LIBFT) :
	@make -s -C libft
	@echo "|---------------------------|"
	@echo "|    Compiling libft📚📚    |"
	@echo "|---------------------------|"

clean :
	@make -s -C libft clean
	@rm $(OBJ) main.o
	@echo 🔥🔥 Deleting all .o files 🗑️ 🗑️

fclean : clean clean_bonus
	@echo executing fclean...
	@rm -rf $(PUSH_SWAP) checker
	@echo 🔥🔥deleted executables files 🗑️ 🗑️

clean_bonus :
	@rm $(OBJ_BONUS)
	@echo Deleting bonus files.

py : all
	python3 visualizer.py `ruby -e "puts (-249..250).to_a.shuffle.join(' ')"`

re : fclean all

phony : all clean fclean re

$(BONUS) : $(OBJ_BONUS) $(LIBFT) $(PUSH_SWAP)
	@echo "COMPILING BONUS"
	@gcc $(CFLAGS) $(INC) -o checker $(SRC) $(SRC_BONUS) $(LIBFT)