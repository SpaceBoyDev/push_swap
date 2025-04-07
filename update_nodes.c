/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:26:58 by dario             #+#    #+#             */
/*   Updated: 2025/04/07 20:48:50 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_stack(t_node *node)
{
	update_index(node);
}

void	update_index(t_node *node)
{
	int	n;

	if (!node || node->prev != NULL)
		return ;
	n = 0;
	while (node)
	{
		node->index = n;
		node = node->next;
		++n;
	}
}
