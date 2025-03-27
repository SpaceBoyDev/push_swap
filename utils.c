/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:00:23 by dario             #+#    #+#             */
/*   Updated: 2025/03/27 20:51:50 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*error_exit(const char *error_message)
{
	ft_printf(RED"\n-----\nERROR\n-----\n");
	if (error_message)
		ft_printf(YELLOW"%s\n"RST, error_message);
	exit(1);
}

void	check_digit_arg(char *argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]) && argv[i] != ' '
			&& argv[i] != '-' && argv[i] != '+')
			error_exit("Argument must contain only digits");
		++i;
	}
}

int	*fill_stack(char **numbers)
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
		++i;
	}
	return (stack_array);
}

int	*multiple_args(char **argv)
{
	size_t	i;
	
	i = 1;
	while (argv[i])
	{
		check_digit_arg(argv[i]);
		++i;
	}
	i = 1;
	return (fill_stack(argv));
}

int	*single_arg(char *argv)
{
	char	**stack;

	check_digit_arg(argv);
	stack = ft_split(argv, ' ');
	return (fill_stack(stack));
}
