/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:55:46 by arigonza          #+#    #+#             */
/*   Updated: 2023/09/18 18:59:25 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_stack *stack_a)
{
	t_node	*first;
	t_node	*second;

	if (!stack_a || !stack_a->head)
		return ;
	first = pop(stack_a);
	second = pop(stack_a);
	insert_node_head(stack_a, first);
	insert_node_head(stack_a, second);
	ft_putstr("sa\n");
}

void	ft_pa(t_stack *stack_a, t_stack *stackB)
{
	insert_node_head(stack_a, pop(stackB));
	ft_putstr("pa\n");
}

void	ft_ra(t_stack *stack_a)
{
	insert_node_tail(stack_a, pop(stack_a));
	ft_putstr("ra\n");
}

void	ft_rra(t_stack *stack_a)
{
	t_node	*prev;
	t_node	*current;

	if (!stack_a || !stack_a->head || !stack_a->head->next)
		return ;
	prev = NULL;
	current = stack_a->head;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = stack_a->head;
	stack_a->head = current;
	ft_putstr("rra\n");
}
