/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doble_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:46:26 by arigonza          #+#    #+#             */
/*   Updated: 2023/09/18 16:48:18 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}

void	ft_rr(t_stack *stack_a, t_stack *stack_b)
{
	insert_node_tail(stack_a, pop(stack_a));
	insert_node_tail(stack_b, pop(stack_b));
}

void	ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
}