/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:10:54 by lararamirez       #+#    #+#             */
/*   Updated: 2017/11/05 15:17:00 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

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

static void		usage(void)
{
	write(1, "usage : ./push_swap [-t] [\"int int ...\"] or \
		./push_swap [-t] [int] [int] [...]\n", 79);
	exit (EXIT_SUCCESS);
}

void			print_stacks(t_struct *stacks)
{
	t_element	*a_tmp;
	t_element	*b_tmp;
	size_t		a_size;
	size_t		b_size;

	a_tmp = stacks->a;
	b_tmp = stacks->b;
	a_size = stacks->a_size;
	b_size = stacks->b_size;
	ft_printf("\n	* -- PILE A -- *	* -- PILE B -- *\n");
	while (a_size || b_size)
	{
		if (a_size && b_size)
			ft_printf("	| %12d |	| %12d |\n", a_tmp->nbr, b_tmp->nbr);
		else if (a_size && !b_size)
			ft_printf("	| %12d |	| %12c |\n", a_tmp->nbr, ' ');
		else if (!a_size && b_size)
			ft_printf("	| %12c |	| %12d |\n", ' ', b_tmp->nbr);
		if (a_size)
		{
			a_tmp = a_tmp->next;
			a_size--;
		}
		if (b_size)
		{
			b_tmp = b_tmp->next;
			b_size--;
		}
	}
	ft_printf("	* -- PILE A -- *	* -- PILE B -- *\n");
}

int				main(int argc, char **argv)
{
	t_struct	*stacks;
	char		option;
	t_list		*instructions;

	instructions = NULL;
	if (argc <= 1)
		usage();
	option = ft_strequ("-t", argv[1]) ? 1 : 0;
	if (option && argc == 2)
		usage();
	if (argc - option == 2 && ft_strchr(argv[1 + option], ' '))
		stacks = build(ft_countwords(argv[1 + option], ' '),
			ft_strsplit(argv[1 + option], ' '));
	else
		stacks = build(argc - option - 1, argv + 1 + option);
	compute_solution(stacks, &instructions);
	// display_instructions;
	return (0);
}
