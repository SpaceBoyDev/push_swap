/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:36:08 by dario             #+#    #+#             */
/*   Updated: 2025/04/09 20:32:43 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_node **stack)
{
	t_node	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	if (stack_size(*stack) == 2)
	{
		swap(stack);
		return ;
	}
	tmp = *stack;
	*stack = find_last_node(*stack);
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
	(*stack)->next = tmp;
	tmp->prev = *stack;
	tmp = NULL;
}

void	rra(t_node **stack)
{
	rev_rotate(stack);
	ft_printf("%s\n", __func__);
}

void	rrb(t_node **stack)
{
	rev_rotate(stack);
	ft_printf("%s\n", __func__);
}

void	rrr(t_node **a, t_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("%s\n", __func__);
}
