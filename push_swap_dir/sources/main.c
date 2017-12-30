/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:10:54 by lararamirez       #+#    #+#             */
/*   Updated: 2017/12/30 16:35:34 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			display_instructions(t_list **instructions, char option)
{
	t_list		*tmp;
	t_list		*tmp_next;
	size_t		count;

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
}

void			usage(void)
{
	ft_printf("usage : ./push_swap [-t] [\"int int ...\"] or ");
	ft_printf("./push_swap [-t] [int] [int] [...]\n");
	exit(EXIT_SUCCESS);
}

void			add_to_list(t_list **instructions, char *command)
{
	t_list		*tmp;

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
	if (stacks->a_size > 12)
		compute_solution(stacks, &instructions);
	else
		small_compute(stacks, &instructions);
	display_instructions(optimize(&instructions), option);
	free_stacks(stacks);
	return (0);
}
