/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 12:21:19 by lararamirez       #+#    #+#             */
/*   Updated: 2017/12/30 16:32:16 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../../libft/includes/libft.h"

typedef struct s_element	t_element;
typedef struct s_struct		t_struct;
typedef	struct s_list		t_list;
typedef	struct s_index		t_index;

struct			s_element
{
	int			nbr;
	t_element	*next;
	t_element	*previous;
};

struct			s_struct
{
	t_element	*a;
	t_element	*b;
	size_t		a_size;
	size_t		b_size;
};

struct			s_list
{
	char		*command;
	t_list		*next;
};

struct			s_index
{
	int			min;
	int			max;
	size_t		index;
	size_t		min_index;
	size_t		max_index;
};

/*
** Functions in main.c
*/
void			add_to_list(t_list **instructions, char *command);
void			usage(void);
void			display_instructions(t_list **instructions, char option);

/*
** Functions in instructions.c
*/
void			swap(t_struct *stacks, t_list **instructions, char target);
void			rotate(t_struct *stacks, t_list **instructions, char target);
void			rev_rotate(t_struct *stacks,
					t_list **instructions, char target);
void			push_a(t_struct *stacks, t_list **instructions);
void			push_b(t_struct *stacks, t_list **instructions);

/*
** Functions in compute_solution.c
*/
void			push_back_onto_a(t_struct *stacks, t_list **instructions);
void			copy_tab(size_t *tab, size_t *cpy);
void			push_cheapest_onto_b(t_struct *stacks, t_list **instructions);
t_list			**compute_solution(t_struct *stacks, t_list **instructions);
void			move_cheapest(t_struct *stacks, size_t *costs,
					t_list **instructions);

/*
** Functions in costs.c
*/
void			compute_cheapest_2(size_t cost_2, size_t cost_3,
					size_t cost_4, size_t *costs);
void			compute_cheapest(size_t *costs);
void			get_placement_costs(size_t *costs, t_struct *stacks,
					t_element *a, size_t index);
void			get_b_placement_costs_2(t_index *i, size_t *costs,
				t_struct *stacks, t_element *a);
void			get_b_placement_costs(size_t *costs,
					t_struct *stacks, t_element *a);

/*
** Functions in stack_util.c
*/
t_struct		*build(int arg_nbr, char **args);
t_element		*create_elem(char *arg);
void			add_to_a(t_struct *stacks, t_element *new_elem, char last);
void			free_stacks(t_struct *stacks);

/*
** Functions in is_sortable.c
*/

void			init(size_t *index, t_element **start,
					t_element **tmp, t_element *a);
void			set_start(char *swap_needed, t_element **start, t_element *tmp);
char			is_sortable_in_place(t_element *a, size_t a_size);
char			is_sortable_in_place_2(size_t *a_size,
					char *swap_needed, t_element **start);

/*
** Functions in sort.c
*/
void			sort_a(t_struct *stacks, size_t a_size, t_list **instructions);
char			sort_a_2(t_struct *stacks, t_element *tmp, size_t *index,
					t_list **instructions);
void			sort_b(t_struct *stacks, size_t b_size, t_list **instructions);
char			sort_b_2(t_struct *stacks, t_element *tmp,
					size_t *index, t_list **instructions);

/*
** Functions in tools.c
*/
int				is_sorted(t_element *stack, size_t stack_size);
int				is_rev_sorted(t_element *stack, size_t stack_size);
t_list			**optimize(t_list **instructions);
void			concatenate(t_list *current, t_list *next, char *command);

/*
** Functions in small_compute.c
*/
void			small_compute(t_struct *stacks, t_list **instructions);
size_t			find_min_index(t_struct *stacks);
void			bubble_up_min(size_t index, t_struct *stacks,
					t_list **instructions);

#endif
