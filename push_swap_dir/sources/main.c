/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:10:54 by lararamirez       #+#    #+#             */
/*   Updated: 2017/10/31 12:34:27 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

// static void	compute(t_stack *a, t_stack *b, char option)
// {
// 	t_list		**instructions;

// 	instructions = (t_list **)ft_memalloc(sizeof(t_list *));
// 	*instructions = NULL;
// 	display_instructions(compute_solution(a, b, instructions), option);
// 	free_stack(a);
// 	free_stack(b);
// }

void			add_to_a(t_struct *stacks, t_element *new_elem)
{
	if (stacks->a_bottom)
	{
		new_elem->previous = stacks->a_bottom;
		stacks->a_bottom->next = new_elem;
	}
	stacks->a_bottom = new_elem;
	if (!stacks->a_top)
		stacks->a_top = new_elem;
}

t_element		*create_elem(char *arg)
{
	t_element	*new_elem;
	long		nbr;
	char		*tmp;

	tmp = arg;
	while(ft_isspace(*tmp))
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

void		usage(void)
{
	write(1, "usage : ./push_swap [-t] [\"int int ...\"] OR ./push_swap [-t] [int] [int] [...]\n", 79);
	exit (EXIT_SUCCESS);
}

int			main(int argc, char **argv)
{
	t_struct	*stacks;
	char		option;
	t_element	*tmp;

	if (argc <= 1)
		usage();
	option = ft_strequ("-t", argv[1]) ? 1 : 0;
	if (option && argc == 2)
		usage();
	if (argc - option == 2 && ft_strchr(argv[1 + option], ' '))
		stacks = build(ft_countwords(argv[1 + option], ' '),
			ft_strsplit(argv[1 + option], ' '));
	else
		stacks = build(argc - option - 1, argv + 1);
	tmp = stacks->a_top;
	while (tmp)
	{
		printf("[%d]\n", tmp->nbr);
		tmp = tmp->next;
	}
	// compute(stacks, option);
	return (0);
}
