/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 12:11:19 by lararamirez       #+#    #+#             */
/*   Updated: 2017/11/06 09:51:38 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Key for the costs tab:
** [INDEX_IN_A] [BEST_TOTAL_COST] [A_UP] [A_DOWN] [B_UP] [B_DOWN] [KEY]
** The KEY indicates which route led to the best total cost :
** KEY 1 = A_UP + B_UP
** KEY 2 = A_DOWN + A_DOWN
** KEY 3 = A_UP + B_DOWN
** KEY 4 = A_DOWN + B_UP
*/

void		push_back_onto_a(t_struct *stacks, t_list **instructions)
{
	while (stacks->b_size)
		push_b(stacks, instructions);
}

void		copy_tab(size_t *tab, size_t *cpy)
{
	cpy[0] = tab[0];
	cpy[1] = tab[1];
	cpy[2] = tab[2];
	cpy[3] = tab[3];
	cpy[4] = tab[4];
	cpy[5] = tab[5];
	cpy[6] = tab[6];
}

void		push_cheapest_onto_b(t_struct *stacks, t_list **instructions)
{
	t_element	*tmp;
	size_t		index;
	size_t		costs[7];
	size_t		min_costs[7];

	get_placement_costs(costs, stacks, stacks->a, 0);
	copy_tab(costs, min_costs);
	tmp = stacks->a->next;
	index = 1;
	while (index < stacks->a_size)
	{
		get_placement_costs(costs, stacks, tmp, index);
		if (min_costs[1] > costs[1])
			copy_tab(costs, min_costs);
		tmp = tmp->next;
		index++;
	}
	move_cheapest(stacks, min_costs, instructions);
}

t_list		**compute_solution(t_struct *stacks, t_list **instructions)
{
	if (is_sortable_in_place(stacks->a, stacks->a_size))
		sort_a(stacks, stacks->a_size, instructions);
	else
	{
		while (stacks->a_size)
			push_cheapest_onto_b(stacks, instructions);
		push_back_onto_a(stacks, instructions);
	}
	return (instructions);
}
