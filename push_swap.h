/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:47:54 by dario             #+#    #+#             */
/*   Updated: 2025/04/15 03:08:49 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>

# include "libft/libft.h"

# define PRINT_DEBUG true

typedef struct s_node
{
	int				value;
	int				index;
	int				cost;
	bool			above_median;
	bool			cheapest;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

// Stack Init
void	init_stack_a(t_node **stack, char **argv, bool split);
int		*single_arg(char *argv);
int		*multiple_args(char **argv);

// Algorithm
void	turk_algo(t_node **a, t_node **b, int *moves);

// Movements
void	move_single(t_node **stack, int *moves,
			void (*move)(struct s_node **));
void	move_dual(t_node **a, t_node **b, int *moves,
			void (*move)(struct s_node **, struct s_node **));
void	select_move_a(t_node **a, t_node **b, t_node *push_node, int *moves);
void	select_move_b(t_node **a, t_node **b, t_node *push_node, int *moves);

// Moves
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);

void	swap(t_node **stack);
void	sa(t_node **stack);
void	sb(t_node **stack);
void	ss(t_node **a, t_node **b);

void	ra(t_node **stack);
void	rb(t_node **stack);
void	rr(t_node **a, t_node **b);

void	rra(t_node **stack);
void	rrb(t_node **stack);
void	rrr(t_node **a, t_node **b);

// Nodes
void	set_cost_node(t_node *node);
int		stack_size(t_node *node);
bool	is_stack_sorted(t_node *node);
void	append_node(t_node **stack_node, int n);

// Node Utils
t_node	*find_first_node(t_node *node);
t_node	*find_last_node(t_node *node);
t_node	*find_min_value(t_node *stack);
t_node	*find_max_value(t_node *stack);

// Update Nodes
t_node	*set_cheapest(t_node *node);
void	set_target_node_a(t_node *node, t_node *b);
void	set_target_node_b(t_node *node, t_node *a);
void	update_stack(t_node *node);

// Utils
void	iterate_stack_dual(t_node *a, t_node *b,
			void (*func)(t_node *, t_node *));
void	iterate_stack(t_node *stack, void (*func)(t_node *));

long	ft_atol(const char *nptr);
bool	is_arg_valid(char *argv);

// Free Variables
void	free_split(char **split);

// Handle Errors
void	error_exit(const char *error_message);
void	error_free(t_node **stack, const char *error_message);
void	free_stack(t_node **stack);
bool	error_duplicate(t_node *node, int n);

// DEBUG
void	print_stack(t_node **stack, bool simple_view);
void	check_move(t_node **a, t_node **b, bool simple_view);

#endif