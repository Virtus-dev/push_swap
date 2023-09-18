/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:39:40 by arigonza          #+#    #+#             */
/*   Updated: 2023/04/19 22:39:49 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sb(t_stack *stackB)
{
	t_node	*first;
	t_node	*second;

	if (!stackB || !stackB->head)
		return ;
	first = pop(stackB);
	second = pop(stackB);
	insert_node_head(stackB, first);
	insert_node_head(stackB, second);
	ft_putstr("sb\n");
}

void	ft_pb(t_stack *stackB, t_stack *stack_a)
{
	insert_node_head(stackB, pop(stack_a));
	ft_putstr("pb\n");
}

void	ft_rb(t_stack *stackB)
{
	insert_node_tail(stackB, pop(stackB));
	ft_putstr("rb\n");
}

void	ft_rrb(t_stack *stackB)
{
	t_node	*prev;
	t_node	*current;

	if (!stackB || !stackB->head || !stackB->head->next)
		return ;
	prev = NULL;
	current = stackB->head;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = stackB->head;
	stackB->head = current;
	ft_putstr("rrb\n");
}
