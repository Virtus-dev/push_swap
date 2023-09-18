# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 13:45:44 by arigonza          #+#    #+#              #
#    Updated: 2023/09/18 19:15:12 by arigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

PUSH_SWAP = push_swap

BONUS = bonus

LIBFT = libft/libft.a

INC = -I libft/includes

SRC = main.c parsing/param_aux_ft.c moves/a_moves.c moves/b_moves.c moves/double_moves.c \
	stack_utils/list_utils.c \
	utils.c parsing/argv_checker.c stack_utils/stack_utils.c \
	position/position_manager.c position/target_manager.c sorting/sorting.c \
	cost.c

SRC_BONUS = checkers/checker.c parsing/param_aux_ft.c moves/bonus_a_moves.c moves/bonus_b_moves.c moves/bonus_double_moves.c \
	stack_utils/list_utils.c \
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
	@rm $(OBJ)
	@echo 🔥🔥 Deleting all .o files 🗑️ 🗑️

fclean : clean
	@echo executing fclean...
	@make -C libft fclean
	@rm -rf $(PUSH_SWAP)
	@rm -rf checker
	@rm $(OBJ_BONUS)
	@echo 🔥🔥deleted executables files 🗑️ 🗑️

py : all
	python3 visualizer.py `ruby -e "puts (-24..25).to_a.shuffle.join(' ')"`

re : fclean all

phony : all clean fclean re

$(BONUS) :	$(OBJ_BONUS) $(LIBFT)
	@echo "COMPILING BONUS"
	@gcc $(CFLAGS) $(INC) -o checker $(SRC_BONUS) $(LIBFT)