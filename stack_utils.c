/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:08:03 by arigonza          #+#    #+#             */
/*   Updated: 2023/07/03 17:39:13 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void    ft_print_stack(t_stack* stack, char c)
{
    Node* current;

    current = stack->head;
    while (current)
    {
        if (c == 'a' || c =='A')
            ft_printf("stack A: %d\n", current->value);
        else if (c == 'b' || c == 'B')
            ft_printf("stack B: %d\n", current->value);
        current = current->next;
    }
}

// Initialize an empty stack
void ft_initialize_stack(t_stack* stack)
{
    stack->head = NULL;
    stack->size = 0;
}

// Function to get the maximum value in the stack
int get_max_value(t_stack* stack)
{
    int max_value = INT_MIN;
    Node* current = stack->head;

    while (current != NULL)
    {
        if (current->value > max_value)
        {
            max_value = current->value;
        }
        current = current->next;
    }

    return max_value;
}