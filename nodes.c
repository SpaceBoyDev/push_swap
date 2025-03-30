/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:22:59 by dario             #+#    #+#             */
/*   Updated: 2025/03/30 18:17:05 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_node	*find_last_node(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

void	append_node(t_node **stack_node, int n)
{
	t_node	*node;
	t_node	*last_node;

	if (!stack_node)
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->next = NULL;
	node->value = n;
	if (!(*stack_node))
	{
		*stack_node = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack_node);
		last_node->next = node;
		node->prev = last_node;
	}
}
