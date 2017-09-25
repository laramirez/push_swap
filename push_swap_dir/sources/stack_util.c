/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 11:59:37 by lararamirez       #+#    #+#             */
/*   Updated: 2017/09/11 16:19:30 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_element	*create_element(char *arg, int index)
{
	t_element	*new_element;
	size_t		i;
	long		nbr;

	i = (*arg == '-' && *(arg + 1)) ? 1 : 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) || i > 10)
			ft_kill();
		i++;
	}
	nbr = ft_atoi(arg);
	if (nbr > 2147483647 || nbr < -2147483648)
		ft_kill();
	new_element = (t_element *)ft_memalloc(sizeof(t_element));
	new_element->nbr = (int)nbr;
	new_element->index = (size_t)index;
	new_element->next = NULL;
	return (new_element);
}

void		pile_onto_stack(t_stack *a, t_element *new_element)
{
	new_element->next = a->top;
	a->top = new_element;
	a->size++;
	a->middle = a->size / 2;
}

void		free_stack(t_stack *stack)
{
	t_element	*tmp_stack;
	t_element	*tmp_stack_next;

	tmp_stack = stack->top;
	while (tmp_stack)
	{
		tmp_stack_next = tmp_stack->next;
		tmp_stack->next = NULL;
		free(tmp_stack);
		tmp_stack = tmp_stack_next;
	}
	free(stack);
}

t_stack		*init_stack(void)
{
	t_stack		*new_stack;

	new_stack = (t_stack *)ft_memalloc(sizeof(t_stack));
	new_stack->top = NULL;
	new_stack->size = 0;
	new_stack->middle = 0;
	return (new_stack);
}
