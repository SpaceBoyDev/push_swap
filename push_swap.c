/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:54:11 by dario             #+#    #+#             */
/*   Updated: 2025/04/10 12:58:55 by dario            ###   ########.fr       */
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
	print_stack(&a, false);
	move_dual(&a, &b, &moves, pb);
	move_dual(&a, &b, &moves, pb);
	print_stack(&b, false);

	iterate_stack(a, b, set_target_node);
	//set_target_node(a, b);
	print_stack(&a, false);

	// while (stack_size(a) > 3)
	// {
	// 	if (stack_size(b) < 2)
	// 		move_dual(&a, &b, &moves, pb);
	// 	else
	// 		push_sort_b(&a, &b, &moves);
	// }
	free_stack(&a);
	free_stack(&b);
	return (0);
}

