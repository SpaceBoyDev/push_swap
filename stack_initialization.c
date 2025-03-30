/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 20:14:31 by dario             #+#    #+#             */
/*   Updated: 2025/03/30 17:40:14 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*fill_stack(char **numbers, int *len)
{
	int		*stack_array;
	size_t	count;
	size_t	i;

	count = 0;
	while (numbers[count])
		++count;
	stack_array = (int *)malloc(sizeof(int) * count);
	if (!stack_array)
		error_exit("Memory allocation failed");
	i = 0;
	while (i < count)
	{
		stack_array[i] = ft_atoi(numbers[i]);
		if (stack_array[i] > INT_MAX || stack_array[i] < INT_MIN)
		{
			free(stack_array);
			error_exit("Values can't be outside of int variable limits");
		}
		++i;
	}
	*len = i;
	return (stack_array);
}

void	init_stack_a(t_node **stack, char **argv)
{
	size_t	i;
	long	n;

	i = 0;
	while (argv[i])
	{
		if (!is_arg_valid(argv[i]))
			error_free(stack, "Arguments must contain only digits");
		n = ft_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			error_free(stack, "Numbers must be inside int variable limits");
		if (error_duplicate(*stack, (int)n))
			error_free(stack, "There is a duplicated number");
		append_node(stack, (int)n);
		++i;
	}
}

int	*multiple_args(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		is_arg_valid(argv[i]);
		++i;
	}
	return (fill_stack(argv, &i));
}

int	*single_arg(char *argv)
{
	char	**stack;
	int		*stack_numbers;
	int		stack_len;

	is_arg_valid(argv);
	stack = ft_split(argv, ' ');
	stack_numbers = fill_stack(stack, &stack_len);
	ft_printf("Hay %d números\n", stack_len);
	return (stack_numbers);
}
