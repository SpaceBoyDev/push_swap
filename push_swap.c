/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:54:11 by dario             #+#    #+#             */
/*   Updated: 2025/04/14 19:58:14 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		moves;

	a = NULL;
	b = NULL;
	moves = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		error_exit("No arguments provided");
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		init_stack_a(&a, argv, true);
		free_split(argv);
	}
	else
		init_stack_a(&a, argv + 1, false);
	if (is_stack_sorted(a))
		error_free(&a, "Stack is already sorted");
	turk_algo(&a, &b, &moves);

	free_stack(&a);
	free_stack(&b);
	return (0);
}

