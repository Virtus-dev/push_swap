/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:40:07 by arigonza          #+#    #+#             */
/*   Updated: 2023/09/11 17:52:49 by arigonza         ###   ########.fr       */
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
		if (current_B->pos > (stackB->size/2))
			current_B->b_cost = (current_B->size - current_B->pos) * -1;
		current_B->a_cost = current_B->target_pos;
		if (current_B->target_pos > (stackA->size))
			current_B->a_cost = (current_A->size - current_B->target_pos)* -1;
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
	// TODO ft_move_chose
	
}