/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:22:59 by dario             #+#    #+#             */
/*   Updated: 2025/04/15 00:20:21 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** @brief Checks if the given stack is sorted
 * @param Node from where it starts to check
 * @return True if the stack is sorted. False if it isn't
 */
bool	is_stack_sorted(t_node *node)
{
	int	n;

	if (!node)
		return (true);
	n = node->value;
	while (node)
	{
		if (n > node->value)
			return (false);
		n = node->value;
		node = node->next;
	}
	return (true);
}

/** @brief Sets the target node of a given node of the stack a
 * @param node Node that it's going to have its target set
 * @param b Used to check target candidate nodes
 */
void	set_target_node_a(t_node *node, t_node *b)
{
	int		min_delta;
	t_node	*tmp;

	if (!node || !b)
		return ;
	min_delta = INT_MAX;
	tmp = b;
	node->target = NULL;
	while (b)
	{
		if (b->value < node->value && (node->value - b->value) < min_delta)
		{
			min_delta = node->value - b->value;
			node->target = b;
		}
		b = b->next;
	}
	if (node->target)
		return ;
	node->target = find_max_value(find_first_node(tmp));
}

/** @brief Sets the target node of a given node of the stack b
 * @param node Node that it's going to have its target set
 * @param a Used to check target candidate nodes
 */
void	set_target_node_b(t_node *node, t_node *a)
{
	int		min_delta;
	t_node	*tmp;

	if (!node || !a)
		return ;
	min_delta = INT_MAX;
	tmp = a;
	node->target = NULL;
	while (a)
	{
		if (a->value > node->value && (a->value - node->value) < min_delta)
		{
			min_delta = a->value - node->value;
			node->target = a;
		}
		a = a->next;
	}
	if (node->target)
		return ;
	node->target = find_min_value(find_first_node(tmp));
}

/** @brief Sets the push cost of a given node
 * 
 * @param node Node that is going to have it's push cost calculated
 */
void	set_cost_node(t_node *node)
{
	int	node_cost;
	int	target_cost;

	if (!node)
		return ;
	if (node->above_median)
		node_cost = node->index;
	else
		node_cost = stack_size(find_first_node(node)) - node->index;
	if (node->target->above_median)
		target_cost = node->target->index;
	else
		target_cost = stack_size(find_first_node(node->target))
			- node->target->index;
	node->cost = node_cost + target_cost;
}

/** @brief Appends a new node to the end of a stack
 * @param stack Stack that the new node is going to be appended to
 * @param n Value that it's going to have the new node
 */
void	append_node(t_node **stack, int n)
{
	t_node	*node;
	t_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->next = NULL;
	node->value = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}
