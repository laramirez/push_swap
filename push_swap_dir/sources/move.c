/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 15:42:07 by lararamirez       #+#    #+#             */
/*   Updated: 2017/11/05 17:54:52 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_cheapest(t_struct *stacks, size_t *costs, t_list **instructions)
{
	size_t		a_moves;
	size_t		b_moves;

	a_moves = (costs[6] == 1 || costs[6] == 3) ? costs[2] : costs[3];
	b_moves = (costs[6] == 1 || costs[6] == 4) ? costs[4] : costs[5];
	print_stacks(stacks);
	while (a_moves || b_moves)
	{
		if (a_moves)
		{
			(costs[6] == 1 || costs[6] == 3) ?
				rotate(stacks, instructions, 'a') : rev_rotate(stacks, instructions, 'a');
			a_moves--;
		}
		if (b_moves)
		{
			(costs[6] == 1 || costs[6] == 4) ?
				rotate(stacks, instructions, 'b') : rev_rotate(stacks, instructions, 'b');
			b_moves--;
		}
	}
	push_a(stacks, instructions);
	print_stacks(stacks);
	while (stacks->b->nbr < stacks->b->previous->nbr)
		rotate(stacks, instructions, 'b');
	print_stacks(stacks);
}
