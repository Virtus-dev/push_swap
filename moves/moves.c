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

void	ft_ss(t_stack *stack_a, t_stack *stackB)
{
	ft_sa(stack_a);
	ft_sb(stackB);
}

void	ft_ra(t_stack *stack_a)
{
	insert_node_tail(stack_a, pop(stack_a));
	ft_putstr("ra\n");
}

void	ft_rb(t_stack *stackB)
{
	insert_node_tail(stackB, pop(stackB));
	ft_putstr("rb\n");
}

void	ft_rr(t_stack *stack_a, t_stack *stackB)
{
	insert_node_tail(stack_a, pop(stack_a));
	insert_node_tail(stackB, pop(stackB));
	ft_putstr("rr\n");
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

void	ft_rrr(t_stack *stack_a, t_stack *stackB)
{
	ft_rra(stack_a);
	ft_rrb(stackB);
	//ft_putstr("rrr\n");
}
