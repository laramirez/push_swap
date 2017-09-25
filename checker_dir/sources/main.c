/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 14:38:05 by lramirez          #+#    #+#             */
/*   Updated: 2017/09/11 17:58:00 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	is_number_list(char *argv)
{
	size_t		i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] != ' ' && !ft_isdigit(argv[i]) && argv[i] != '-')
			ft_kill();
		i++;
	}
	return (1);
}

static void	compute(t_stack *a, t_stack *b, char option)
{
	t_list		**instructions;

	instructions = get_instructions(new_list(), a);
	apply_instructions(a, b, instructions, option);
	(is_sorted(a) && b->size == 0) ? ft_printf("OK\n") : ft_printf("KO\n");
	free_instructions(instructions);
	free_stack(a);
	free_stack(b);
}

static char	get_option(int *argc, char ***argv)
{
	if (ft_strequ("-v", (*argv)[1]))
	{
		(*argv) += 2;
		(*argc)--;
		return (1);
	}
	else
		(*argv)++;
	return (0);
}

int			main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	char		option;

	if (argc <= 1)
		return (0);
	a = init_stack();
	b = init_stack();
	option = get_option(&argc, &argv);
	if (argc == 2 && is_number_list(argv[0]))
	{
		argc = ft_countwords(argv[0], ' ') - 1;
		argv = ft_strsplit(argv[0], ' ');
	}
	else
		argc -= 2;
	while (argc >= 0)
	{
		pile_onto_stack(a, create_element(argv[argc], argc));
		argc--;
	}
	duplicates_check(a);
	compute(a, b, option);
	return (0);
}
