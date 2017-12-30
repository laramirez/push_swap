/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 15:50:58 by lararamirez       #+#    #+#             */
/*   Updated: 2017/12/16 18:48:11 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			is_sorted(t_element *stack, size_t stack_size)
{
	t_element	*tmp;

	if (stack_size < 2)
		return (1);
	tmp = stack;
	while (stack_size - 1)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (0);
		tmp = tmp->next;
		stack_size--;
	}
	return (1);
}

int			is_rev_sorted(t_element *stack, size_t stack_size)
{
	t_element	*tmp;

	if (stack_size < 2)
		return (1);
	tmp = stack;
	while (stack_size - 1)
	{
		if (tmp->nbr < tmp->next->nbr)
			return (0);
		tmp = tmp->next;
		stack_size--;
	}
	return (1);
}

void		concatenate(t_list *current, t_list *next, char *command)
{
	t_list	*new;
	t_list	*delete;

	delete = current->next;
	new = (t_list *)ft_memalloc(sizeof(t_list));
	new->command = ft_strdup(command);
	current->next = new;
	new->next = next;
	free(delete->next->command);
	free(delete->next);
	free(delete->command);
	free(delete);
}

t_list		**optimize(t_list **instructions)
{
	t_list	*tmp;

	tmp = *instructions;
	while (tmp && tmp->next && tmp->next->next)
	{
		if ((ft_strequ(tmp->next->command, "sa") &&
			ft_strequ(tmp->next->next->command, "sb")) ||
				(ft_strequ(tmp->next->command, "sb") &&
					ft_strequ(tmp->next->next->command, "sa")))
			concatenate(tmp, tmp->next->next->next, "ss");
		else if ((ft_strequ(tmp->next->command, "ra") &&
		ft_strequ(tmp->next->next->command, "rb")) ||
			(ft_strequ(tmp->next->command, "rb") &&
				ft_strequ(tmp->next->next->command, "ra")))
			concatenate(tmp, tmp->next->next->next, "rr");
		else if ((ft_strequ(tmp->next->command, "rra") &&
			ft_strequ(tmp->next->next->command, "rrb")) ||
				(ft_strequ(tmp->next->command, "rrb") &&
					ft_strequ(tmp->next->next->command, "rra")))
			concatenate(tmp, tmp->next->next->next, "rrr");
		tmp = tmp->next;
	}
	return (instructions);
}
