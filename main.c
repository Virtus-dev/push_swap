/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:45:16 by arigonza          #+#    #+#             */
/*   Updated: 2023/09/18 18:27:37 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_leaks(void)
{
	system("leaks -q checker");
}

void	push_swap(int *parsed, int size)
{
	t_stack	stack_a;
	t_stack	stack_b;

	ft_initialize_stack(&stack_a);
	ft_initialize_stack(&stack_b);
	while (0 < size)
	{
		insert_node_head(&stack_a, create_node(parsed[size - 1]));
		size--;
	}
	ft_index_it(&stack_a, stack_a.size);
	if (!ft_is_sorted(&stack_a))
	{
		if (stack_a.size == 2)
			ft_sa(&stack_a);
		if (stack_a.size == 3)
			ft_sort_3(&stack_a);
		else
			ft_sort_all(&stack_a, &stack_b);
	}
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
}

int	main(int argc, char **argv)
{
	int		size;
	char	**splited;

	if (argc > 1)
	{
		if (!ft_param_checker(argc, argv))
			ft_printf("Error\n");
		else
		{
			if (argc == 2)
			{
				splited = ft_split(argv[1], ' ');
				size = ft_matrix_size(splited);
				push_swap(ft_parse(splited, 0), size);
				ft_free_matrix(splited);
			}
			else
			{
				size = (ft_matrix_size(argv) - 1);
				push_swap(ft_parse(argv, 1), size);
			}
		}
	}
	return (0);
}
