/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 12:11:19 by lararamirez       #+#    #+#             */
/*   Updated: 2017/11/02 17:57:53 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void        sort_a(t_struct *stacks, size_t a_size, t_list **instructions)
{
    t_element   *tmp;
    size_t      index;

    printf("it is %zu\n", a_size / 2);
    if (a_size == 2)
        swap(stacks, instructions, 'a');
    else
    {
        tmp = stacks->a;
        index = 0;
        while (a_size - 1)
        {
            if (tmp->nbr > tmp->next->nbr)
            {
                if (index == 0 && tmp->nbr < tmp->next->next->nbr)
                {
                    swap(stacks, instructions, 'a');
                    return ;
                }
                else if (index < a_size / 2)
                {
                    while (index + 1)
                    {
                        rotate(stacks, instructions, 'a');
                        index--;
                    }
                    return ;
                }
                else
                {
                    while (index)
                    {
                        rev_rotate(stacks, instructions, 'a');
                        index--;
                    }
                    return ;
                }
            }
            a_size--;
            index++;
            tmp = tmp->next;
        }
    }
}

char        is_sortable_in_place(t_element *a, size_t a_size)
{
    t_element   *tmp;
    size_t      sorted;

    if (a_size <= 2)
        return (1);
    tmp = a;
    sorted = 0;
    while (a_size - 1)
    {
        if (tmp->nbr > tmp->next->nbr)
            sorted++;
        tmp = tmp->next;
        a_size--;
    }
    if (sorted < 2)
        return (1);
    return (0);
}

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
