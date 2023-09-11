/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:58:16 by arigonza          #+#    #+#             */
/*   Updated: 2023/09/11 17:25:31 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void    ft_move_chose(t_stack* stackA, t_stack* stackB, int a_cost, int b_cost)
{
    if (a_cost > 0 && b_cost > 0)
        ft_rotate_both(stackA, stackB, &a_cost, &b_cost);
    if (a_cost < 0 && b_cost < 0)
        ft_reverse_rotate_both(stackA, stackB, *a_cost, *b_cost);
}