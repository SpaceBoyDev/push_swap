/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:47:54 by dario             #+#    #+#             */
/*   Updated: 2025/03/30 18:12:27 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>

# include "libft/libft.h"

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
void	init_stack_a(t_node **stack_node, char **argv);
int		*single_arg(char *argv);
int		*multiple_args(char **argv);

// Node Utils
bool	is_stack_sorted(t_node *node);
t_node	*find_last_node(t_node *node);
void	append_node(t_node **stack_node, int n);

// Utils
bool	is_arg_valid(char *argv);

// Handle Errors
void	error_exit(const char *error_message);
void	error_free(t_node **stack, const char *error_message);
void	free_stack(t_node **stack);
bool	error_duplicate(t_node *node, int n);

#endif