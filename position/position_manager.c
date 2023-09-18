/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:17:07 by arigonza          #+#    #+#             */
/*   Updated: 2023/09/18 19:03:11 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate_both(t_stack *stack_a, t_stack *stack_b,
	int *a_cost, int *b_cost)
{
	while (*a_cost > 0 && *b_cost > 0)
	{
		ft_rr(stack_a, stack_b);
		(*a_cost)--;
		(*b_cost)--;
	}
}

void	ft_reverse_rotate_both(t_stack *stack_a, t_stack *stack_b,
	int *a_cost, int *b_cost)
{
	while (*a_cost < 0 && *b_cost < 0)
	{
		ft_rrr(stack_a, stack_b);
		(*a_cost)++;
		(*b_cost)++;
	}
}

void	ft_rotate_a(t_stack *stack_a, int *a_cost)
{
	while (*a_cost)
	{
		if (*a_cost > 0)
		{
			ft_ra(stack_a);
			(*a_cost)--;
		}
		else if (*a_cost < 0)
		{
			ft_rra(stack_a);
			(*a_cost)++;
		}
	}
}

void	ft_rotate_b(t_stack *stack_b, int *b_cost)
{
	while (*b_cost)
	{
		if (*b_cost > 0)
		{
			ft_rb(stack_b);
			(*b_cost)--;
		}
		else if (*b_cost < 0)
		{
			ft_rrb(stack_b);
			(*b_cost)++;
		}
	}
}
