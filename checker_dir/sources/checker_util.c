/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 11:23:49 by lararamirez       #+#    #+#             */
/*   Updated: 2017/09/11 16:51:25 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void		apply_double(t_stack *a, t_stack *b, char *command, char option)
{
	if (ft_strequ(command, "ss"))
	{
		swap(a);
		swap(b);
	}
	else if (ft_strequ(command, "rr"))
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strequ(command, "rrr"))
	{
		rev_rotate(a);
		rev_rotate(b);
	}
	if (option)
		display_stacks(a, b);
}

void		apply_instructions(t_stack *a, t_stack *b,
				t_list **instructions, char option)
{
	t_list		*tmp;

	tmp = *instructions;
	while (tmp->next)
	{
		if (ft_strequ(tmp->command, "sa"))
			swap(a);
		else if (ft_strequ(tmp->command, "sb"))
			swap(b);
		else if (ft_strequ(tmp->command, "pa"))
			push(b, a);
		else if (ft_strequ(tmp->command, "pb"))
			push(a, b);
		else if (ft_strequ(tmp->command, "ra"))
			rotate(a);
		else if (ft_strequ(tmp->command, "rb"))
			rotate(b);
		else if (ft_strequ(tmp->command, "rra"))
			rev_rotate(a);
		else if (ft_strequ(tmp->command, "rrb"))
			rev_rotate(b);
		apply_double(a, b, tmp->command, option);
		tmp = tmp->next;
	}
}

int			is_sorted(t_stack *stack)
{
	t_element	*tmp;

	if (stack->size < 2)
		return (1);
	tmp = stack->top;
	while (tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_stack		*init_stack(void)
{
	t_stack *new_stack;

	new_stack = (t_stack *)ft_memalloc(sizeof(t_stack));
	new_stack->top = NULL;
	new_stack->size = 0;
	return (new_stack);
}

void		duplicates_check(t_stack *stack)
{
	size_t		i;
	int			tab[stack->size];
	t_element	*tmp;

	i = 0;
	tmp = stack->top;
	while (tmp)
	{
		tab[i] = tmp->nbr;
		i++;
		tmp = tmp->next;
	}
	ft_tab_quicksort(tab, 0, i - 1);
	i = 0;
	while ((i + 1) < stack->size)
	{
		if (tab[i] == tab[i + 1])
			ft_kill();
		i++;
	}
}
