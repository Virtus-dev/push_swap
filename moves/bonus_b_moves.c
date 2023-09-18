/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_b_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:36:25 by arigonza          #+#    #+#             */
/*   Updated: 2023/09/18 17:22:31 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sb(t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;
	
	if (!stack_b || !stack_b->head)
		return ;
	first = pop(stack_b);
	second = pop(stack_b);
	insert_node_head(stack_b, first);
	insert_node_head(stack_b, second);
}

void	ft_pb(t_stack *stack_b, t_stack *stack_a)
{
	insert_node_head(stack_b, pop(stack_a));
}

void	ft_rb(t_stack *stack_b)
{
	insert_node_tail(stack_b, pop(stack_b));
}

void	ft_rrb(t_stack *stack_b)
{
	t_node	*prev;
	t_node	*current;

	if (!stack_b || !stack_b->head || !stack_b->head->next)
		return ;
	prev = NULL;
	current = stack_b->head;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = stack_b->head;
	stack_b->head = current;
}
