/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:54:11 by dario             #+#    #+#             */
/*   Updated: 2025/03/28 22:29:15 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *node)
{
	ft_printf("INDEX    |    VALUE\n");
	ft_printf("---------|---------\n");
	while (node)
	{
		ft_printf("  %d\t |\t%d\n", node->index, node->value);
		node = node->next;
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		error_exit("No arguments provided");
	else if (argc == 2)
		init_stack_a(&a, ft_split(argv[1], ' '));
	else
		init_stack_a(&a, argv + 1);
	print_stack(a);
	return (0);
}