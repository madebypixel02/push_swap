/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 09:58:49 by aperez-b          #+#    #+#             */
/*   Updated: 2021/09/14 15:02:01 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H

# define STACK_H

# include "../libft/lib/libft.h"

/* Deletes element at the top of the stack and returns it */
void	*st_pop(t_list **stack);

/* Adds new node at the top of the stack */
int		st_push(t_list **stack, void *newcontent, size_t size);

/* Allocates memory for new stack node */
t_list	*st_newstack(void *newcontent, size_t size);

/* Prints stack from current node and tries to move to the next one */
t_list	*st_printstack(t_list *stack);

/* Prints both stacks side-by-side */
int		st_printstack_ab(t_list *a, t_list *b);

/* Swaps first two elements of a stack if needed */
int		st_swap_ab(t_list **a, t_list **b, char c);

/* Performs st_swap_ab on both a and b */
int		st_swap_ss(t_list **a, t_list **b);

/* Move top of second stack to top of first stack */
int		st_push_ab(t_list **a, t_list **b, char c);

/* Moves every element one position up */
int		st_rotate_ab(t_list **a, t_list **b, char c);

/* Performs st_rotate_ab on both a and b */
int		st_rotate_rr(t_list **a, t_list **b);

/* Moves every element one position down */
int		st_rrotate_ab(t_list **a, t_list **b, char c);

/* Performs st_rrotate_ab on both a and b */
int		st_rrotate_rrr(t_list **a, t_list **b);

/* Returns first occurrence of content in the stack, or -1 */
int		st_find(t_list *stack, void *content, size_t size);

/* Returns 1 if stack a is ordered and b is empty */
int		st_is_ordered(t_list *a, t_list *b);

/* Moves an element to the top as efficiently as possible */
int		st_to_top(t_list **a, t_list **b, void *content, char c);

/* Returns min element of a stack */
t_list	*st_min(t_list *stack);

/* Returns max element of a stack */
t_list	*st_max(t_list *stack);

/* Retrieves node at the given index, or NULL */
t_list	*st_get_at(t_list *stack, int index);

/* Changes content at given index */
void	st_replace_at(t_list **stack, int index, void *nw, int size);

#endif
