/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:14:43 by arigonza          #+#    #+#             */
/*   Updated: 2023/09/19 10:39:10 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_set_position(t_stack *stack)
{
	int		i;
	t_node	*current;

	i = 0;
	current = stack->head;
	while (current)
	{
		current->pos = i;
		i++;
		current = current->next;
	}
}

int	ft_find_aux(t_stack *stack_a, int a_index)
{
	t_node	*current;
	int		target_pos;

	current = stack_a->head;
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

int	ft_find_tp(t_stack *stack_a, int b_index)
{
	t_node	*current;
	int		a_index;
	int		target_pos;

	current = stack_a->head;
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
	return (ft_find_aux(stack_a, a_index));
}

void	ft_set_target_position(t_stack *stack_a, t_stack *stackB)
{
	t_node	*current;

	ft_set_position(stack_a);
	ft_set_position(stackB);
	current = stackB->head;
	while (current)
	{
		current->target_pos = ft_find_tp(stack_a, current->index);
		current = current->next;
	}
}
