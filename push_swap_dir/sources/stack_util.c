/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 11:59:37 by lararamirez       #+#    #+#             */
/*   Updated: 2017/11/01 15:16:22 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_struct		*build(int arg_nbr, char **args)
{
	t_struct	*stacks;
	int			i;

	stacks = (t_struct *)ft_memalloc(sizeof(t_struct));
	stacks->a = NULL;
	stacks->b = NULL;
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
	t_element	*tmp;
	size_t		size;

	printf("stacks->a_size (%zu)\n", stacks->a_size);
	if (!stacks->a_size)
		stacks->a = new_elem;
	else
	{
		tmp = stacks->a;
		size = stacks->a_size;
		while (size)
		{
			if (new_elem->nbr == tmp->nbr)
				ft_kill();
			tmp = tmp->next;
			size--;
		}
		tmp = stacks->a->previous;
		stacks->a->previous = new_elem;
		new_elem->next = stacks->a;
		new_elem->previous = (tmp) ? tmp : stacks->a;
	}
	(stacks->a_size)++;
}

void			free_stacks(t_struct *stacks)
{
	t_element	*tmp_stack;
	t_element	*tmp_stack_next;

	tmp_stack = stacks->a;
	while (stacks->a_size)
	{
		tmp_stack_next = tmp_stack->next;
		tmp_stack->next = NULL;
		free(tmp_stack);
		tmp_stack = tmp_stack_next;
		(stacks->a_size)--;
	}
	free(stacks);
}