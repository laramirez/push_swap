/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 12:11:19 by lararamirez       #+#    #+#             */
/*   Updated: 2017/11/03 17:05:47 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t		*compute_cheapest(size_t *costs)
{
	size_t		cost_1;
	size_t		cost_2;

	cost_1 = (costs[1] > costs[3]) ? costs[1] : costs[3];
	cost_2 = (costs[2] > costs[4]) ? costs[2] : costs[4];
	costs[0] = cost_1;
	costs[5] = 1;
	if (cost_2 < costs[0])
	{
		costs[0] = cost_2;
		costs[5] = 2;
	}
	if ((costs[1] + costs[4]) < costs[0])
	{
		costs[0] = costs[1] + costs[4];
		costs[5] = 3;
	}
	if ((costs[2] + costs[3]) < costs[0])
	{
		costs[0] = costs[2] + costs[3];
		costs[5] = 4;
	}
	return (costs);
}

size_t		*get_placement_costs(size_t *costs, t_struct *stacks, size_t index)
{
	t_element	*tmp;

	costs[1] = index;
	costs[2] = stacks->a_size - index;
	if (!stacks->b_size)
	{
		costs[3] = 0;
		costs[4] = 0;
	}
	else
	{
		tmp = stacks->b;
		index = 0;
		printf("trying to place [%d]\n", stacks->a->nbr);
		while (!(stacks->a->nbr > tmp->nbr) && index < stacks->b_size) 
		{
			index++;
			tmp = tmp->next;
		}
		costs[3] = index - 1;
		costs[4] = stacks->b_size - index + 1;
	}
	return (compute_cheapest(costs));
}

void		copy_tab(size_t *tab, size_t *cpy)
{
	cpy[0] = tab[0];
	cpy[1] = tab[1];
	cpy[2] = tab[2];
	cpy[3] = tab[3];
	cpy[4] = tab[4];
	cpy[5] = tab[5];
}

void		push_cheapest_onto_b(t_struct *stacks, t_list **instructions)
{
	t_element	*tmp;
	size_t		index;
	size_t		costs[6];
	size_t		min_costs[6];
	size_t		min_index;

	tmp = stacks->a->next;
	index = 1;
	push_a(stacks, instructions);
	push_a(stacks, instructions);
	push_a(stacks, instructions);
	get_placement_costs(costs, stacks, 0);
	copy_tab(costs, min_costs);
	printf("COSTS TAB [%zu] - [%zu] - [%zu] - [%zu] - [%zu] - [%zu] index [%d]\n", costs[0], costs[1], costs[2], costs[3], costs[4], costs[5], 0);
	min_index = 0;
	while (index < stacks->a_size)
	{
		get_placement_costs(costs, stacks, index);
		printf("COSTS TAB [%zu] - [%zu] - [%zu] - [%zu] - [%zu] - [%zu] index [%zu]\n", costs[0], costs[1], costs[2], costs[3], costs[4], costs[5], index);
		if (min_costs[0] < costs[0])
		{
			copy_tab(costs, min_costs);
			min_index = index;
		}
		tmp = tmp->next;
		index++;
	}
	// move_cheapest()
	if (instructions)
		return ;
}

t_list		**compute_solution(t_struct *stacks, t_list **instructions)
{
	char test;

	test = 1;
	while (!is_sorted(stacks->a, stacks->a_size) && test)
	{
		if (is_sortable_in_place(stacks->a, stacks->a_size))
			sort_a(stacks, stacks->a_size, instructions);
		else
			push_cheapest_onto_b(stacks, instructions);
		test--;
	}
	// if (stacks->b_size)
	//     push_back_onto_a(stacks, instructions);
	return (instructions);
}
