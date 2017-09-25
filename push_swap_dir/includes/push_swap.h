/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 12:21:19 by lararamirez       #+#    #+#             */
/*   Updated: 2017/09/11 20:20:07 by lramirez         ###   ########.fr       */
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
	size_t				index;
	struct s_element	*next;
}				t_element;

typedef struct	s_stack
{
	t_element			*top;
	size_t				size;
	size_t				middle;
}				t_stack;

typedef	struct	s_list
{
	char				*command;
	struct s_list		*next;
}				t_list;

/*
** Functions in instructions.c
*/
void			swap(t_stack *stack, t_list **instructions, char target);
void			rotate(t_stack *stack, t_list **instructions, char target);
void			rev_rotate(t_stack *stack, t_list **instructions, char target);
void			push(t_stack *send_stack, t_stack *receive_stack,
					t_list **instructions, char target);
char			*last(t_list **instructions);

/*
** Functions in compute_solution.c
*/
t_list			**compute_solution(t_stack *a, t_stack *b,
					t_list **instructions);
size_t			cost(t_stack *a, size_t i);
void			select_min_and_bubble(t_stack *a, t_stack *b,
					size_t min1_index, t_list **instructions);
void			bubble1(t_stack *a, t_stack *b, size_t i,
					t_list **instructions);
void			bubble2(t_stack *a, t_stack *b, size_t i,
					t_list **instructions);

/*
** Functions in tools.c
*/
size_t			get_min_index(t_stack *a);
size_t			get_second_min_index(t_stack *a, size_t ignore_index);
void			duplicates_check(t_stack *stack);
int				is_sorted(t_stack *stack);
int				is_rev_sorted(t_stack *stack);

/*
** Functions in stack_util.c
*/
t_stack			*init_stack(void);
t_element		*create_element(char *arg, int index);
void			pile_onto_stack(t_stack *a, t_element *new_element);
void			free_stack(t_stack *stack);

/*
** Functions in list_util.c
*/
t_list			**new_list(void);
void			add_to_list(t_list **instructions, char *command);
void			display_instructions(t_list **instructions, char option);
t_list			**optimize(t_list **instructions);
void			concatenate(t_list *current, t_list *next, char *command);

#endif
