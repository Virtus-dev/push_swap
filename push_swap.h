/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:00:30 by arigonza          #+#    #+#             */
/*   Updated: 2023/04/19 23:00:38 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line_bonus.h"
# include "libft/includes/ft_printf.h"

typedef struct t_node
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				a_cost;
	int				b_cost;
	struct t_node	*next;
}	t_node;

typedef struct t_stack
{
	t_node	*head;
	int		size;
}	t_stack;

//Colors Start
# define FRED "\033[0;31m"
# define FGREEN "\033[0;32m"
# define FYELLOW "\033[0;33m"
# define FBLUE "\033[0;34m"
# define FPURPLE "\033[0;35m"
# define NONE "\033[0;37m"
//Colors End

void	push_swap(int *parsed, int size);
// list_utils
t_node	*create_node(int value);
t_node	*pop(t_stack *stack);
void	insert_node_head(t_stack *stack, t_node *node);
void	insert_node_tail(t_stack *stack, t_node *node);
void	destroy_node(t_node *node);
// utils
int		ft_matrix_size(char **matrix);
void	ft_free_matrix(char **matrix);
void	ft_push_until_3(t_stack *stack_a, t_stack *stack_b);
int		ft_get_absolute(int nbr);
// stack utils
void	ft_initialize_stack(t_stack *stack);
void	ft_fill_stack(t_stack *stack, int size, int *parsed);
void	ft_free_stack(t_stack *stack);
int		get_max_index(t_stack *stack);
int		ft_get_lowest_index(t_stack *stack_a);
// argv_checker
int		ft_param_checker(int argc, char **argv);
int		*ft_parse(char **splited, int argc);
// param_aux_functions
int		ft_is_sorted(t_stack *stack);
int		ft_isdup(char **argv);
int		ft_is_nbr(char *s);
int		ft_str_nbr_cmp(const char *s1, const char *s2);
// swap operations
void	ft_sa(t_stack *stack_a);
void	ft_sb(t_stack *stack_b);
void	ft_ss(t_stack *stack_a, t_stack *stack_b);
// push operations
void	ft_pa(t_stack *stack_a, t_stack *stack_b);
void	ft_pb(t_stack *stack_b, t_stack *stack_a);
// rotate operations
void	ft_ra(t_stack *stack_a);
void	ft_rb(t_stack *stack_b);
void	ft_rr(t_stack *stack_a, t_stack *stack_b);
void	ft_rotate_a(t_stack *stack_a, int *a_cost);
void	ft_rotate_b(t_stack *stack_b, int *b_cost);
void	ft_rotate_both(t_stack *stack_a, t_stack *stack_b,
			int *a_cost, int *b_cost);
// reverse rotate operations
void	ft_rra(t_stack *stack_a);
void	ft_rrb(t_stack *stack_b);
void	ft_rrr(t_stack *stack_a, t_stack *stack_b);
void	ft_reverse_rotate_both(t_stack *stack_a, t_stack *stack_b,
			int *a_cost, int *b_cost);
// Bonus swap operations
void	ft_sa_bonus(t_stack *stack_a);
void	ft_sb_bonus(t_stack *stack_b);
void	ft_ss_bonus(t_stack *stack_a, t_stack *stack_b);
// Bonus push operations
void	ft_pa_bonus(t_stack *stack_a, t_stack *stack_b);
void	ft_pb_bonus(t_stack *stack_b, t_stack *stack_a);
// Bonus rotate operations
void	ft_ra_bonus(t_stack *stack_a);
void	ft_rb_bonus(t_stack *stack_b);
void	ft_rr_bonus(t_stack *stack_a, t_stack *stack_b);
// Bonus reverse rotate operations
void	ft_rra_bonus(t_stack *stack_a);
void	ft_rrb_bonus(t_stack *stack_b);
void	ft_rrr_bonus(t_stack *stack_a, t_stack *stack_b);
// target manager
void	ft_set_position(t_stack *stack);
int		ft_find_tp(t_stack *stack_a, int b_index);
void	ft_set_target_position(t_stack *stack_a, t_stack *stack_b);
// costs
void	ft_cost(t_stack *stack_a, t_stack *stack_b);
void	ft_choose_cheapest_and_move(t_stack *stack_a, t_stack *stack_b);
void	ft_index_it(t_stack *stack, int stack_size);
// sorting
void	ft_sort_all(t_stack *stack_a, t_stack *stack_b);
void	ft_sort_3(t_stack *stack);
void	ft_shift_stack(t_stack *stack_a);
void	ft_choose_move(t_stack *stack_a, t_stack *stack_b,
			int a_cost, int b_cost);
//checker
void	ft_exit_on_error(t_stack *stack_a, t_stack *stack_b);
void	ft_print_stack(t_stack *stack);

#endif