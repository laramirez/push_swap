/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sortable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 16:21:43 by lramirez          #+#    #+#             */
/*   Updated: 2017/12/30 16:21:54 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	is_sortable_in_place_2(size_t *a_size,
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

void	init(size_t *index, t_element **start, t_element **tmp, t_element *a)
{
	*index = 0;
	(*start) = NULL;
	(*tmp) = a;
}

void	set_start(char *swap_needed, t_element **start, t_element *tmp)
{
	if (*swap_needed)
		(*start) = tmp->next->next;
	else if (tmp->nbr > tmp->next->nbr)
		(*start) = tmp->next;
}

char	is_sortable_in_place(t_element *a, size_t a_size)
{
	t_element	*tmp;
	t_element	*start;
	char		swap_needed;
	size_t		index;

	if (a_size <= 2 || (a_size == 3 && is_rev_sorted(a, a_size)))
		return (1);
	init(&index, &start, &tmp, a);
	swap_needed =
		(tmp->nbr > tmp->next->nbr && tmp->nbr < tmp->next->next->nbr) ? 1 : 0;
	while (a_size - 1)
	{
		set_start(&swap_needed, &start, tmp);
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
