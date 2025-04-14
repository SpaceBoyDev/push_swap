/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:22:59 by dario             #+#    #+#             */
/*   Updated: 2025/04/14 20:47:30 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node *node)
{
	int	size;

	size = 0;
	if (!node)
		return (size);
	while (node)
	{
		node = node->next;
		++size;
	}
	return (size);
}

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

void	set_target_node(t_node *node, t_node *b)
{
	int		min_delta;
	t_node	*tmp;
	if (!node || !b)
		return ;
	min_delta = INT_MAX;
	tmp = b;
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
		target_cost = stack_size(find_first_node(node->target)) - node->target->index;
	node->cost = node_cost + target_cost;
	
}

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
