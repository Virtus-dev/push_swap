/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:48:26 by arigonza          #+#    #+#             */
/*   Updated: 2023/09/19 16:49:01 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int *parsed, int size)
{
	t_stack	stack_a;
	t_stack	stack_b;

	ft_initialize_stack(&stack_a);
	ft_initialize_stack(&stack_b);
	while (0 < size)
	{
		insert_node_head(&stack_a, create_node(parsed[size - 1]));
		size--;
	}
	ft_index_it(&stack_a, stack_a.size);
	if (!ft_is_sorted(&stack_a))
	{
		if (stack_a.size == 2)
			ft_sa(&stack_a);
		if (stack_a.size == 3)
			ft_sort_3(&stack_a);
		else
			ft_sort_all(&stack_a, &stack_b);
	}
	free(parsed);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
}
