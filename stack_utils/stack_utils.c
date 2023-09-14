/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:08:03 by arigonza          #+#    #+#             */
/*   Updated: 2023/09/14 17:25:58 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief frees the stack.
 * 
 * @param stack 
 */
void    ft_free_stack(t_stack* stack)
{
    Node* current;
    Node* next_node;

    if (!stack->head)
        return;
    current = stack->head;
    next_node = current->next;
    while (current->next)
    {
        destroy_node(current);
        current = next_node;
        next_node = current->next;
    }
}

/**
 * @brief Fill a stack with the number of elements passed by parameter
 * 
 * @param stack t_stack.
 * @param size number of elements used to fill the t_stack.
 * @param parsed Elements passed to fill the t_stack. (int*)
 */
void    ft_fill_stack(t_stack* stack, int size, int* parsed)
{
    int	i;

	i = 0;
    while (i < size)
    {
        insert_node_head(stack, create_node(parsed[i]));
        i++;
    }
}

/**
 * @brief Initialize a t_stack as NULL.
 * 
 * @param stack 
 */
void ft_initialize_stack(t_stack* stack)
{
    stack->head = NULL;
    stack->size = 0;
}

/**
 * @brief Get the max index in the stack.
 * 
 * @param stack 
 * @return the max index found.
 */
int get_max_index(t_stack* stack)
{
    int max_index;
    Node* current;
    
    current = stack->head;
    max_index = current->index;
    while (current != NULL)
    {
        if (current->index > max_index)
            max_index = current->index;
        current = current->next;
    }

    return max_index;
}

int ft_get_lowest_index(t_stack* stack)
{
    Node*	current;
    int		lowest;
    int     pos;
	
    ft_set_position(stack);
    lowest = INT_MAX;
    current = stack->head;
    pos = current->pos;
	while (current)
	{
		if (current->index < lowest)
        {
            lowest = current->index;
            pos = current->pos;
        }
		current = current ->next;
	}
	return (pos);
} 