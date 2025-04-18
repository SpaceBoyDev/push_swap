/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 20:14:31 by dario             #+#    #+#             */
/*   Updated: 2025/04/15 03:16:48 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_error(t_node **stack, char **argv, char *msg, bool split)
{
	if (split)
		free_split(argv);
	error_free(stack, msg);
}

static int	*fill_stack(char **numbers, int *len)
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

void	init_stack_a(t_node **stack, char **argv, bool split)
{
	size_t	i;
	long	n;

	i = 0;
	while (argv[i])
	{
		if (!is_arg_valid(argv[i]))
			init_error(stack, argv, "Arguments must contain only digits",
				split);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			init_error(stack, argv, "Numbers must be in int variable limits",
				split);
		if (error_duplicate(*stack, (int)n))
			init_error(stack, argv, "There is a duplicated number",
				split);
		append_node(stack, (int)n);
		++i;
	}
	update_stack(*stack);
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
