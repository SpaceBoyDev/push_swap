/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:00:23 by dario             #+#    #+#             */
/*   Updated: 2025/03/30 18:44:46 by dario            ###   ########.fr       */
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
