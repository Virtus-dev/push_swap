/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:45:16 by arigonza          #+#    #+#             */
/*   Updated: 2023/08/26 13:33:24 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_leaks(void)
{
    system("leaks -q push_swap");
}

void    push_swap(int* parsed, int size)
{
    t_stack stackA;
    t_stack stackB;
    
    ft_initialize_stack(&stackA);
    ft_initialize_stack(&stackB);
    
    while (size > 0)
    {
        insert_node_head(&stackA, create_node(parsed[size - 1]));
        size--;
    }
    if (ft_is_sorted(&stackA))
    {
        ft_free_stack(&stackA);
        ft_free_stack(&stackB);
        return;
    }
    ft_sort_stack(&stackA, &stackB);
}

int main(int argc, char** argv)
{
    int size;
    int* parsed;
    //char* sequence = get_next_line(0);
   
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
