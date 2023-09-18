/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:08:53 by arigonza          #+#    #+#             */
/*   Updated: 2023/09/18 18:43:26 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_leaks(void)
{
	system("leaks -q checker");
}

void	ft_exit_on_error(t_stack *stack_a, t_stack *stack_b)
{
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	ft_printf("Error\n");
	exit(1);
}

void	ft_do_op(char *op, t_stack *stack_a, t_stack *stack_b)
{
	if (!strcmp(op, "sa\n"))
		ft_sa(stack_a);
	else if (!strcmp(op, "pa\n"))
		ft_pa(stack_a, stack_b);
	else if (!strcmp(op, "sb\n"))
		ft_sb(stack_b);
	else if (!strcmp(op, "pb\n"))
		ft_pb(stack_b, stack_a);
	else if (!strcmp(op, "ss\n"))
		ft_ss(stack_a, stack_b);
	else if (!strcmp(op, "ra\n"))
		ft_ra(stack_a);
	else if (!strcmp(op, "rb\n"))
		ft_rb(stack_b);
	else if (!strcmp(op, "rr\n"))
		ft_rr(stack_a, stack_b);
	else if (!strcmp(op, "rra\n"))
		ft_rra(stack_a);
	else if (!strcmp(op, "rrb\n"))
		ft_rrb(stack_b);
	else if (!strcmp(op, "rrr\n"))
		ft_rrr(stack_a, stack_b);
	else
		ft_exit_on_error(stack_a, stack_b);
}

void	ft_checker(int size, int *parsed)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	*op;

	ft_initialize_stack(&stack_a);
	ft_initialize_stack(&stack_b);
	ft_fill_stack(&stack_a, size, parsed);
	op = get_next_line(0);
	while (op)
	{
		ft_do_op(op, &stack_a, &stack_b);
		free(op);
		op = get_next_line(0);
	}
	if (ft_is_sorted(&stack_a) && stack_b.size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
}

int	main(int argc, char **argv)
{
	int		size;
	char	**splited;

	if (argc > 1)
	{
		if (!ft_param_checker(argc, argv))
			ft_printf("Error\n");
		else
		{
			if (argc == 2)
			{
				splited = ft_split(argv[1], ' ');
				size = ft_matrix_size(splited);
				ft_checker(size, ft_parse(splited, 0));
				ft_free_matrix(splited);
			}
			else
			{
				size = (ft_matrix_size(argv) - 1);
				ft_checker(size, ft_parse(argv, 1));
			}
		}
	}
	return (0);
}
