/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 11:24:35 by lararamirez       #+#    #+#             */
/*   Updated: 2017/09/11 20:20:07 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include "../../libft/includes/libft.h"

typedef	struct	s_list
{
	char				*command;
	struct s_list		*next;
}				t_list;

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
}				t_stack;

/*
** Functions in checker_util.c
*/
void			duplicates_check(t_stack *stack);
void			apply_instructions(t_stack *a, t_stack *b,
					t_list **instructions, char option);
void			apply_double(t_stack *a, t_stack *b, char *command, char opt);
int				is_sorted(t_stack *a);
t_stack			*init_stack(void);

/*
** Functions in display_and_free.c
*/
void			display_stacks(t_stack *a, t_stack *b);
void			free_instructions(t_list **instructions);
void			free_stack(t_stack *stack);
t_element		*create_element(char *arg, int index);
void			pile_onto_stack(t_stack *a, t_element *new_element);

/*
** Functions in get.c
*/
t_list			**new_list(void);
t_list			**get_instructions(t_list **instructions, t_stack *a);
void			check_instruction(char *instruction);
t_list			*create_instruction(void);

/*
** Functions in instructions.c
*/
void			swap(t_stack *stack);
void			rotate(t_stack *stack);
void			rev_rotate(t_stack *stack);
void			push(t_stack *send_stack, t_stack *receive_stack);

#endif
