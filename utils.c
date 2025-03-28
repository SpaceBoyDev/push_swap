/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:00:23 by dario             #+#    #+#             */
/*   Updated: 2025/03/28 21:12:54 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
