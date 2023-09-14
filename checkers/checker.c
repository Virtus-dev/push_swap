/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:08:53 by arigonza          #+#    #+#             */
/*   Updated: 2023/09/14 18:51:34 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void    ft_checker(char** argv,int* parsed)
{
	t_stack	stackA;
	t_stack	stackB;
	char* op;
	
    ft_initialize_stack(&stackA);
	ft_initialize_stack(&stackB);
	op = get_next_line(0);
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

int main(int argc, char** argv)
{
	int size;
    int* parsed;
	char** splited;

    parsed = NULL;
    if (argc > 1)
    {
        if (!ft_param_checker(argc, argv))
        {
            ft_printf("Error\n");
        }
        else
        {
            if (argc == 2)
            {
                splited = ft_split(argv[1], ' ');
                size = ft_matrix_size(splited);
                parsed = ft_parse(splited, 0);
				ft_checker(argv, parsed);
                ft_free_matrix(splited);
            }
            else
            {
                size = (ft_matrix_size(argv) - 1);
                parsed = ft_parse(argv, 1);
				ft_checker(argv, parsed);
            }
        }
        free(parsed);
    }
    return 0;
}