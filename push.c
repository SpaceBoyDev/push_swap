/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:35:50 by dario             #+#    #+#             */
/*   Updated: 2025/04/08 20:19:23 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **dst, t_node **src) //Define a function that pushes a top node, from one stack to another's top node
{
	t_node	*push_node; //Used to store the pointer to the node to be pushed

	if (!*src) //The top node of a stack to be pushed
		return ;
	push_node = *src; //The top node to push is assigned to the `t_node` variable
	*src = (*src)->next; //Move the pointer of the stack to the next node, which will become the next `top node` after the node before is "popped off"
	if (*src) //Check if the current node exists
		(*src)->prev = NULL; //Set the current node as the head of the stack
	push_node->prev = NULL; //Detach the node to push from its stack
	if (!*dst) //Check if the other stack is empty
	{
		*dst = push_node; //If it's empty, assign as the first node of that stack, the node we want pushed
		push_node->next = NULL; //Ensure it is also set as the last node, e.g. properly null terminate the stack
	}
	else //If the other stack we want to push to is not empty
	{
		push_node->next = *dst; //Assign the node to push, to the top of the current top node of the stack
		push_node->next->prev = push_node; //Assign to the "second node" `prev` attribute, the pushed node as the current top node
		*dst = push_node; //Complete appending the node. The pointer to the top node of the stack is now pointing to our recently pushed node
	}
}

void	pa(t_node **a, t_node **b) //Push on top of `b`, the top `a` and print the instruction
{
	push(a, b); 
	ft_printf("pa\n");
}

void	pb(t_node **b, t_node **a) //Push on top of `a`, the top `b` and print the instruction
{
	push(b, a);
	ft_printf("pb\n");
}

// void	pa(t_node *a, t_node *b)
// {
// 	if (!a || !b)
// 		return ;
// 	b->next = a;
// 	a->prev = b;
// }

// void	pb(t_node *a, t_node *b)
// {
// 	if (!a)
// 		return ;
// 	if (!b)
// 		a->next = NULL;
// 	else
// 	{
// 		a->next = b;
// 		b->prev = a;
// 	}
// }