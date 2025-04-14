/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:26:58 by dario             #+#    #+#             */
/*   Updated: 2025/04/14 21:24:49 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_median(t_node *node)
{
	int	median;

	median = stack_size(node) / 2;
	while (node)
	{
		if (node->index < median)
			node->above_median = true;
		else
			node->above_median = false;
		node = node->next;
	}
}

t_node	*set_cheapest(t_node *node)
{
	t_node	*tmp;
	int		cheapest;

	if (!node)
		return (NULL);
	cheapest = node->cost;
	tmp = node;
	while (node)
	{
		if (node->cost < cheapest)
		{
			cheapest = node->cost;
			tmp = node;
		}
		node->cheapest = false;
		node = node->next;
	}
	tmp->cheapest = true;
	return (tmp);
}

static void	update_index(t_node *node)
{
	int	n;

	n = 0;
	while (node)
	{
		node->index = n;
		node = node->next;
		++n;
	}
}

void	update_stack(t_node *node)
{
	if (!node || node->prev)
		return ;
	update_index(node);
	update_median(node);
}
