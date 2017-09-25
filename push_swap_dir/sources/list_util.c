/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:03:23 by lararamirez       #+#    #+#             */
/*   Updated: 2017/09/11 20:06:59 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		add_to_list(t_list **instructions, char *command)
{
	t_list	*tmp;

	tmp = *instructions;
	if (!tmp)
	{
		tmp = (t_list *)ft_memalloc(sizeof(t_list));
		tmp->command = ft_strdup(command);
		tmp->next = NULL;
		*instructions = tmp;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (t_list *)ft_memalloc(sizeof(t_list));
	tmp->next->command = ft_strdup(command);
	tmp->next->next = NULL;
}

void		display_instructions(t_list **instructions, char option)
{
	t_list	*tmp;
	t_list	*tmp_next;
	size_t	count;

	count = 0;
	tmp = *instructions;
	while (tmp)
	{
		if (option)
			count++;
		ft_printf("%s\n", tmp->command);
		tmp = tmp->next;
	}
	if (option)
		ft_printf("total operations: [%zu]\n", count);
	tmp = *instructions;
	while (tmp)
	{
		tmp_next = tmp->next;
		free(tmp->command);
		tmp->next = NULL;
		free(tmp);
		tmp = tmp_next;
	}
	free(instructions);
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
