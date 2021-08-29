/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 09:58:49 by aperez-b          #+#    #+#             */
/*   Updated: 2021/08/29 20:00:07 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H

# define STACK_H

# include "../libft/lib/libft.h"

/* Classic stack struct (elemets are added and removed from the top) */
typedef struct s_stack
{
	void			*content;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

/* Deletes element at the top of the stack and returns it */
void	*st_pop(t_stack **stack);

/* Adds new node at the top of the stack */
int		st_push(t_stack **stack, void *newcontent, size_t size);

/* Allocates memory for new stack node */
t_stack	*st_newstack(void *newcontent, size_t size);

/* Prints stack from current node and tries to move to the next one */
t_stack	*st_printstack(t_stack *stack);

/* Prints both stacks side-by-side */
int		st_printstack_ab(t_stack *a, t_stack *b);

/* Frees allocated memory for a stack */
void	st_freestack(t_stack **stack);

/* Returns number of elements in stack */
int		st_stacklen(t_stack *stack);

/* Swaps first two elements of a stack if needed */
void	st_swap_ab(t_stack **stack);

/* Performs st_swap_ab on both a and b */
void	st_swap_ss(t_stack **a, t_stack **b);

/* Move top of second stack to top of first stack */
void	st_push_ab(t_stack **a, t_stack **b);

/* Performs st_rotate_ab on both a and b */
int		st_rotate_rr(t_stack **a, t_stack **b);

/* Moves every element one position up */
int		st_rotate_ab(t_stack **stack);

/* Moves every element one position down */
int		st_rrotate_ab(t_stack **stack);

/* Performs st_rrotate_ab on both a and b */
int		st_rrotate_rrr(t_stack **a, t_stack **b);

#endif
