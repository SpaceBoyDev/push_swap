/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:54:58 by dario             #+#    #+#             */
/*   Updated: 2025/04/14 21:08:48 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** @brief Realizes moves that only require one stack.
 * 
 * First it checks if the move is possible, then it is executed, one move is
 * added to the counter and the given stack is updated
 * @param stack Stack that is going to execute the move
 * @param moves Numbers of moves done
 * @param move Movement function that is going to be executed
 */
void	move_single(t_node **stack, int *moves, void (*move)(struct s_node **))
{
	if (!(*stack) || !move)
		return ;
	move(stack);
	++(*moves);
	update_stack(*stack);
}

/** @brief Realizes moves that require both stacks.
 * 
 * First it checks if the move is possible, then it is executed, one move is
 * added to the counter and the both stacks are updated
 * @param a Stack a
 * @param b Stack b
 * @param moves Numbers of moves done
 * @param move Movement function that is going to be executed
 */
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
