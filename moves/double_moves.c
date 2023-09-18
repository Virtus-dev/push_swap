/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:58:20 by arigonza          #+#    #+#             */
/*   Updated: 2023/09/18 18:59:38 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ss(t_stack *stack_a, t_stack *stackB)
{
	ft_sa(stack_a);
	ft_sb(stackB);
}

void	ft_rr(t_stack *stack_a, t_stack *stackB)
{
	insert_node_tail(stack_a, pop(stack_a));
	insert_node_tail(stackB, pop(stackB));
	ft_putstr("rr\n");
}

// ft_printf("rrr");
void	ft_rrr(t_stack *stack_a, t_stack *stackB)
{
	ft_rra(stack_a);
	ft_rrb(stackB);
}
