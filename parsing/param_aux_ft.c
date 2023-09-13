/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_aux_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:26:06 by arigonza          #+#    #+#             */
/*   Updated: 2023/07/03 17:32:41 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_is_sorted(t_stack *stack)
{
    int i;
	Node*	current;

	current = stack->head;
    i = 0;
    while (i < stack->size)
    {
        if (current->next && (current->value > current->next->value))
            return (0);
		current = current->next;
        i++;
    }
    return (1);
}

// Checks if is, or is not a number
int	ft_is_nbr(char* s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] == '+' || s[i] == '-'))
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_str_nbr_cmp(const char* s1, const char* s2)
{
	while (*s1 == '+' || *s1 == '0')
		s1++;
	while (*s2 == '+' || *s2 == '0')
		s2++;
	return (ft_strcmp(s1, s2));
}

// Checks if there's duplicates on a int*
int		ft_isdup(char** argv)
{
	int	i;
	int	j;

    i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_str_nbr_cmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

