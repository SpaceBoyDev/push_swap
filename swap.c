/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:27:58 by dario             #+#    #+#             */
/*   Updated: 2025/04/07 20:35:24 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node *node)
{
	int	tmp;

	if (!node)
		return ;
	tmp = node->value;
	node->value = node->next->value;
	node->next->value = tmp;
	ft_printf("sa\n");
}

void	sb(t_node *node)
{
	int	tmp;

	if (!node)
		return ;
	tmp = node->value;
	node->value = node->next->value;
	node->next->value = tmp;
	ft_printf("sb\n");
}

void	ss(t_node *a, t_node *b)
{
	int	tmp;

	if (!a || !b)
		return ;
	tmp = a->value;
	a->value = a->next->value;
	a->next->value = tmp;
	tmp = b->value;
	b->value = b->next->value;
	b->next->value = tmp;
	ft_printf("ss\n");
}
