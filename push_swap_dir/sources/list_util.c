/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:03:23 by lararamirez       #+#    #+#             */
/*   Updated: 2017/10/31 17:29:03 by lramirez         ###   ########.fr       */
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
