/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:45:16 by arigonza          #+#    #+#             */
/*   Updated: 2023/09/19 16:49:06 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_leaks(void)
{
	system("leaks -q push_swap");
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
