/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 15:20:53 by lararamirez       #+#    #+#             */
/*   Updated: 2017/12/16 18:21:56 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		compute_cheapest_2(size_t cost_2, size_t cost_3,
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
}

void		compute_cheapest(size_t *costs)
{
	size_t		cost_1;
	size_t		cost_2;
	size_t		cost_3;
	size_t		cost_4;

	cost_1 = (costs[2] >= costs[4]) ? costs[2] : costs[4];
	cost_2 = (costs[3] >= costs[5]) ? costs[3] : costs[5];
	cost_3 = costs[2] + costs[5];
	cost_4 = costs[3] + costs[4];
	costs[1] = cost_1;
	costs[6] = 1;
	compute_cheapest_2(cost_2, cost_3, cost_4, costs);
}

void		get_b_placement_costs(size_t *costs, t_struct *stacks, t_element *a)
{
	t_element	*current;
	int			min;
	int			max;
	size_t		index;
	size_t		min_index;
	size_t		max_index;

	// ft_printf("number to place [%zu]\n", a->nbr);
	if (stacks->b_size == 1)
		costs[4] = 0;
	else
	{
		current = stacks->b;
		index = 0;
		while (current->nbr > current->next->nbr)
		{
			index++;
			current = current->next;
		}
		min_index = index;
		max_index = (index == stacks->b_size - 1) ? 0 : index + 1;
		min = current->nbr;
		max = current->next->nbr;
		// ft_printf("min_index is %zu - max_index is %zu - number to place is %zu\n", min_index, max_index, a->nbr);
		if (a->nbr < min)
		{
			costs[4] = (min_index == stacks->b_size - 1) ? 0 : min_index + 1;
			costs[5] = stacks->b_size - min_index - 1;
		}
		else if (a->nbr > max)
		{
			costs[4] = (max_index == 0) ? 0 : max_index;
			costs[5] = stacks->b_size - max_index;
		}
		else
		{
			current = stacks->b;
			index = 0;
			while (!(a->nbr > current->nbr && a->nbr < current->previous->nbr))
			{
				index++;
				current = current->next;
			}
			costs[4] = index;
			costs[5] = stacks->b_size - index;
		}
	}
	// ft_printf("cost B up [%zu] - cost B down [%zu]\n", costs[4], costs[5]);
	// ft_printf("-\n", costs[4], costs[5]);
	// current = stacks->b;
	// index = stacks->b_size;
	// while (index)
	// {
	// 	ft_printf("- %d -\n", current->nbr);
	// 	current = current->next;
	// 	index--;
	// }
	// ft_printf("-\n", costs[4], costs[5]);
	// ft_printf("-\n", costs[4], costs[5]);
}

void		get_placement_costs(size_t *costs, t_struct *stacks, t_element *a, size_t index)
{
	costs[0] = index;
	costs[2] = index;
	costs[3] = (stacks->a_size > 1) ? stacks->a_size - index : 0;
	if (!stacks->b_size)
	{
		costs[4] = 0;
		costs[5] = 0;
	}
	else
		get_b_placement_costs(costs, stacks, a);
	compute_cheapest(costs);
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
}
