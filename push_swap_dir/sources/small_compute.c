/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_compute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 11:14:39 by lararamirez       #+#    #+#             */
/*   Updated: 2017/12/21 10:47:48 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void        small_compute(t_struct *stacks, t_list **instructions)
{
    int         min;
    t_element   *tmp;
    size_t      size;
    size_t      index;
    size_t      index_min;

    min = stacks->a->nbr;
    tmp = stacks->a;
    size = stacks->a_size;
    index = 0;
    index_min = 0;
    while (size)
    {
        if (tmp->nbr < min)
        {
            min = tmp->nbr;
            index_min = index;
        }
        index++;
        size--;
        tmp = tmp->next;
    }

}
find min
bubble up, at each step check if swap or sorting in place works
push onto b
check if swap or sorting in place works for rest of the list
repeat until sorted