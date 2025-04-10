/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:27:22 by dario             #+#    #+#             */
/*   Updated: 2025/04/10 14:27:03 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	iterate_stack_dual(t_node *a, t_node *b,
			void (*func)(t_node *, t_node *))
{
	if (!a || !b || !func)
		return ;
	while (a)
	{
		func(a, b);
		a = a->next;
	}
}

void	iterate_stack(t_node *a, void (*func)(t_node *))
{
	if (!a || !func)
		return ;
	while (a)
	{
		func(a);
		a = a->next;
	}
}

void	push_sort_b(t_node **a, t_node **b, int *moves)
{
	iterate_stack_dual(*a, *b, set_target_node);
	print_stack(a, false);
	iterate_stack(*a, set_cost_node);
	print_stack(b, false);
	print_stack(a, false);
}
