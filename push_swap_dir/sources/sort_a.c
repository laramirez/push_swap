/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 10:41:55 by lramirez          #+#    #+#             */
/*   Updated: 2017/11/03 11:02:32 by lramirez         ###   ########.fr       */
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
		while (index < a_size)
		{
            if (tmp->nbr > tmp->next->nbr)
			{
				if (index == 0 && tmp->nbr < tmp->next->next->nbr)
				{
					swap(stacks, instructions, 'a');
					return ;
				}
				else if (index < (a_size / 2))
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
                    index = a_size - index - 1;
                    while (index)
					{
                        rev_rotate(stacks, instructions, 'a');
						index--;
					}
					return ;
				}
			}
			index++;
			tmp = tmp->next;
		}
	}
}

char        is_sortable_in_place(t_element *a, size_t a_size)
{
	t_element   *tmp;
	t_element	*start;
	char      	swap_needed;
	size_t      index;
	size_t      anomaly;

	if (a_size <= 2)
		return (1);
	tmp = a;
	swap_needed = (tmp->nbr > tmp->next->nbr && tmp->nbr < tmp->next->next->nbr) ? 1 : 0;
	index = 0;
	anomaly = 0;
	start = NULL;
	while (a_size - 1)
	{
		if (swap_needed)
			start = tmp->next->next;
		else if (tmp->nbr > tmp->next->nbr)
			start = tmp->next;
		if (start)
		{
			while (a_size - swap_needed * 2 - 1)
			{
				if (start->nbr > start->next->nbr)
					return (0);
				start = start->next;
				a_size--;
			}
			break ;
		}
		tmp = tmp->next;
		a_size--;
	}
	return (1);
}
