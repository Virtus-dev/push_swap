/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:58:16 by arigonza          #+#    #+#             */
/*   Updated: 2023/09/13 16:52:28 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_3(t_stack* stack)
{
	int	max_index;
	Node*	current;

	current = stack->head;
	max_index = get_max_index(stack);
	if (current->index == max_index)
		ft_ra(stack);
		if (!ft_is_sorted(stack))
			ft_sa(stack);
	else if (current->next->index == max_index)
		ft_rra(stack);
		if (!ft_is_sorted(stack))
			ft_sa(stack);
	else if ((current->next->next->index == max_index) && !ft_is_sorted(stack))
		ft_sa(stack);
}

void	ft_sort_all(t_stack* stackA, t_stack* stackB)
{
	ft_push_until_3(stackA, stackB);
	ft_sort_3(stackA);
	while (stackB)
	{
		ft_set_target_position(stackA, stackB);
		ft_cost(stackB);
		ft_choose_cheapest_and_move(stackA, stackB);
	}
	if (!ft_is_sorted(StackA))
		ft_shift_stack(stackA);
}

void    ft_choose_move(t_stack* stackA, t_stack* stackB, int a_cost, int b_cost)
{
    if (a_cost > 0 && b_cost > 0)
        ft_rotate_both(stackA, stackB, &a_cost, &b_cost);
    if (a_cost < 0 && b_cost < 0)
        ft_reverse_rotate_both(stackA, stackB, &a_cost, &b_cost);
	ft_rotate_a(stackA);
	ft_rotate_b(stackB);
	ft_pa(stackA, stackB);
}

void	ft_shift_stack(t_stack* stackA)
{
	int	stack_size;
	int	lower_index;

	stack_size = ft_stack_size(stackA);
	lowest_index = ft_get_lowest_index(stackA);
	
	if (lowest_index < (stack_size / 2))
	{
		while (lowest > 0)
		{
			ft_ra(stackA);
			lowest_index--;
		}
	}
	else (lowest_index > (stack_size / 2))
	{
		while (lowest_index < stack_size)
		{
			ft_rra(stackA);
			lowest_index++;
		}
	}
}