/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:26:58 by dario             #+#    #+#             */
/*   Updated: 2025/04/10 14:10:38 by dario            ###   ########.fr       */
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

static void	update_cheapest(t_node *node)
{
	t_node	*tmp;
	int		cheapest;

	cheapest = node->value;
	while (node)
	{
		if (node->value <= cheapest)
		{
			cheapest = node->value;
			tmp = node;
		}
		node->cheapest = false;
		node = node->next;
	}
	tmp->cheapest = true;
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
	update_cheapest(node);
}
