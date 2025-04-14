/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:27:22 by dario             #+#    #+#             */
/*   Updated: 2025/04/14 21:27:11 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** Iterates through the nodes of the stack and executes a function
 * that needs both stacks on each node
 * @param stack Iterates through the nodes of this stack
 * @param aux_stack Aux stack needed to perform the function
 * @param func Function that is going to be executed on each node of stack
*/
void	iterate_stack_dual(t_node *stack, t_node *aux_stack,
			void (*func)(t_node *, t_node *))
{
	if (!stack || !aux_stack || !func)
		return ;
	while (stack)
	{
		func(stack, aux_stack);
		stack = stack->next;
	}
}

/** Iterates through the nodes of the stack and executes the given function
 * @param stack Iterates through the nodes of this stack
 * @param func Function that is going the be executed on each node of stack
 */
void	iterate_stack(t_node *stack, void (*func)(t_node *))
{
	if (!stack || !func)
		return ;
	while (stack)
	{
		func(stack);
		stack = stack->next;
	}
}

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
	while (stack_size(*b) != 2 && stack_size(*a) > 3)
		move_dual(a, b, moves, pb);
	push_sort_b(a, b, moves);
	ft_printf("Moves -> %i\n", *moves);
}
