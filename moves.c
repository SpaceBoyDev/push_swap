/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:54:58 by dario             #+#    #+#             */
/*   Updated: 2025/04/07 20:28:11 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	movement(t_node *stack, int *moves, void (*move)(struct s_node *))
{
	if (!stack || !move)
		return ;
	move(stack);
	++(*moves);
}
