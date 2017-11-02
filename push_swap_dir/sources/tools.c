/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 15:50:58 by lararamirez       #+#    #+#             */
/*   Updated: 2017/11/02 11:36:05 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			is_sorted(t_element *stack, size_t stack_size)
{
	t_element	*tmp;

	if (stack_size < 2)
		return (1);
	tmp = stack;
	while (stack_size - 1)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (0);
		tmp = tmp->next;
		stack_size--;
	}
	return (1);
}

int			is_rev_sorted(t_element *stack, size_t stack_size)
{
	t_element	*tmp;

	if (stack_size < 2)
		return (1);
	tmp = stack;
	while (stack_size - 1)
	{
		if (tmp->nbr < tmp->next->nbr)
			return (0);
		tmp = tmp->next;
		stack_size--;
	}
	return (1);
}
