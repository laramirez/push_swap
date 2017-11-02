/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:10:54 by lararamirez       #+#    #+#             */
/*   Updated: 2017/11/02 17:31:59 by lararamirez      ###   ########.fr       */
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

// static void		compute(t_struct *stacks, char option)
// {
// 	t_list		**instructions;

// 	if (option)
// 	{
// 		instructions = (t_list **)ft_memalloc(sizeof(t_list *));
// 		*instructions = NULL;
// 	}
// 	display_instructions(compute_solution(stacks, instructions), option);
// 	free_stacks(stacks);
// }

static void		usage(void)
{
	write(1, "usage : ./push_swap [-t] [\"int int ...\"] or ./push_swap [-t] [int] [int] [...]\n", 79);
	exit (EXIT_SUCCESS);
}

void			test(t_struct *stacks)
{
	t_element	*tmp;
	size_t		size;
	t_list		**instructions;

	instructions = NULL;
	tmp = stacks->a;
	size = stacks->a_size;
	printf("stack size -- [%zu]\n", stacks->a_size);
	while (size)
	{
		printf("[%d]\n", tmp->nbr);
		tmp = tmp->next;
		size--;
	}
	if (is_sorted(stacks->a, stacks->a_size))
		printf("Pile is sorted\n");
	else
		printf("Pile is NOT sorted\n");
	if (is_rev_sorted(stacks->a, stacks->a_size))
		printf("Pile is rev_sorted\n");
	else
		printf("Pile is NOT rev_sorted\n");
	compute_solution(stacks, instructions);
	tmp = stacks->a;
	size = stacks->a_size;
	printf("a stack size -- [%zu]\n", stacks->a_size);
	while (size)
	{
		printf("[%d]\n", tmp->nbr);
		tmp = tmp->next;
		size--;
	}
	tmp = stacks->b;
	size = stacks->b_size;
	printf("b stack size -- [%zu]\n", stacks->b_size);
	while (size)
	{
		printf("[%d]\n", tmp->nbr);
		tmp = tmp->previous;
		size--;
	}
}

int				main(int argc, char **argv)
{
	t_struct	*stacks;
	char		option;

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
	// compute(stacks, option);
	test(stacks);
	return (0);
}
