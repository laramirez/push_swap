/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:10:54 by lararamirez       #+#    #+#             */
/*   Updated: 2017/10/31 18:20:21 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

// static void		compute(t_struct *stacks, char option)
// {
// 	t_list		**instructions;

// 	if (option)
// 	{
// 		instructions = (t_list **)ft_memalloc(sizeof(t_list *));
// 		*instructions = NULL;
// 	}
	
		
// 	// display_instructions(compute_solution(stacks, instructions), option);
// 	free_stacks(stacks);
// }

static void		usage(void)
{
	write(1, "usage : ./push_swap [-t] [\"int int ...\"] or ./push_swap [-t] [int] [int] [...]\n", 79);
	exit (EXIT_SUCCESS);
}

int				main(int argc, char **argv)
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
		stacks = build(argc - option - 1, argv + 1 + option);
	tmp = stacks->a_top;
	printf("stack size -- [%zu]\n", stacks->a_size);
	while (tmp)
	{
		printf("[%d]\n", tmp->nbr);
		tmp = tmp->next;
	}
	if (is_sorted(stacks->a_top, stacks->a_size))
		printf("Pile is sorted\n");
	else
		printf("Pile is NOT sorted\n");
	if (is_rev_sorted(stacks->a_bottom, stacks->a_size))
		printf("Pile is rev_sorted\n");
	else
		printf("Pile is NOT rev_sorted\n");
	// compute(stacks, option);
	return (0);
}
