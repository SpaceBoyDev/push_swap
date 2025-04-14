/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:00:23 by dario             #+#    #+#             */
/*   Updated: 2025/04/15 00:22:46 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** Iterates through the nodes of the stack and executes a function
 * that needs both stacks on each node
 * @param stack Iterates through the nodes of this stack
 * @param aux_stack Aux stack needed to perform the function
 * @param func Function that is going to be executed on each node of stack
*/
void	iterate_stack_dual(t_node *stack, t_node *aux_stack,
	void (*func)(t_node *, t_node *))
{
	if (!stack || !aux_stack || !func)
		return ;
	while (stack)
	{
		func(stack, aux_stack);
		stack = stack->next;
	}
}

/** Iterates through the nodes of the stack and executes the given function
* @param stack Iterates through the nodes of this stack
* @param func Function that is going the be executed on each node of stack
*/
void	iterate_stack(t_node *stack, void (*func)(t_node *))
{
	if (!stack || !func)
		return ;
	while (stack)
	{
		func(stack);
		stack = stack->next;
	}
}

bool	is_arg_valid(char *argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]) && argv[i] != '-' && argv[i] != '+')
			return (false);
		++i;
	}
	return (true);
}

long	ft_atol(const char *nptr)
{
	long	num;
	int		negative;

	num = 0;
	negative = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		++nptr;
	if (*nptr == '-')
	{
		if (!ft_isdigit(*(nptr + 1)))
			return (0);
		negative = -1;
		++nptr;
	}
	if (*nptr == '+' && ft_isdigit(*(nptr + 1)))
		++nptr;
	else if (*nptr == '+' && !ft_isdigit(*(nptr + 1)))
		return (0);
	while (ft_isdigit(*nptr))
	{
		num = (num * 10) + ((int)*nptr - '0');
		++nptr;
	}
	return (num * negative);
}
