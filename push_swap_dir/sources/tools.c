/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 15:50:58 by lararamirez       #+#    #+#             */
/*   Updated: 2017/09/11 16:19:48 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t		get_min_index(t_stack *a)
{
	t_element	*tmp;
	int			min;
	size_t		min_index;

	if (a->size < 2)
		return (0);
	tmp = a->top;
	min = tmp->nbr;
	min_index = tmp->index;
	while (tmp)
	{
		if (min > tmp->nbr)
		{
			min = tmp->nbr;
			min_index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (min_index);
}

size_t		get_second_min_index(t_stack *a, size_t ignore_index)
{
	t_element	*tmp;
	int			min;
	size_t		min_index;

	tmp = a->top;
	if (ignore_index == 0)
		tmp = tmp->next;
	min = tmp->nbr;
	min_index = tmp->index;
	while (tmp)
	{
		if (min > tmp->nbr && tmp->index != ignore_index)
		{
			min = tmp->nbr;
			min_index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (min_index);
}

void		duplicates_check(t_stack *stack)
{
	size_t		i;
	int			tab[stack->size];
	t_element	*tmp;

	i = 0;
	tmp = stack->top;
	while (tmp)
	{
		tab[i] = tmp->nbr;
		i++;
		tmp = tmp->next;
	}
	ft_tab_quicksort(tab, 0, i - 1);
	i = 0;
	while ((i + 1) < stack->size)
	{
		if (tab[i] == tab[i + 1])
			ft_kill();
		i++;
	}
}

int			is_sorted(t_stack *stack)
{
	t_element	*tmp;

	if (stack->size < 2)
		return (1);
	tmp = stack->top;
	while (tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int			is_rev_sorted(t_stack *stack)
{
	t_element	*tmp;

	if (stack->size < 2)
		return (1);
	tmp = stack->top;
	while (tmp->next)
	{
		if (tmp->nbr < tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
