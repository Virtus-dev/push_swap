

#include "push_swap.h"

int	ft_matrix_size(char** matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

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
