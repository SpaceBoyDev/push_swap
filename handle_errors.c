/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 20:02:33 by dario             #+#    #+#             */
/*   Updated: 2025/04/15 03:23:14 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** Prints in yellow the error message given below a red ERROR square
 * @param error_message Error message that's going to be displayed
*/
static void	error_msg(const char *error_message)
{
	ft_printf(RED"\n-----\nERROR\n-----\n");
	if (error_message)
		ft_printf(YELLOW"%s\n"RST, error_message);
}

/** Exits the program after printing the error message
 * @param error_message Error message that's going to be displayed
 */
void	error_exit(const char *error_message)
{
	error_msg(error_message);
	exit(1);
}

/** Frees the given stack, displays an error message and exits the program
 * @param stack Stack that's going to be freed
 * @param error_message Error message that's going to be displayed
 */
void	error_free(t_node **stack, const char *error_message)
{
	free_stack(stack);
	error_msg(error_message);
	exit(1);
}

/** Checks if n is already a value in the stack.
 * @param stack Stack that is going to be checked
 * @param n Number that is going to be checked
 * @return Returns true if n is found in the stack. Returns false if it isn't.
*/
bool	error_duplicate(t_node *stack, int n)
{
	if (!stack)
		return (false);
	while (stack)
	{
		if (stack->value == n)
			return (true);
		stack = stack->next;
	}
	return (false);
}
