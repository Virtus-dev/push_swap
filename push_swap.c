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

#include "push_swap.h"

void	ft_sa(t_stack* stackA)
{
	if (!stackA || !stackA->head)
		return;
	Node* first = pop(stackA);
	Node* second = pop(stackA);
	insert_node_head(stackA, first);
	insert_node_head(stackA, second);
	ft_putstr("sa\n");
}

void	ft_pa(t_stack* stackA, t_stack* stackB)
{
	insert_node_head(stackA, pop(stackB));
	ft_putstr("pa\n");
}

void	ft_sb(t_stack* stackB)
{
	if (!stackB || !stackB->head)
		return;
	Node* first = pop(stackB);
	Node* second = pop(stackB);
	insert_node_head(stackB, first);
	insert_node_head(stackB, second);
	ft_putstr("sb\n");
}

void	ft_pb(t_stack* stackB, t_stack* stackA)
{
	insert_node_head(stackB, pop(stackA));
	ft_putstr("pb\n");
}

void	ft_ss(t_stack* stackA, t_stack* stackB)
{
	ft_sa(stackA);
	ft_sb(stackB);
}

void	ft_ra(t_stack* stackA)
{
	insert_node_tail(stackA, pop(stackA));
	ft_putstr("ra\n");
}

void	ft_rb(t_stack* stackB)
{
	insert_node_tail(stackB, pop(stackB));
	ft_putstr("rb\n");
}

void	ft_rr(t_stack* stackA, t_stack* stackB)
{
	insert_node_tail(stackA, pop(stackA));
	insert_node_tail(stackB, pop(stackB));
	ft_putstr("rr\n");
}

void	ft_rra(t_stack* stackA)
{
	if (!stackA || !stackA->head || !stackA->head->next)
		return;
	Node* prev = NULL;
	Node* current = stackA->head;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = stackA->head;
	stackA->head = current;
	ft_putstr("rra\n");
}

void	ft_rrb(t_stack* stackB)
{
	if (!stackB || !stackB->head || !stackB->head->next)
		return;
	Node* prev = NULL;
	Node* current = stackB->head;
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

void	ft_rrr(t_stack* stackA, t_stack* stackB)
{
	ft_rra(stackA);
	ft_rrb(stackB);
	//ft_putstr("rrr\n");
}
