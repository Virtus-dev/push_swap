/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:40:07 by arigonza          #+#    #+#             */
/*   Updated: 2023/09/18 18:25:57 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_a;
	t_node	*current_b;

	current_a = stack_a->head;
	current_b = stack_b->head;
	while (current_b)
	{
		current_b->b_cost = current_b->pos;
		if (current_b->pos > (stack_b->size / 2))
			current_b->b_cost = (stack_b->size - current_b->pos) * -1;
		current_b->a_cost = current_b->target_pos;
		if (current_b->target_pos > (stack_a->size / 2))
			current_b->a_cost = (stack_a->size - current_b->target_pos) * -1;
		current_b = current_b->next;
	}
}

void	ft_choose_cheapest_and_move(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	int		cheapest;
	int		a_cost;
	int		b_cost;

	current = stack_b->head;
	cheapest = INT_MAX;
	while (current)
	{
		if (ft_get_absolute(current->a_cost) + \
			ft_get_absolute(current->b_cost) < ft_get_absolute(cheapest))
		{
			cheapest = (ft_get_absolute(current->a_cost) + \
					ft_get_absolute(current->b_cost));
			a_cost = current->a_cost;
			b_cost = current->b_cost;
		}
		current = current->next;
	}
	ft_choose_move(stack_a, stack_b, a_cost, b_cost);
}

// Function to get the maximum value in the stack
void	ft_index_it(t_stack	*stack, int stack_size)
{
	int			max_value;
	t_node		*current;
	t_node		*max_node;
	int			size;

	size = stack_size;
	while (size > 0)
	{
		max_value = INT_MIN;
		current = stack->head;
		max_node = NULL;
		while (current)
		{
			if ((current->value > max_value) && current->index == 0)
			{
				max_value = current->value;
				max_node = current;
			}
				current = current->next;
		}
		if (max_node != NULL)
			max_node->index = size;
		size--;
	}
}
