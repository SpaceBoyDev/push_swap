/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:54:58 by dario             #+#    #+#             */
/*   Updated: 2025/04/08 20:03:41 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_single(t_node **stack, int *moves, void (*move)(struct s_node **))
{
	if (!(*stack) || !move)
		return ;
	move(stack);
	++(*moves);
	update_stack(*stack);
}

void	move_dual(t_node **a, t_node **b, int *moves,
			void (*move)(struct s_node **, struct s_node **))
{
	if (!a || !b || !move)
		return ;
	move(a, b);
	++(*moves);
	update_stack(*a);
	update_stack(*b);
}
