/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:27:22 by dario             #+#    #+#             */
/*   Updated: 2025/04/15 02:54:46 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** Sorts stacks of three nodes
 * @param stack Stack that is going to be sorted
 * @param moves Total number of moves
 */
void	sort_three(t_node **stack, int *moves)
{
	t_node	*max_value;

	if (is_stack_sorted(*stack))
		return ;
	max_value = find_max_value(*stack);
	if (max_value->index == 0)
		move_single(stack, moves, ra);
	else if (max_value->index == 1)
		move_single(stack, moves, rra);
	if (!is_stack_sorted(*stack))
		move_single(stack, moves, sa);
}

/** Final part of the turk algorithm. Sets the target of each node of b and
 * calculates its push cost. The cheapest node to push and its target are
 * moved to the top of their respective stack. When both are on top, it pushes
 * the first node of stack b to stack a until b is empty.
 * @param a Stack a
 * @param b Stack b
 * @param moves Numbers of moves done
 */
void	push_sort_a(t_node **a, t_node **b, int *moves)
{
	t_node	*push_node;

	while (stack_size(*b) > 0)
	{
		iterate_stack_dual(*b, *a, set_target_node_b);
		iterate_stack(*b, set_cost_node);
		push_node = set_cheapest(*b);
		if (push_node->index != 0 || push_node->target->index != 0)
		{
			while (push_node->index != 0 && push_node->target->index != 0
				&& push_node->above_median == push_node->target->above_median)
			{
				if (push_node->above_median && push_node->target->above_median)
					move_dual(a, b, moves, rr);
				else if (!push_node->above_median && !push_node->target->above_median)
					move_dual(a, b, moves, rrr);
			}
			while (push_node->index != 0)
			{
				if (push_node->above_median)
					move_single(b, moves, rb);
				else
					move_single(b, moves, rrb);
			}
			while (push_node->target->index != 0)
			{
				if (push_node->target->above_median)
					move_single(a, moves, ra);
				else
					move_single(a, moves, rra);
			}
		}
		// while (push_node->index != 0)
		// {
		// 	if (push_node->above_median)
		// 		move_single(b, moves, rb);
		// 	else
		// 		move_single(b, moves, rrb);
		// }
		// while (push_node->target->index != 0)
		// {
		// 	if (push_node->target->above_median)
		// 		move_single(a, moves, ra);
		// 	else
		// 		move_single(a, moves, rra);
		// }
		(*b)->cheapest = false;
		move_dual(a, b, moves, pa);
	}
}

/** Initial part of the turk algorithm. Sets the target of each node of a and
 * calculates its push cost. The cheapest node to push and its target are
 * moved to the top of their respective stack. When both are on top, it pushes
 * the first node of stack a to stack b.
 * @param a Stack a
 * @param b Stack b
 * @param moves Numbers of moves done
 */
void	push_sort_b(t_node **a, t_node **b, int *moves)
{
	t_node	*push_node;

	while (stack_size(*a) > 3)
	{
		iterate_stack_dual(*a, *b, set_target_node_a);
		iterate_stack(*a, set_cost_node);
		push_node = set_cheapest(*a);
		if (push_node->index != 0 || push_node->target->index != 0)
		{
			while (push_node->index != 0 && push_node->target->index != 0
				&& push_node->above_median == push_node->target->above_median)
			{
				if (push_node->above_median && push_node->target->above_median)
					move_dual(a, b, moves, rr);
				else if (!push_node->above_median && !push_node->target->above_median)
					move_dual(a, b, moves, rrr);
			}
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
		}

		// while (push_node->index != 0)
		// {
		// 	if (push_node->above_median)
		// 		move_single(a, moves, ra);
		// 	else
		// 		move_single(a, moves, rra);
		// }
		// while (push_node->target->index != 0)
		// {
		// 	if (push_node->target->above_median)
		// 		move_single(b, moves, rb);
		// 	else
		// 		move_single(b, moves, rrb);
		// }
		(*a)->cheapest = false;
		move_dual(a, b, moves, pb);
	}
	sort_three(a, moves);
}

/** Turkish algorithm. Sorts stack a in the minimum number of moves possible
 * @param a Stack a
 * @param b Stack b
 * @param moves Number of moves done
*/
void	turk_algo(t_node **a, t_node **b, int *moves)
{
	t_node	*min_value;

	if (stack_size(*a) == 3)
		sort_three(a, moves);
	else if (stack_size(*a) == 2)
		move_single(a, moves, sa);
	while (stack_size(*b) != 2 && stack_size(*a) > 3)
		move_dual(a, b, moves, pb);
	push_sort_b(a, b, moves);
	push_sort_a(a, b, moves);
	min_value = find_min_value(*a);
	while (min_value->index != 0)
	{
		if (min_value->above_median)
			move_single(a, moves, ra);
		else
			move_single(a, moves, rra);
	}
}
