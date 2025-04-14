/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:52:41 by dario             #+#    #+#             */
/*   Updated: 2025/04/15 00:09:37 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>

bool	is_unique(int *arr, int size, int num)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == num)
			return false;
	}
	return true;
}

char	**generate_unique_random_numbers(int count)
{
	int		*numbers;
	char	**result;
	int		i = 0;

	if (count <= 0)
		return NULL;
	numbers = malloc(sizeof(int) * count);
	if (!numbers)
		return NULL;
	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
	{
		free(numbers);
		return NULL;
	}
	srand(time(NULL));
	while (i < count)
	{
		int num = (rand() % (INT_MAX + INT_MAX + 1)) - INT_MAX;
		if (is_unique(numbers, i, num))
		{
			numbers[i] = num;
			asprintf(&result[i], "%d", num);
			i++;
		}
	}
	result[count] = NULL;
	free(numbers);
	return result;
}

/** Prints the stack and some of its values in a table.
 * Prints the index, value, prev, next, median and cheap values.
 * @param stack The stack that is going to be printed
 * @param simple_view Whether it's going to be printed in a table or not
*/
void	print_stack_old(t_node **stack, bool simple_view)
{
	t_node	*current;

	current = *stack;
	if (simple_view)
	{
		while (current)
		{
			ft_printf("%d\n", current->value);
			current = current->next;
		}
		return ;
	}
	ft_printf("+-----------------------+-----------------------+-----------------------+");
	ft_printf("-----------------------+-----------------------+--------------------+\n");
	ft_printf("|\tINDEX\t\t|\tVALUE\t\t|\tPREV\t\t|\tNEXT\t\t|\tMEDIAN\t\t|\tCHEAP\t\t|\n");
	ft_printf("+-----------------------+-----------------------+-----------------------+");
	ft_printf("-----------------------+-----------------------+--------------------+\n");
	while (current)
	{
		ft_printf("|\t%d\t\t|\t%d\t\t|", current->index, current->value);
		if (current->prev)
			ft_printf("\t%d\t\t|", current->prev->value);
		else
			ft_printf("\tNULL\t\t|");
		if (current->next)
			ft_printf("\t%d\t\t|", current->next->value);
		else
			ft_printf("\tNULL\t\t|");
		if (current->above_median)
			ft_printf("\t^\t\t|");
		else
			ft_printf("\tv\t\t|");
		if (current->cheapest)
			ft_printf("\tTRUE\t\t|\n");
		else
			ft_printf("\tFALSE\t\t|\n");
		current = current->next;
	}
	ft_printf("+------------------------------------------------------------------------");
	ft_printf("--------------------------------------------------------------------+\n\n");
}

/** Prints the stack and some of its values in a table.
 * Prints index, value, target, cost, median and cheap values.
* @param stack The stack that is going to be printed
* @param simple_view Whether it's going to be printed in a table or not
*/
void	print_stack(t_node **stack, bool simple_view)
{
	t_node	*current;

	current = *stack;
	if (simple_view)
	{
		while (current)
		{
			ft_printf("%d\n", current->value);
			current = current->next;
		}
		return ;
	}
	ft_printf("+-----------------------+-----------------------+-----------------------+");
	ft_printf("-----------------------+-----------------------+-----------------------+\n");
	ft_printf("|\tINDEX\t\t|\tVALUE\t\t|\tTARGET\t\t|\tCOST\t\t|\tMEDIAN\t\t|\tCHEAP\t\t|\n");
	ft_printf("+-----------------------+-----------------------+-----------------------+");
	ft_printf("-----------------------+-----------------------+-----------------------+\n");
	while (current)
	{
		ft_printf("|\t%d\t\t|\t%d\t\t|", current->index, current->value);
		if (current->target)
			ft_printf("\t%d\t\t|", current->target->value);
		else
			ft_printf("\tNULL\t\t|");
		ft_printf("\t%d\t\t|", current->cost);
		if (current->above_median)
			ft_printf("\t^\t\t|");
		else
			ft_printf("\tv\t\t|");
		if (current->cheapest)
			ft_printf("\tTRUE\t\t|\n");
		else
			ft_printf("\tFALSE\t\t|\n");
		current = current->next;
	}
	ft_printf("+------------------------------------------------------------------------");
	ft_printf("-----------------------------------------------------------------------+\n\n");
}

void	check_move(t_node **a, t_node **b, bool simple_view)
{
	print_stack(a, simple_view);
	print_stack(b, simple_view);
}