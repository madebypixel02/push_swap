/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 09:58:49 by aperez-b          #+#    #+#             */
/*   Updated: 2021/08/29 14:40:54 by aperez-b         ###   ########.fr       */
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

/* Checks content at the top without modifying it */
void	*st_peek(t_stack *stack);

/* Prints stack from current node */
int		st_print(t_stack *stack);

/* Frees allocated memory for a stack */
void	st_free(t_stack *stack);

#endif
