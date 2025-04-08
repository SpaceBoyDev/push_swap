/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:27:58 by dario             #+#    #+#             */
/*   Updated: 2025/04/08 19:55:19 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack)
{
	if (!(*stack) || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	sa(t_node **stack)
{
	swap(stack);
	ft_printf("%s\n", __func__);
}

void	sb(t_node **stack)
{
	swap(stack);
	ft_printf("%s\n", __func__);
}

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	ft_printf("%s\n", __func__);
}
