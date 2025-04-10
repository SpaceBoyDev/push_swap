/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:27:22 by dario             #+#    #+#             */
/*   Updated: 2025/04/10 12:58:14 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	iterate_stack(t_node *a, t_node *b, void (*func)(t_node *, t_node *))
{
	if (!a || !b || !func)
		return ;
	while (a)
	{
		func(a, b);
		a = a->next;
	}
}

void	push_sort_b(t_node **a, t_node **b, int *moves)
{
	iterate_stack(*a, *b, set_target_node);
	print_stack(a, false);
}
