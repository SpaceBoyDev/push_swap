/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 18:38:58 by dario             #+#    #+#             */
/*   Updated: 2025/04/15 03:23:26 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** Frees a char **
 * @param split Char ** that is going to be freed
*/
void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		++i;
	}
	free(split);
	split = NULL;
}

/** Frees all the nodes of the given stack
 * @param stack Stack that is going to be freed
 */
void	free_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->value = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}
