/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 15:20:53 by lararamirez       #+#    #+#             */
/*   Updated: 2017/12/30 16:00:23 by lramirez         ###   ########.fr       */
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

void		get_b_placement_costs_2(t_index *i, size_t *costs,
				t_struct *stacks, t_element *a)
{
	t_element	*current;

	if (a->nbr < i->min)
	{
		costs[4] = (i->min_index == stacks->b_size - 1) ? 0 : i->min_index + 1;
		costs[5] = stacks->b_size - i->min_index - 1;
	}
	else if (a->nbr > i->max)
	{
		costs[4] = (i->max_index == 0) ? 0 : i->max_index;
		costs[5] = stacks->b_size - i->max_index;
	}
	else
	{
		current = stacks->b;
		i->index = 0;
		while (!(a->nbr > current->nbr && a->nbr < current->previous->nbr))
		{
			(i->index)++;
			current = current->next;
		}
		costs[4] = i->index;
		costs[5] = stacks->b_size - i->index;
	}
}

void		get_b_placement_costs(size_t *costs, t_struct *stacks, t_element *a)
{
	t_element	*current;
	t_index		*i;

	i = (t_index *)ft_memalloc(sizeof(t_index));
	if (stacks->b_size == 1)
		costs[4] = 0;
	else
	{
		current = stacks->b;
		i->index = 0;
		while (current->nbr > current->next->nbr)
		{
			(i->index)++;
			current = current->next;
		}
		i->min_index = i->index;
		i->max_index = (i->index == stacks->b_size - 1) ? 0 : i->index + 1;
		i->min = current->nbr;
		i->max = current->next->nbr;
		get_b_placement_costs_2(i, costs, stacks, a);
	}
	free(i);
}

void		get_placement_costs(size_t *costs, t_struct *stacks,
				t_element *a, size_t index)
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
