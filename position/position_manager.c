/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:17:07 by arigonza          #+#    #+#             */
/*   Updated: 2023/09/13 11:41:38 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_both(t_stack* stackA, t_stack* stackB, int* a_cost, int* b_cost)
{
	while (*a_cost > 0 && *b_cost > 0)
	{
		ft_rr(stackA, stackB);
		(*a_cost)--;
		(*b_cost)--;
	}
}

void	ft_reverse_rotate_both(t_stack* stackA, t_stack* stackB, int* a_cost, int* b_cost)
{
	while (*a_cost < 0 && *b_cost < 0)
	{
		ft_rrr(stackA, stackB);
		(*a_cost)++;
		(*b_cost)++;
	}	
void	ft_rotate_a(t_stack* stackA, int* a_cost)
{
	while (*a_cost)
	{
		if (*a_cost > 0)
		{
			ft_ra(stackA);
			(*a_cost)--;
		}
		else if (*a_cost < 0)
		{
			ft_rra(stackA);
			(*a_cost)++;
		}
	}
}

void	ft_rotate_b(t_stack* stackB, int* b_cost)
{
	while (*b_cost)
	{
		if (*b_cost > 0)
		{
			ft_rb(stackB);
			(*b_cost)--;
		}
		else if (*b_cost < 0)
		{
			ft_rrb(stackB);
			(*b_cost)++;
		}
	}
}