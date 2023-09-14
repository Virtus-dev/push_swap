/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:45:16 by arigonza          #+#    #+#             */
/*   Updated: 2023/09/14 17:54:15 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_swap(int* parsed, int size)
{
    t_stack stackA;
    t_stack stackB;

    ft_initialize_stack(&stackA);
    ft_initialize_stack(&stackB);
    
    while (0 < size)
    {
        insert_node_head(&stackA, create_node(parsed[size-1]));
        size--;
    }
    ft_index_it(&stackA, stackA.size);
    if (!ft_is_sorted(&stackA))
    {
        if (stackA.size == 2)
            ft_sa(&stackA);
        if (stackA.size == 3)
            ft_sort_3(&stackA);
        else
            ft_sort_all(&stackA, &stackB);
    }
    ft_free_stack(&stackA);
    ft_free_stack(&stackB);
}

int main(int argc, char** argv)
{
    int size;
    int* parsed;
   
    parsed = NULL;
    if (argc > 1)
    {
        if (!ft_param_checker(argc, argv))
        {
            ft_printf("Error\n");
        }
        else
        {
            if (argc == 2)
            {
                char** splited = ft_split(argv[1], ' ');
                size = ft_matrix_size(splited);
                parsed = ft_parse(splited, 0);
                push_swap(parsed, size);
                ft_free_matrix(splited);
            }
            else
            {
                size = (ft_matrix_size(argv) - 1);
                parsed = ft_parse(argv, 1);
                push_swap(parsed, size);
            }
        }
        free(parsed);
    }
    return 0;
}
