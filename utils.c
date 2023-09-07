/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:35:39 by arigonza          #+#    #+#             */
/*   Updated: 2023/09/05 13:30:50 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/**
 * @brief Takes a doble char pointer(char**) and returns the size of it as an int.
 * 
 * @param matrix 
 * @return int 
 */
int	ft_matrix_size(char** matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

/**
 * @brief Free a doble char pointer(char**).
 * 
 * @param matrix (char**)
 */
void	ft_free_matrix(char** matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

/**
 * @brief Push all the elements on the stack A to stack B except 3 while pre-sort them.
 * 
 * @param stackA t_stack (linkedList)
 * @param stackB t_stack (linkedList)
 */
void	ft_push_until_3(t_stack* stackA, t_stack* stackB)
{
	int		stack_size;
	Node*	current;
	int		i;
	int		pushed;

	stack_size = stackA->size;
	current = stackA->head;
	i = 0;
	pushed = 0;
	while (i < stack_size && pushed < (stack_size / 2) && stack_size > 5)
	{
		if (current->index <= stack_size / 2)
		{
			ft_pb(stackB, stackA);
			pushed++;
		}
		else
		{
			ft_ra(stackA);
		}
		i++;
	}
	while ((stack_size - pushed) > 3)
	{
		ft_pb(stackB, stackA);
		pushed++;
	}
}

void	ft_sort_3(t_stack* stack)
{
	int	max_index;
	Node*	current;

	current = stack->head;
	max_index = get_max_index(stack);
	if (current->index == max_index)
		ft_ra(stack);
		if (!ft_is_sorted(stack))
			ft_sa(stack);
	else if (current->next->index == max_index)
		ft_rra(stack);
		if (!ft_is_sorted(stack))
			ft_sa(stack);
	else if ((current->next->next->index == max_index) && !ft_is_sorted(stack))
		ft_sa(stack);
}
