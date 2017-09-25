/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:10:54 by lararamirez       #+#    #+#             */
/*   Updated: 2017/09/11 20:04:50 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** This program follows 3 key steps:
**
** 1- Get arguments, and if they are valid, turn them into a stack (a).
** Initialize a second, empty, stack (b) to be used for sorting.
**
** 2- Determine the most optimized set of instructions that will sort stack a
** using only stack b (no temporary variables, no other structure).
** Store the result in a list.
**
** 3- Display the list on STDOUT.
*/

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

	instructions = (t_list **)ft_memalloc(sizeof(t_list*));
	*instructions = NULL;
	display_instructions(compute_solution(a, b, instructions), option);
	free_stack(a);
	free_stack(b);
}

static char	get_option(int *argc, char ***argv)
{
	if (ft_strequ("-t", (*argv)[1]))
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
