/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:40:07 by arigonza          #+#    #+#             */
/*   Updated: 2023/09/14 17:50:46 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cost(t_stack* stackA, t_stack* stackB)
{
	Node*	current_A;
	Node*	current_B;

	current_A = stackA->head;
	current_B = stackB->head;
	while (current_B)
	{
		current_B->b_cost = current_B->pos;
		if (current_B->pos > (stackB->size / 2))
			current_B->b_cost = (stackB->size - current_B->pos) * -1;
		current_B->a_cost = current_B->target_pos;
		if (current_B->target_pos > (stackA->size / 2))
			current_B->a_cost = (stackA->size - current_B->target_pos) * -1;
		current_B = current_B->next;
	}
}

void	ft_choose_cheapest_and_move(t_stack* stackA, t_stack* stackB)
{
	Node*	current;
	int		cheapest;
	int		a_cost;
	int		b_cost;

	current = stackB->head;
	cheapest = INT_MAX;
	while (current)
	{
		if (ft_get_absolute(current->a_cost) + ft_get_absolute(current->b_cost) < ft_get_absolute(cheapest))
		{
			cheapest = (ft_get_absolute(current->a_cost) +  ft_get_absolute(current->b_cost));
			a_cost = current->a_cost;
			b_cost = current->b_cost;
		}
		current = current->next;
	}
	ft_choose_move(stackA, stackB, a_cost, b_cost);
}

// Function to get the maximum value in the stack
void ft_index_it(t_stack* stack, int stack_size)
{
    int     max_value;
    Node*   current;
    Node*   max_node;
    int     size;

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