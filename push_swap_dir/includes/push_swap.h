/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 12:21:19 by lararamirez       #+#    #+#             */
/*   Updated: 2017/11/03 14:14:06 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../../libft/includes/libft.h"

typedef struct	s_element
{
	int					nbr;
	struct s_element	*next;
	struct s_element	*previous;
}				t_element;

typedef struct	s_struct
{
	t_element			*a;
	t_element			*b;
	size_t				a_size;
	size_t				b_size;
}				t_struct;

typedef	struct	s_list
{
	char				*command;
	struct s_list		*next;
}				t_list;

// /*
// ** Functions in instructions.c
// */
void				swap(t_struct *stacks, t_list **instructions, char target);
void				rotate(t_struct *stacks, t_list **instructions, char target);
void				rev_rotate(t_struct *stacks, t_list **instructions, char target);
void				push_a(t_struct *stacks, t_list **instructions);
void				push_b(t_struct *stacks, t_list **instructions);

// /*
// ** Functions in compute_solution.c
// */
t_list			**compute_solution(t_struct *stacks, t_list **instructions);
size_t			*get_placement_costs(size_t *costs, t_struct *stacks, size_t index);

// size_t			cost(t_stack *a, size_t i);
// void			select_min_and_bubble(t_stack *a, t_stack *b,
// 					size_t min1_index, t_list **instructions);
// void			bubble1(t_stack *a, t_stack *b, size_t i,
// 					t_list **instructions);
// void			bubble2(t_stack *a, t_stack *b, size_t i,
// 					t_list **instructions);

// /*
// ** Functions in tools.c
// */
// size_t			get_min_index(t_stack *a);
// size_t			get_second_min_index(t_stack *a, size_t ignore_index);
// void				duplicates_check(t_stack *stack);
int				is_sorted(t_element *stack_top, size_t stack_size);
int				is_rev_sorted(t_element *stack_bottom, size_t stack_size);

/*
** Functions in stack_util.c
*/
t_struct		*build(int arg_nbr, char **args);
t_element		*create_elem(char *arg);
void			add_to_a(t_struct *stacks, t_element *new_elem, char last);
void			free_stacks(t_struct *stacks);
void       		sort_a(t_struct *stacks, size_t a_size, t_list **instructions);
char        	is_sortable_in_place(t_element *a, size_t a_size);



/*
** Functions in list_util.c
*/
void			add_to_list(t_list **instructions, char *command);
void			display_instructions(t_list **instructions, char option);

#endif
