/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:54:11 by dario             #+#    #+#             */
/*   Updated: 2025/03/27 21:05:24 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	read_stack_int(int stack[])
{
	int i = 0;

	while (stack[i] != '\0')
	{
		printf("Number %d: %d\n", i + 1, stack[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	int	*stack;
	
	if (argc == 1)
		error_exit("No arguments provided");
	else if (argc == 2)
		stack = single_arg(argv[1]);
	else if (argc > 2)
		stack = multiple_args(argv);
	read_stack_int(stack);
	free(stack);
	return (0);
}