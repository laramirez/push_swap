/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 11:59:37 by lararamirez       #+#    #+#             */
/*   Updated: 2017/10/31 18:12:44 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_struct		*build(int arg_nbr, char **args)
{
	t_struct	*stacks;
	int			i;

	stacks = (t_struct *)ft_memalloc(sizeof(t_struct));
	stacks->a_top = NULL;
	stacks->a_bottom = NULL;
	stacks->b_top = NULL;
	stacks->b_bottom = NULL;
	stacks->a_size = 0;
	stacks->b_size = 0;
	i = 0;
	while (i < arg_nbr)
	{
		add_to_a(stacks, create_elem(args[i]));
		i++;
	}
	return (stacks);
}

t_element		*create_elem(char *arg)
{
	t_element	*new_elem;
	long		nbr;
	char		*tmp;

	tmp = arg;
	while (ft_isspace(*tmp))
		tmp++;
	if (*tmp == '-' || *tmp == '+')
		tmp++;
	if (!ft_isdigit(*tmp))
		ft_kill();
	while (ft_isdigit(*tmp))
		tmp++;
	if (*tmp)
		ft_kill();
	nbr = ft_atoi(arg);
	if (nbr > 2147483647 || nbr < -2147483648)
		ft_kill();
	new_elem = (t_element *)ft_memalloc(sizeof(t_element));
	new_elem->nbr = (int)nbr;
	new_elem->next = NULL;
	new_elem->previous = NULL;
	return (new_elem);
}

void			add_to_a(t_struct *stacks, t_element *new_elem)
{
	if (stacks->a_bottom)
	{
		new_elem->previous = stacks->a_bottom;
		stacks->a_bottom->next = new_elem;
	}
	stacks->a_bottom = new_elem;
	(stacks->a_size)++;
	if (!stacks->a_top)
		stacks->a_top = new_elem;
}

void			free_stacks(t_struct *stacks)
{
	t_element	*tmp_stack;
	t_element	*tmp_stack_next;

	tmp_stack = stacks->a_top;
	while (tmp_stack)
	{
		tmp_stack_next = tmp_stack->next;
		tmp_stack->next = NULL;
		free(tmp_stack);
		tmp_stack = tmp_stack_next;
	}
	free(stacks);
}