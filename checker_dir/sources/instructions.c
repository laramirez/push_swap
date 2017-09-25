/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 10:07:53 by lararamirez       #+#    #+#             */
/*   Updated: 2017/09/11 16:48:55 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	swap(t_stack *stack)
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
}

void	rotate(t_stack *stack)
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
}

void	rev_rotate(t_stack *stack)
{
	t_element	*move;
	t_element	*tmp;

	if (stack->size == 2)
		rotate(stack);
	else if (stack->size > 2)
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
	}
}

void	push(t_stack *send_stack, t_stack *receive_stack)
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
	}
}
