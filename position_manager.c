/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:17:07 by arigonza          #+#    #+#             */
/*   Updated: 2023/09/11 15:17:38 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_psotition(t_stack* stack)
{
    int i;
    Node* current;

    i = 0;
    current = stack->head;
    while (current)
    {
        current->pos = i;
        i++;
        current = current->next;
    }
}

int	ft_find_tp(t_stack* stackA, int b_index)
{
	Node*	current;
	int		a_index;
	int		target_pos;
	
	current = stackA->head;
	a_index = INT_MAX;
	while (current)
	{
		if (current->index > b_index && current->index < a_index)
		{
			a_index = current->index;
			target_pos = current->pos;
		}
		current = current->next;
	}
	if (a_index != INT_MAX)
		return (target_pos);
	current = stackA->head;
	while (current)
	{
		if (current->index < a_index)
		{
			a_index = current->index;
			target_pos = current->pos;
		}
		current = current->next;
	}
	return (target_pos);
}

void	ft_set_target_position(t_stack* stackA, t_stack* stackB)
{
    Node*	current;
	
	ft_set_psotition(stackA);
    ft_set_psotition(stackB);
	current = stackB->head;
    while (current)
	{
		current->target_pos = ft_find_tp(stackA, current->index);
		current = current->next;
	}
}