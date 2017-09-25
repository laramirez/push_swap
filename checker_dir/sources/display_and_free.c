/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_and_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 10:10:53 by lararamirez       #+#    #+#             */
/*   Updated: 2017/09/11 17:57:23 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void		free_instructions(t_list **instructions)
{
	t_list		*tmp_list;
	t_list		*tmp_list_next;

	if (instructions)
	{
		tmp_list = *instructions;
		while (tmp_list)
		{
			tmp_list_next = tmp_list->next;
			free(tmp_list->command);
			tmp_list->next = NULL;
			free(tmp_list);
			tmp_list = tmp_list_next;
		}
		*instructions = NULL;
		free(instructions);
	}
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

void		display_stacks(t_stack *a, t_stack *b)
{
	t_element	*a_tmp;
	t_element	*b_tmp;

	a_tmp = a->top;
	b_tmp = b->top;
	ft_printf("\n	* -- PILE A -- *	* -- PILE B -- *\n");
	while (a_tmp || b_tmp)
	{
		if (a_tmp && b_tmp)
			ft_printf("	| %12d |	| %12d |\n", a_tmp->nbr, b_tmp->nbr);
		else if (a_tmp && !b_tmp)
			ft_printf("	| %12d |	| %12c |\n", a_tmp->nbr, ' ');
		else if (!a_tmp && b_tmp)
			ft_printf("	| %12c |	| %12d |\n", ' ', b_tmp->nbr);
		if (a_tmp)
			a_tmp = a_tmp->next;
		if (b_tmp)
			b_tmp = b_tmp->next;
	}
	ft_printf("	* -- PILE A -- *	* -- PILE B -- *\n");
}

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
}
