/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 12:05:38 by lramirez          #+#    #+#             */
/*   Updated: 2017/12/14 13:38:01 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char		sort_b_2(t_struct *stacks, t_element *tmp,
				size_t *index, t_list **instructions)
{
	if (tmp->nbr < tmp->next->nbr)
	{
		if (*index < (stacks->a_size / 2))
		{
			*index = stacks->a_size - *index - 1;
			while (*index)
			{
				rev_rotate(stacks, instructions, 'b');
				(*index)--;
			}
		}
		else
		{
			while (*index + 1)
			{
				rotate(stacks, instructions, 'b');
				(*index)--;
			}
		}
		return (1);
	}
	return (0);
}

void		sort_b(t_struct *stacks, size_t b_size, t_list **instructions)
{
	t_element	*tmp;
	size_t		index;

	tmp = stacks->b;
	index = 0;
	while (index < b_size)
	{
		if (sort_b_2(stacks, tmp, &index, instructions))
			return ;
		index++;
		tmp = tmp->next;
	}
}
