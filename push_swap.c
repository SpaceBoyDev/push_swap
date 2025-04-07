/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:54:11 by dario             #+#    #+#             */
/*   Updated: 2025/04/07 20:27:32 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *node, bool simple_view)
{
	if (simple_view)
	{
		while (node)
		{
			ft_printf("\t%d\n", node->value);
			node = node->next;
		}
		return ;
	}
	ft_printf("+-----------------------------------------------------+\n");
	ft_printf("|    INDEX    |    VALUE    |    PREV    |    NEXT    |\n");
	ft_printf("|-------------+-------------+------------+------------|\n");
	while (node)
	{
		ft_printf("|      %d      |      %d      |", node->index, node->value);
		if (node->prev)
			ft_printf("      %d     |", node->prev->value);
		else
			ft_printf("    NULL    |");
		if (node->next)
			ft_printf("      %d     |\n", node->next->value);
		else
			ft_printf("    NULL    |\n");
		node = node->next;
	}
}

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

	update_index(a);
	print_stack(a, false);
	printf("Size del stack -> %d\n", stack_size(a));
	movement(a, &moves, &sa);
	update_index(a);
	print_stack(a, false);

	if (is_stack_sorted(a))
		error_free(&a, "Stack is already sorted");
	free_stack(&a);
	return (0);
}
