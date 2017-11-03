/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 12:11:19 by lararamirez       #+#    #+#             */
/*   Updated: 2017/11/03 09:57:39 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void        sort_a(t_struct *stacks, size_t a_size, t_list **instructions)
{
	t_element   *tmp;
	size_t      index;

	printf("it is %zu\n", a_size / 2);
	if (a_size == 2)
		swap(stacks, instructions, 'a');
	else
	{
		tmp = stacks->a;
		index = 0;
		while (a_size - 1)
		{
			if (tmp->nbr > tmp->next->nbr)
			{
				if (index == 0 && tmp->nbr < tmp->next->next->nbr)
				{
					swap(stacks, instructions, 'a');
					return ;
				}
				else if (index < a_size / 2)
				{
					while (index + 1)
					{
						rotate(stacks, instructions, 'a');
						index--;
					}
					return ;
				}
				else
				{
					while (index)
					{
						rev_rotate(stacks, instructions, 'a');
						index--;
					}
					return ;
				}
			}
			a_size--;
			index++;
			tmp = tmp->next;
		}
	}
}

char        is_sortable_in_place(t_element *a, size_t a_size)
{
	t_element   *tmp;
	size_t      swap_needed;
	size_t      index;
	size_t      anomaly;

	if (a_size <= 2)
		return (1);
	tmp = a;
	swap_needed = (tmp->nbr > tmp->next->nbr && tmp->nbr < tmp->next->next->nbr) ? 1 : 0;
	index = 0;
	anomaly = 0;
	while (a_size - 1)
	{
		if (swap_needed && tmp != a && tmp->nbr > tmp->next->nbr)
			return (0);
		else if (tmp->nbr > tmp->next->nbr)
			anomaly++;
		tmp = tmp->next;
		a_size--;
	}
	if (anomaly < 2)
		return (1);
	return (0);
}

t_list		**compute_solution(t_struct *stacks, t_list **instructions)
{
	char test;

	test = 1;
	while (!is_sorted(stacks->a, stacks->a_size) && test)
	{
		if (is_sortable_in_place(stacks->a, stacks->a_size))
			sort_a(stacks, stacks->a_size, instructions);
		test--;
		// else
		//     push_cheapest_onto_b(stacks, instructions);
	}
	// if (stacks->b_size)
	//     push_back_onto_a(stacks, instructions);
	return (instructions);
}
