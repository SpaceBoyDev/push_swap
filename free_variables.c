/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 18:38:58 by dario             #+#    #+#             */
/*   Updated: 2025/03/30 18:40:40 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int     i;

	if (!split)
			return ;
	i = 0;
	while (split[i])
	{
			free(split[i]);
			i++;
	}
	free(split);
	split = NULL;
}