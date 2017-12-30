/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_compute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 11:14:39 by lararamirez       #+#    #+#             */
/*   Updated: 2017/12/30 16:02:57 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bubble_up_min(size_t index, t_struct *stacks, t_list **instructions)
{
	if (index <= stacks->a_size / 2)
	{
		while (index)
		{
			if (is_sortable_in_place(stacks->a, stacks->a_size))
				return ;
			rotate(stacks, instructions, 'a');
			index--;
		}
	}
	else
	{
		while (index < stacks->a_size)
		{
			if (is_sortable_in_place(stacks->a, stacks->a_size))
				return ;
			rev_rotate(stacks, instructions, 'a');
			index++;
		}
	}
}

size_t	find_min_index(t_struct *stacks)
{
	int			min;
	t_element	*tmp;
	size_t		size;
	size_t		index;
	size_t		index_min;

	min = stacks->a->nbr;
	tmp = stacks->a;
	size = stacks->a_size;
	index = 0;
	index_min = 0;
	while (size)
	{
		if (tmp->nbr < min)
		{
			min = tmp->nbr;
			index_min = index;
		}
		index++;
		size--;
		tmp = tmp->next;
	}
	return (index_min);
}

void	small_compute(t_struct *stacks, t_list **instructions)
{
	while (!is_sorted(stacks->a, stacks->a_size))
	{
		if (is_sortable_in_place(stacks->a, stacks->a_size))
			sort_a(stacks, stacks->a_size, instructions);
		else
		{
			bubble_up_min(find_min_index(stacks), stacks, instructions);
			if (is_sortable_in_place(stacks->a, stacks->a_size))
				sort_a(stacks, stacks->a_size, instructions);
			else
				push_a(stacks, instructions);
		}
	}
	while (stacks->b_size)
		push_b(stacks, instructions);
}
