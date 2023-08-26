/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:08:53 by arigonza          #+#    #+#             */
/*   Updated: 2023/08/26 13:54:19 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit_on_error(t_stack* stackA, t_stack* stackB)
{
	ft_free_stack(stackA);
	ft_free_stack(stackB);
	ft_printf("Error\n");
	exit(1);
}

void	ft_do_op(char* op, t_stack* stackA, t_stack* stackB)
{
	if (!strcmp(op, "sa\n"))
		ft_sa(stackA);
	else if (!strcmp(op, "pa\n"))
		ft_pa(stackA, stackB);
	else if (!strcmp(op, "sb\n"))
		ft_sb(stackB);
	else if (!strcmp(op, "pb\n"))
		ft_pb(stackB, stackA);
	else if (!strcmp(op, "ss\n"))
		ft_ss(stackA, stackB);
	else if (!strcmp(op, "ra\n"))
		ft_ra(stackA);
	else if (!strcmp(op, "rb\n"))
		ft_rb(stackB);
	else if (!strcmp(op, "rr\n"))
		ft_rr(stackA, stackB);
	else if (!strcmp(op, "rra\n"))
		ft_rra(stackA);
	else if (!strcmp(op, "rrb\n"))
		ft_rrb(stackB);
	else if (!strcmp(op, "rrr\n"))
		ft_rrr(stackA, stackB);
	else
		ft_exit_on_error(stackA, stackB);
}

void    ft_checker(char** argv, int argc)
{
	t_stack	stackA;
	t_stack	stackB;
	int*	parsed;
	char* op;
	
    ft_initialize_stack(&stackA);
	ft_initialize_stack(&stackB);
	op = get_next_line(0);
	if (argc == 2)
		parsed = ft_parse(argv, 0);
	else if (argc > 2)
		parsed = ft_parse(argv, 1);
	ft_fill_stack(&stackA, ft_matrix_size(argv), parsed);
	while (op)
	{
		ft_do_op(op, &stackA, &stackB);
		free(op);
		op = get_next_line(0);
	}
	if (ft_is_sorted(&stackA))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}