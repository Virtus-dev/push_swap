/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:51:58 by arigonza          #+#    #+#             */
/*   Updated: 2023/09/19 16:11:56 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_param_checker_plus(char **argv, int argc)
{
	int	*parsed;
	int	i;

	i = 1;
	parsed = ft_parse(argv, 1);
	if (!parsed)
		return (free(parsed), 0);
	while (i < argc)
	{
		if (!ft_is_nbr(argv[i]))
			return (free(parsed), 0);
		i++;
	}
	if (ft_isdup(argv))
		return (free(parsed), 0);
	return (free(parsed), 1);
}

/**
 * @brief Checks if all of them are numbers and if some of them are duplicate.
 * 
 * @param argc (number of arguments)
 * @param argv (char**)
 * @return int 
 */
int	ft_param_checker(int argc, char **argv)
{
	int		i;
	char	**splited;
	int		*parsed;

	if (argc == 2)
	{
		i = 0;
		splited = ft_split(argv[1], ' ');
		parsed = ft_parse(splited, 0);
		if (!parsed || !splited)
			return (ft_free_matrix(splited), free(parsed), 0);
		while (splited[i])
		{
			if (!ft_is_nbr(splited[i]))
				return (ft_free_matrix(splited), free(parsed), 0);
			i++;
		}
		if (ft_isdup(splited))
			return (ft_free_matrix(splited), free(parsed), 0);
		return (ft_free_matrix(splited), free(parsed), 1);
	}
	return (ft_param_checker_plus(argv, argc));
}

// argc should be 1 if there's more than 2 argc, or 0 in case there's only 2
int	*ft_parse(char **splited, int argc)
{
	int		i;
	int		j;
	int		size;
	int		*values;

	i = argc;
	j = 0;
	size = ft_matrix_size(splited);
	values = (int *)malloc(size * sizeof(int));
	if (!values)
		return (free(values), NULL);
	while (i < size)
	{
		if (ft_atol(splited[i]) > INT_MAX || ft_atol(splited[i]) < INT_MIN)
		{
			return (free(values), NULL);
		}
		else
			values[j] = (int)ft_atol(splited[i]);
		i++;
		j++;
	}
	return (values);
}
