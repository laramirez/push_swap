/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 12:11:19 by lararamirez       #+#    #+#             */
/*   Updated: 2017/09/11 20:11:04 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		bubble1(t_stack *a, t_stack *b, size_t index, t_list **instructions)
{
	t_element	*tmp;
	int			move;

	tmp = a->top;
	while (tmp->index != index)
		tmp = tmp->next;
	move = tmp->nbr;
	if (index <= a->middle)
	{
		while (a->top->nbr != move)
			rotate(a, instructions, 'a');
	}
	else
	{
		while (a->top->nbr != move)
			rev_rotate(a, instructions, 'a');
	}
	if (!is_sorted(a))
		push(a, b, instructions, 'b');
}

void		bubble2(t_stack *a, t_stack *b, size_t index, t_list **instructions)
{
	bubble1(a, b, index, instructions);
	if (!is_sorted(a))
	{
		bubble1(a, b, get_min_index(a), instructions);
		if (b->size == 2)
			rotate(b, instructions, 'b');
		else
			swap(b, instructions, 'b');
	}
}

size_t		cost(t_stack *a, size_t index)
{
	return ((index <= a->middle) ? index : a->size - index);
}

void		select_min_and_bubble(t_stack *a, t_stack *b,
				size_t min1_index, t_list **instructions)
{
	size_t	min2_index;

	min2_index = get_second_min_index(a, min1_index);
	if (min1_index == 1 && min2_index == 0)
		swap(a, instructions, 'a');
	else
		(cost(a, min1_index) <= cost(a, min2_index) ||
			min1_index == a->size - 1) ?
				bubble1(a, b, min1_index, instructions) :
					bubble2(a, b, min2_index, instructions);
}

t_list		**compute_solution(t_stack *a, t_stack *b, t_list **instructions)
{
	size_t	min1_index;

	while (!is_sorted(a) && a->size > 2)
	{
		if (a->size == 3 && is_rev_sorted(a))
		{
			swap(a, instructions, 'a');
			rev_rotate(a, instructions, 'a');
			break ;
		}
		min1_index = get_min_index(a);
		select_min_and_bubble(a, b, min1_index, instructions);
	}
	if (a->size == 2 && !is_sorted(a))
		swap(a, instructions, 'a');
	while (b->size)
		push(b, a, instructions, 'a');
	return (optimize(instructions));
}
