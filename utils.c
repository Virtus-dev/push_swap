/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:35:39 by arigonza          #+#    #+#             */
/*   Updated: 2023/09/18 18:37:24 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Takes a doble char pointer(char**)
 *  and returns the size of it as an int.
 * 
 * @param matrix 
 * @return int 
 */
int	ft_matrix_size(char **matrix)
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
void	ft_free_matrix(char	**matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

/**
 * @brief Push all the elements on the stack A to stack B
 *  except 3 while pre-sort them.
 * 
 * @param stack_a t_stack (linkedList)
 * @param stack_b t_stack (linkedList)
 */
void	ft_push_until_3(t_stack *stack_a, t_stack *stack_b)
{
	int		stack_size;
	int		i;
	int		pushed;

	stack_size = stack_a->size;
	i = 0;
	pushed = 0;
	while (i < stack_size && pushed < (stack_size / 2) && stack_size > 5)
	{
		if (stack_a->head->index <= (stack_size / 2))
		{
			ft_pb(stack_b, stack_a);
			pushed++;
		}
		else
			ft_ra(stack_a);
		i++;
	}
	while ((stack_size - pushed) > 3)
	{
		ft_pb(stack_b, stack_a);
		pushed++;
	}
}

/**
 * @brief Takes a number and changes it to positive.
 * 
 * @param nbr 
 * @return int
 */
int	ft_get_absolute(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

void	ft_print_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current)
	{
		ft_printf("stack: %d\n", current->value);
		current = current->next;
	}
}
