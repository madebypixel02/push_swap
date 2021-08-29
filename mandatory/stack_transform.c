/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 16:30:04 by aperez-b          #+#    #+#             */
/*   Updated: 2021/08/29 22:53:10 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/stack.h"

/* Alternate swap algorithm in case the other one causes trouble */
/*void	st_swap_ab(t_stack **stack)
{
	void	*first;
	void	*second;

	if (st_stacklen(*stack) > 1)
	{
		first = st_pop(stack);
		second = st_pop(stack);
		st_push(stack, first, sizeof(int));
		st_push(stack, second, sizeof(int));
		free(first);
		free(second);
	}
}*/

void	st_swap_ab(t_stack **stack)
{
	void	*temp;

	if (st_stacklen(*stack) > 1)
	{
		temp = stack[0]->content;
		stack[0]->content = stack[0]->next->content;
		stack[0]->next->content = temp;
	}
}

void	st_push_ab(t_stack **a, t_stack **b)
{
	void	*temp;

	if (st_stacklen(*b))
	{
		temp = st_pop(b);
		st_push(a, temp, sizeof(int));
		free(temp);
	}
}

int	st_rotate_ab(t_stack **stack)
{
	void	*content;
	t_stack	*new;
	t_stack	*temp;

	temp = *stack;
	if (st_stacklen(temp) > 1)
	{
		while (temp->next)
			temp = temp->next;
		content = st_pop(stack);
		new = st_newstack(content, sizeof(int));
		if (!new)
			return (-1);
		free(content);
		temp->next = new;
		new->prev = temp;
	}
	return (0);
}

int	st_rrotate_ab(t_stack **stack)
{
	void	*content;
	t_stack	*temp;

	if (!stack[0])
		return (-1);
	temp = *stack;
	if (st_stacklen(temp) > 1)
	{
		while (temp->next)
			temp = temp->next;
		content = temp->content;
		temp->prev->next = NULL;
		free(temp);
		temp = NULL;
		st_push(stack, content, sizeof(int));
		free(content);
	}
	return (0);
}
