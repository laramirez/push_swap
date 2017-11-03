/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 12:11:19 by lararamirez       #+#    #+#             */
/*   Updated: 2017/11/03 10:43:17 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list		**compute_solution(t_struct *stacks, t_list **instructions)
{
	char test;

	test = 1;
	while (!is_sorted(stacks->a, stacks->a_size) && test)
	{
		if (is_sortable_in_place(stacks->a, stacks->a_size))
			sort_a(stacks, stacks->a_size, instructions);
		test--;
		// else
		//     push_cheapest_onto_b(stacks, instructions);
	}
	// if (stacks->b_size)
	//     push_back_onto_a(stacks, instructions);
	return (instructions);
}
