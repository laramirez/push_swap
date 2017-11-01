/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 12:20:18 by lararamirez       #+#    #+#             */
/*   Updated: 2017/11/01 14:21:03 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_struct *stacks, t_list **instructions, char target)
{
	int			tmp;

	if (target == 'a')
	{
		if (stacks->a_size <= 1)
			return ;
		tmp = stacks->a->nbr;
		stacks->a->nbr = stacks->a->next->nbr;
		stacks->a->next->nbr = tmp;
		// add_to_list(instructions, "sa");
	}
	else if (target == 'b')
	{
		if (stacks->b_size <= 1)
			return ;
		tmp = stacks->b->nbr;
		stacks->b->nbr = stacks->b->next->nbr;
		stacks->b->next->nbr = tmp;
		// add_to_list(instructions, "sb");
	}
	if (!instructions)
		return ;
}

void	rotate(t_struct *stacks, t_list **instructions, char target)
{
	if (target == 'a')
	{
		if (stacks->a_size <= 1)
			return ;
		stacks->a = stacks->a->next;
		// add_to_list(instructions, "ra");
	}
	else if (target == 'b')
	{
		if (stacks->b_size <= 1)
			return ;
		stacks->b = stacks->b->next;
		// add_to_list(instructions, "rb");
	}
	if (!instructions)
		return ;
}
	
void	rev_rotate(t_struct *stacks, t_list **instructions, char target)
{

	if (target == 'a')
	{
		if (stacks->a_size <= 1)
			return ;
		stacks->a = stacks->a->previous;
		// add_to_list(instructions, "ra");
	}
	if (target == 'b')
	{
		if (stacks->a_size <= 1)
			return ;
		stacks->b = stacks->b->previous;
		// add_to_list(instructions, "ra");
	}
	if (!instructions)
		return ;
}

// void	push(t_struct *stacks, t_list **instructions, char target)
// {
// 	t_element	*tmp;

// 	if (target == 'a')
// 	{
// 		if (stacks->a_size == 0)
// 			return ;
// 		else
// 		{
// 			tmp = stacks->a_top;
// 			if (stacks->a_size > 1)
// 				stacks->a_top = stacks->a_top->next;
// 			(stacks->a_size)--;
// 			stacks->b_top = tmp;
// 			if (stacks->b_size < 1)
// 				stacks->b_bottom = tmp;
// 			(stacks->b_size)++;
// 		}
// 		// add_to_list(instructions, "ra");
// 		if (!instructions)
// 			return ;
// 	}
	
	
	
	// if (send_stack->size > 0)
	// {
	// 	tmp = send_stack->top;
	// 	send_stack->top = send_stack->top->next;
	// 	pile_onto_stack(receive_stack, tmp);
	// 	tmp = receive_stack->top;
	// 	tmp->index = 0;
	// 	while ((tmp = tmp->next))
	// 		tmp->index++;
	// 	tmp = send_stack->top;
	// 	while (tmp)
	// 	{
	// 		tmp->index--;
	// 		tmp = tmp->next;
	// 	}
	// 	send_stack->size--;
	// 	send_stack->middle = send_stack->size / 2;
	// }
	// (target == 'a') ?
	// 	add_to_list(instructions, "pa") : add_to_list(instructions, "pb");
// }
