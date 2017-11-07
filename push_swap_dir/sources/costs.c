/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 15:20:53 by lararamirez       #+#    #+#             */
/*   Updated: 2017/11/07 14:54:18 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t		*compute_cheapest_2(size_t cost_2, size_t cost_3,
	size_t cost_4, size_t *costs)
{
	if (cost_2 < costs[1])
	{
		costs[1] = cost_2;
		costs[6] = 2;
	}
	if (cost_3 < costs[1])
	{
		costs[1] = cost_3;
		costs[6] = 3;
	}
	if (cost_4 < costs[1])
	{
		costs[1] = cost_4;
		costs[6] = 4;
	}
	return (costs);
}

size_t		*compute_cheapest(size_t *costs)
{
	size_t		cost_1;
	size_t		cost_2;
	size_t		cost_3;
	size_t		cost_4;

	cost_1 = (costs[2] >= costs[4]) ? costs[2] : costs[4];
	cost_1 += ((costs[4] <= costs[5] + 1) ? costs[4] : costs[5] + 1) + 1;
	cost_2 = (costs[3] >= costs[5]) ? costs[3] : costs[5];
	cost_2 += ((costs[4] <= costs[5] + 1) ? costs[4] : costs[5] + 1) + 1;
	cost_3 = costs[2] + costs[5];
	cost_3 += ((costs[4] <= costs[5] + 1) ? costs[4] : costs[5] + 1) + 1;
	cost_4 = costs[3] + costs[4];
	cost_4 += ((costs[4] < costs[5] + 1) ? costs[4] : costs[5] + 1) + 1;
	costs[1] = cost_1;
	costs[6] = 1;
	return (compute_cheapest_2(cost_2, cost_3, cost_4, costs));
}

size_t		*get_placement_costs(size_t *costs, t_struct *stacks,
				t_element *a, size_t index)
{
	t_element	*tmp;

	costs[0] = index;
	costs[2] = index;
	costs[3] = (stacks->a_size > 1) ? stacks->a_size - index : 0;
	if (!stacks->b_size)
	{
		costs[4] = 0;
		costs[5] = 0;
	}
	else
	{
		tmp = stacks->b;
		index = 0;
		while (!(a->nbr > tmp->nbr) && index < stacks->b_size)
		{
			index++;
			tmp = tmp->next;
		}
		costs[4] = (index == stacks->b_size) ? 0 : index;
		costs[5] = (index == stacks->b_size) ? 0 : stacks->b_size - index;
	}
	return (compute_cheapest(costs));
}

void		move_cheapest(t_struct *stacks, size_t *costs,
	t_list **instructions)
{
	size_t		a_moves;
	size_t		b_moves;

	a_moves = (costs[6] == 1 || costs[6] == 3) ? costs[2] : costs[3];
	b_moves = (costs[6] == 1 || costs[6] == 4) ? costs[4] : costs[5];
	while (a_moves || b_moves)
	{
		if (a_moves)
		{
			(costs[6] == 1 || costs[6] == 3) ?
				rotate(stacks, instructions, 'a') :
					rev_rotate(stacks, instructions, 'a');
			a_moves--;
		}
		if (b_moves)
		{
			(costs[6] == 1 || costs[6] == 4) ?
				rotate(stacks, instructions, 'b') :
					rev_rotate(stacks, instructions, 'b');
			b_moves--;
		}
	}
	push_a(stacks, instructions);
	while (stacks->b->nbr < stacks->b->previous->nbr)
		rotate(stacks, instructions, 'b');
}
