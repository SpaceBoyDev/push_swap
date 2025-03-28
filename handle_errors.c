/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 20:02:33 by dario             #+#    #+#             */
/*   Updated: 2025/03/28 22:19:21 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_msg(const char *error_message)
{
	ft_printf(RED"\n-----\nERROR\n-----\n");
	if (error_message)
		ft_printf(YELLOW"%s\n"RST, error_message);
}

void	error_exit(const char *error_message)
{
	error_msg(error_message);
	exit(1);
}

void	error_free(t_node **stack, const char *error_message)
{
	free_stack(stack);
	error_msg(error_message);
	exit(1);
}

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

bool	error_duplicate(t_node *node, int n)
{
	if (!node)
		return (false);
	while (node)
	{
		if (node->value == n)
			return (true);
		node = node->next;
	}
	return (false);
}