/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:35:42 by arigonza          #+#    #+#             */
/*   Updated: 2023/09/02 13:35:42 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}

/**
 * @brief Takes out the first node of a t_stack and returns it.
 * 
 * @param stack 
 * @return Node* 
 */
t_node	*pop(t_stack *stack)
{
	t_node	*tmp;

	if (!stack || stack->head == NULL)
		return (NULL);
	tmp = stack->head;
	stack->head = stack->head->next;
	tmp->next = NULL;
	stack->size--;
	return (tmp);
}

void	insert_node_head(t_stack *stack, t_node *node)
{
	t_node	*tmp;

	if (!stack || !node)
		return ;
	tmp = stack->head;
	stack->head = node;
	stack->head->next = tmp;
	stack->size++;
}

void	insert_node_tail(t_stack *stack, t_node *node)
{
	t_node	*current;

	if (!stack || !node)
		return ;
	current = stack->head;
	while (current->next)
	{
		current = current->next;
	}
	current->next = node;
	node->next = NULL;
	stack->size++;
}

void	destroy_node(t_node *node)
{
	free(node);
}
