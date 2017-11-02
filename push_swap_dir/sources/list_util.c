/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:03:23 by lararamirez       #+#    #+#             */
/*   Updated: 2017/11/02 12:56:09 by lararamirez      ###   ########.fr       */
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
