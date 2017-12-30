/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 11:59:37 by lararamirez       #+#    #+#             */
/*   Updated: 2017/12/30 13:43:34 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_struct		*build(int arg_nbr, char **args)
{
	t_struct	*stacks;
	int			i;
	char		last;

	stacks = (t_struct *)ft_memalloc(sizeof(t_struct));
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->a_size = 0;
	stacks->b_size = 0;
	last = 0;
	i = 0;
	while (i < arg_nbr)
	{
		if (i == arg_nbr - 1)
			last = 1;
		add_to_a(stacks, create_elem(args[i]), last);
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

void			add_to_a(t_struct *stacks, t_element *new_elem, char last)
{
	t_element	*tmp;

	if (!stacks->a_size)
		stacks->a = new_elem;
	else
	{
		tmp = stacks->a;
		while (tmp->next)
		{
			if (new_elem->nbr == tmp->nbr)
				ft_kill();
			tmp = tmp->next;
		}
		if (new_elem->nbr == tmp->nbr)
			ft_kill();
		tmp->next = new_elem;
		new_elem->previous = tmp;
	}
	if (last)
	{
		stacks->a->previous = new_elem;
		new_elem->next = stacks->a;
	}
	(stacks->a_size)++;
}

void			free_stacks(t_struct *stacks)
{
	t_element	*tmp;

	while (stacks->a_size)
	{
		tmp = stacks->a;
		ft_printf("freeing %d\n", tmp->nbr);
		stacks->a = stacks->a->next;
		free(tmp);
		(stacks->a_size)--;
	}
	free(stacks);
}
