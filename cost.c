/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:40:07 by arigonza          #+#    #+#             */
/*   Updated: 2023/08/30 13:49:51 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int index_finder(t_stack* stack, int size)
{
    int i;
    int min_value;
    int min_position;
    t_stack* current;

    i = 0;
    current = stack->head;
    while (current)
    {
        if (current->value < min_value)
        {
            min_value = current->value;
            current->index = i;
            min_position = i;
            current = current->next;
            i++;
        }
        if ((current->value > min_value) )
        {
            current->index = i;
            current = current->next;
            i++;
        }
    }
    return (-1);
}