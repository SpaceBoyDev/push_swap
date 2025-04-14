/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:27:57 by dario             #+#    #+#             */
/*   Updated: 2025/04/14 21:25:07 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** @brief Finds the first node of a given stack.
 * 
 * Starting from the given node, it finds the first node of its stack
 * @param node Node from where it's going to start
 * @return The first node of the stack
*/
t_node	*find_first_node(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->prev != NULL)
		node = node->prev;
	return (node);
}

/** @brief Finds the last node of a given stack.
 * 
 * Starting from the given node, it finds the last node of its stack
 * @param node Node from where it's going to start
 * @return The last node of the stack
*/
t_node	*find_last_node(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

// t_node	*find_min_value(t_node *stack)
// {
// 	int		lowest;
// 	t_node	*tmp;
// 	if (!stack)
// 		return (NULL);
// 	lowest = stack->value;
// 	while (stack)
// 	{
// 		if (stack->value <= lowest)
// 		{
// 			lowest = stack->value;
// 			tmp = stack;
// 		}
// 		stack = stack->next;
// 	}
// 	return (tmp);
// }

/** @brief Finds the highest value node of a given stack.
 * 
 * Starting from the given node, it finds the highest value node of its stack
 * @param node Node from where it's going to start
 * @return The highest value node of the stack
*/
t_node	*find_max_value(t_node *stack)
{
	int		max;
	t_node	*tmp;

	if (!stack)
		return (NULL);
	max = stack->value;
	while (stack)
	{
		if (stack->value >= max)
		{
			max = stack->value;
			tmp = stack;
		}
		stack = stack->next;
	}
	return (tmp);
}
