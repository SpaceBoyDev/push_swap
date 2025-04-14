/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:27:22 by dario             #+#    #+#             */
/*   Updated: 2025/04/14 19:59:13 by dario            ###   ########.fr       */
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

void	sort_three(t_node **a, int *moves)
{
	t_node	*max_value;
	
	if (is_stack_sorted(*a))
		return ;
	max_value = find_max_value(*a);
	if (max_value->index == 0)
		move_single(a, moves, ra);
	else if (max_value->index == 1)
		move_single(a, moves, rra);
	if (!is_stack_sorted(*a))
		move_single(a, moves, sa);
}

void	push_sort_b(t_node **a, t_node **b, int *moves)
{
	t_node	*push_node;
	while (stack_size(*a) > 3)
	{
		iterate_stack_dual(*a, *b, set_target_node);
		iterate_stack(*a, set_cost_node);
		push_node = set_cheapest(*a);
		while (push_node->index != 0)
		{
			if (push_node->above_median)
				move_single(a, moves, ra);
			else
				move_single(a, moves, rra);
		}
		while (push_node->target->index != 0)
		{
			if (push_node->target->above_median)
				move_single(b, moves, rb);
			else
				move_single(b, moves, rrb);
		}
		move_dual(a, b, moves, pb);
	}
	print_stack(a, false);
	print_stack(b, false);
	sort_three(a, moves);
	print_stack(a, false);
	print_stack(b, false);
}

void	turk_algo(t_node **a, t_node **b, int *moves)
{
	while (stack_size(*b) != 2 && stack_size(*a) > 3)
		move_dual(a, b, moves, pb);
	push_sort_b(a, b, moves);
	ft_printf("Moves -> %i\n", *moves);
}
