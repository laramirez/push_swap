/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 12:20:18 by lararamirez       #+#    #+#             */
/*   Updated: 2017/11/05 18:18:42 by lararamirez      ###   ########.fr       */
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
		add_to_list(instructions, "sa");
	}
	else if (target == 'b')
	{
		if (stacks->b_size <= 1)
			return ;
		tmp = stacks->b->nbr;
		stacks->b->nbr = stacks->b->next->nbr;
		stacks->b->next->nbr = tmp;
		add_to_list(instructions, "sb");
	}
	if (instructions)
		return ;
}

void	rotate(t_struct *stacks, t_list **instructions, char target)
{
	if (target == 'a')
	{
		if (stacks->a_size <= 1)
			return ;
		stacks->a = stacks->a->next;
		add_to_list(instructions, "ra");
	}
	else if (target == 'b')
	{
		if (stacks->b_size <= 1)
			return ;
		stacks->b = stacks->b->next;
		add_to_list(instructions, "rb");
	}
	if (instructions)
		return ;
}
	
void	rev_rotate(t_struct *stacks, t_list **instructions, char target)
{

	if (target == 'a')
	{
		if (stacks->a_size <= 1)
			return ;
		stacks->a = stacks->a->previous;
		add_to_list(instructions, "rra");
	}
	else if (target == 'b')
	{
		if (stacks->b_size <= 1)
			return ;
		stacks->b = stacks->b->previous;
		add_to_list(instructions, "rrb");
	}
	if (instructions)
		return ;
}

void	push_a(t_struct *stacks, t_list **instructions)
{
	t_element	*tmp;

	if (stacks->a_size == 0)
		return ;
	else
	{
		stacks->a->previous->next = stacks->a->next;
		stacks->a->next->previous = stacks->a->previous;
		tmp = stacks->a;
		stacks->a = stacks->a->next;
		(stacks->a_size)--;
		tmp->previous = (stacks->b_size) ? stacks->b->previous : tmp;
		tmp->next = (stacks->b_size) ? stacks->b : tmp;
		if (stacks->b_size)
		{
			stacks->b->previous->next = tmp;
			stacks->b->previous = tmp;
		}
		stacks->b = tmp;
		(stacks->b_size)++;
		add_to_list(instructions, "pa");
	}
}

void	push_b(t_struct *stacks, t_list **instructions)
{
	t_element	*tmp;
	
		if (stacks->b_size == 0)
			return ;
		else
		{
			stacks->b->previous->next = stacks->b->next;
			stacks->b->next->previous = stacks->b->previous;
			tmp = stacks->b;
			stacks->b = stacks->b->next;
			(stacks->b_size)--;
			tmp->previous = (stacks->a_size) ? stacks->a->previous : tmp;
			tmp->next = (stacks->a_size) ? stacks->a : tmp;
			if (stacks->a_size)
			{
				stacks->a->previous->next = tmp;
				stacks->a->previous = tmp;
			}
			stacks->a = tmp;
			(stacks->a_size)++;
			add_to_list(instructions, "pa");
		}
}
