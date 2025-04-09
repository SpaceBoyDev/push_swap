/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:54:11 by dario             #+#    #+#             */
/*   Updated: 2025/04/09 20:24:39 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node **stack, bool simple_view)
{
	t_node	*current;

	current = *stack;
	if (simple_view)
	{
		while (current)
		{
			ft_printf("%d\n", current->value);
			current = current->next;
		}
		return ;
	}
	ft_printf("+------------------------------------------------------------------------------+\n");
	ft_printf("|    INDEX    |    VALUE    |    PREV    |    NEXT    |   MEDIAN   |   CHEAP   |\n");
	ft_printf("|-------------+-------------+------------+------------+------------+-----------|\n");
	while (current)
	{
		ft_printf("|      %d      |      %d      |", current->index, current->value);
		if (current->prev)
			ft_printf("      %d     |", current->prev->value);
		else
			ft_printf("    NULL    |");
		if (current->next)
			ft_printf("      %d     |", current->next->value);
		else
			ft_printf("    NULL    |");
		if (current->above_median)
			ft_printf("      ^     |");
		else
			ft_printf("      v     |");
		if (current->cheapest)
			ft_printf("    TRUE   |\n");
		else
			ft_printf("    FALSE  |\n");
		current = current->next;
	}
	ft_printf("+------------------------------------------------------------------------------+\n\n");
}

void	check_move(t_node **a, t_node **b)
{
	print_stack(a, false);
	print_stack(b, false);
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
	//move_single(&a, &moves, rra);
	print_stack(&a, false);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
