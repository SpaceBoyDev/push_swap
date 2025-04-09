/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:36:10 by dario             #+#    #+#             */
/*   Updated: 2025/04/09 18:50:29 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **stack)
{
	if (!(*stack) || !(*stack)->next)
		return ;
	if (stack_size(*stack) == 2)
	{
		swap(stack);
		return ;
	}
	*stack = (*stack)->next;
	(*stack)->prev->prev = find_last_node(*stack);
	(*stack)->prev->next = NULL;
	find_last_node(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	ra(t_node **stack)
{
	rotate(stack);
	ft_printf("%s\n", __func__);
}

void	rb(t_node **stack)
{
	rotate(stack);
	ft_printf("%s\n", __func__);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("%s\n", __func__);
}