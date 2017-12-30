/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 10:41:55 by lramirez          #+#    #+#             */
/*   Updated: 2017/12/30 16:22:38 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	sort_a_2(t_struct *stacks, t_element *tmp,
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

void	sort_a(t_struct *stacks, size_t a_size, t_list **instructions)
{
	t_element	*tmp;
	size_t		index;

	if (a_size == 2)
		swap(stacks, instructions, 'a');
	else if (a_size == 3 && is_rev_sorted(stacks->a, a_size))
	{
		rotate(stacks, instructions, 'a');
		swap(stacks, instructions, 'a');
	}
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

char	sort_b_2(t_struct *stacks, t_element *tmp,
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

void	sort_b(t_struct *stacks, size_t b_size, t_list **instructions)
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
