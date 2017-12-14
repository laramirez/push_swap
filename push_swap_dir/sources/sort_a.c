/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 10:41:55 by lramirez          #+#    #+#             */
/*   Updated: 2017/12/14 12:11:28 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char		sort_a_2(t_struct *stacks, t_element *tmp,
				size_t *index, t_list **instructions)
{
	if (tmp->nbr > tmp->next->nbr)
	{
		if (*index == 0 && tmp->nbr < tmp->next->next->nbr)
			swap(stacks, instructions, 'a');
		else if (*index < (stacks->a_size / 2))
		{
			while (*index + 1)
			{
				rotate(stacks, instructions, 'a');
				(*index)--;
			}
		}
		else
		{
			*index = stacks->a_size - *index - 1;
			while (*index)
			{
				rev_rotate(stacks, instructions, 'a');
				(*index)--;
			}
		}
		return (1);
	}
	return (0);
}

void		sort_a(t_struct *stacks, size_t a_size, t_list **instructions)
{
	t_element	*tmp;
	size_t		index;

	if (a_size == 2)
		swap(stacks, instructions, 'a');
	else
	{
		tmp = stacks->a;
		index = 0;
		while (index < a_size)
		{
			if (sort_a_2(stacks, tmp, &index, instructions))
				return ;
			index++;
			tmp = tmp->next;
		}
	}
}

char		is_sortable_in_place_2(size_t *a_size,
				char *swap_needed, t_element **start)
{
	while (*a_size - *swap_needed * 2 - 1)
	{
		if ((*start)->nbr > (*start)->next->nbr)
			return (0);
		(*start) = (*start)->next;
		(*a_size)--;
	}
	return (1);
}

void		init(size_t *index, size_t *anomaly, t_element **start)
{
	*index = 0;
	*anomaly = 0;
	(*start) = NULL;
}

char		is_sortable_in_place(t_element *a, size_t a_size)
{
	t_element	*tmp;
	t_element	*start;
	char		swap_needed;
	size_t		index;
	size_t		anomaly;

	if (a_size <= 2)
		return (1);
	tmp = a;
	swap_needed =
		(tmp->nbr > tmp->next->nbr && tmp->nbr < tmp->next->next->nbr) ? 1 : 0;
	init(&index, &anomaly, &start);
	while (a_size - 1)
	{
		if (swap_needed)
			start = tmp->next->next;
		else if (tmp->nbr > tmp->next->nbr)
			start = tmp->next;
		if (start)
		{
			if (is_sortable_in_place_2(&a_size, &swap_needed, &start))
				break ;
			else
				return (0);
		}
		tmp = tmp->next;
		a_size--;
	}
	return (1);
}
