/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 12:11:19 by lararamirez       #+#    #+#             */
/*   Updated: 2017/10/31 18:22:14 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			is_sorted(t_element *stack_top, size_t stack_size)
{
	t_element	*tmp;

	if (stack_size < 2)
		return (1);
	tmp = stack_top;
	while (stack_size - 1)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (0);
		tmp = tmp->next;
		stack_size--;
	}
	return (1);
}

int			is_rev_sorted(t_element *stack_bottom, size_t stack_size)
{
	t_element	*tmp;

	if (stack_size < 2)
		return (1);
	tmp = stack_bottom;
	while (stack_size - 1)
	{
		if (tmp->nbr > tmp->previous->nbr)
			return (0);
		tmp = tmp->previous;
		stack_size--;
	}
	return (1);
}

// size_t		cost_to_sort(t_elem *current, t_struct *stacks)
// {
// 	return ();
// }

// void		select_cheapest_move(t_struct *stacks)
// {

// }

// t_list		**compute_solution(t_stack *a, t_stack *b, t_list **instructions)
// {
// 	while (!is_sorted(a) && a->size > 2)
// 	{
// 		if (a->size == 3 && is_rev_sorted(a))
// 		{
// 			swap(a, instructions, 'a');
// 			rev_rotate(a, instructions, 'a');
// 			break ;
// 		}
// 		min1_index = get_min_index(a);
// 		select_min_and_bubble(a, b, min1_index, instructions);
// 	}
// 	if (a->size == 2 && !is_sorted(a))
// 		swap(a, instructions, 'a');
// 	while (b->size)
// 		push(b, a, instructions, 'a');
// 	return (optimize(instructions));
// }
