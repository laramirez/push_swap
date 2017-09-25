/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 12:20:18 by lararamirez       #+#    #+#             */
/*   Updated: 2017/09/11 19:53:45 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *stack, t_list **instructions, char target)
{
	int			tmp;

	if (stack->size > 1)
	{
		tmp = stack->top->nbr;
		stack->top->nbr = stack->top->next->nbr;
		stack->top->index = 0;
		stack->top->next->nbr = tmp;
		stack->top->next->index = 1;
	}
	(target == 'a') ?
		add_to_list(instructions, "sa") : add_to_list(instructions, "sb");
}

void	rotate(t_stack *stack, t_list **instructions, char target)
{
	t_element	*move;
	t_element	*tmp;

	if (stack->size > 1)
	{
		move = stack->top;
		stack->top = stack->top->next;
		tmp = stack->top;
		tmp->index = 0;
		while (tmp->next)
		{
			tmp = tmp->next;
			tmp->index--;
		}
		tmp->next = move;
		move->next = NULL;
		move->index = stack->size - 1;
	}
	(target == 'a') ?
		add_to_list(instructions, "ra") : add_to_list(instructions, "rb");
}

void	rev_rotate(t_stack *stack, t_list **instructions, char target)
{
	t_element	*move;
	t_element	*tmp;

	if (stack->size == 2)
		rotate(stack, instructions, target);
	if (stack->size > 1)
	{
		tmp = stack->top;
		while (tmp->next->next)
		{
			tmp->index++;
			tmp = tmp->next;
		}
		tmp->index++;
		move = tmp->next;
		tmp->next = NULL;
		move->next = stack->top;
		stack->top = move;
		move->index = 0;
		(target == 'a') ?
			add_to_list(instructions, "rra") : add_to_list(instructions, "rrb");
	}
}

void	push(t_stack *send_stack, t_stack *receive_stack,
			t_list **instructions, char target)
{
	t_element	*tmp;

	if (send_stack->size > 0)
	{
		tmp = send_stack->top;
		send_stack->top = send_stack->top->next;
		pile_onto_stack(receive_stack, tmp);
		tmp = receive_stack->top;
		tmp->index = 0;
		while ((tmp = tmp->next))
			tmp->index++;
		tmp = send_stack->top;
		while (tmp)
		{
			tmp->index--;
			tmp = tmp->next;
		}
		send_stack->size--;
		send_stack->middle = send_stack->size / 2;
	}
	(target == 'a') ?
		add_to_list(instructions, "pa") : add_to_list(instructions, "pb");
}
