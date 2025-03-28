/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:22:59 by dario             #+#    #+#             */
/*   Updated: 2025/03/28 21:17:17 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(1 * sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	// node->
	// node->next = NULL;
	return (node);
}

t_node	*find_last(t_node *node)
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
		last_node = find_last(*stack_node);
		last_node->next = node;
		node->prev = last_node;
	}
}
