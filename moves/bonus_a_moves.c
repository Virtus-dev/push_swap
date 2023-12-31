/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_a_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:41:06 by arigonza          #+#    #+#             */
/*   Updated: 2023/09/19 16:36:55 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa_bonus(t_stack *stack_a)
{
	t_node	*first;
	t_node	*second;

	if (!stack_a || !stack_a->head)
		return ;
	first = pop(stack_a);
	second = pop(stack_a);
	insert_node_head(stack_a, first);
	insert_node_head(stack_a, second);
}

void	ft_pa_bonus(t_stack *stack_a, t_stack *stack_b)
{
	insert_node_head(stack_a, pop(stack_b));
}

void	ft_ra_bonus(t_stack *stack_a)
{
	insert_node_tail(stack_a, pop(stack_a));
}

void	ft_rra_bonus(t_stack *stack_a)
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
}
