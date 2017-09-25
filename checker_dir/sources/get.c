/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 10:23:13 by lararamirez       #+#    #+#             */
/*   Updated: 2017/09/11 17:58:00 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void		check_instruction(char *instruction)
{
	if (ft_strequ("sa", instruction) || ft_strequ("sb", instruction) ||
		ft_strequ("ss", instruction) || ft_strequ("pa", instruction) ||
		ft_strequ("pb", instruction) || ft_strequ("ra", instruction) ||
		ft_strequ("rb", instruction) || ft_strequ("rr", instruction) ||
		ft_strequ("rra", instruction) || ft_strequ("rrb", instruction) ||
		ft_strequ("rrr", instruction))
		return ;
	ft_kill();
}

t_list		*create_instruction(void)
{
	t_list	*new_instruction;

	new_instruction = (t_list *)ft_memalloc(sizeof(t_list));
	new_instruction->command = NULL;
	new_instruction->next = NULL;
	return (new_instruction);
}

t_list		**get_instructions(t_list **instructions, t_stack *a)
{
	t_list			*tmp;
	int				ret;

	tmp = *instructions;
	ret = get_next_line(0, &tmp->command);
	if (ret == 0)
	{
		if (is_sorted(a))
			ft_printf("OK\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		check_instruction(tmp->command);
		tmp->next = create_instruction();
		tmp = tmp->next;
		while (get_next_line(0, &tmp->command))
		{
			check_instruction(tmp->command);
			tmp->next = create_instruction();
			tmp = tmp->next;
		}
	}
	return (instructions);
}

t_list		**new_list(void)
{
	t_list **new_list;

	new_list = (t_list **)ft_memalloc(sizeof(t_list *));
	*new_list = (t_list *)ft_memalloc(sizeof(t_list));
	(*new_list)->command = NULL;
	(*new_list)->next = NULL;
	return (new_list);
}
