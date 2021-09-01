/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 16:26:30 by aperez-b          #+#    #+#             */
/*   Updated: 2021/09/01 12:49:25 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/stack.h"


int	st_stacklen(t_stack *stack)
{
	int		count;

	count = 0;
	if (!stack)
		return (count);
	while (stack->prev)
		stack = stack->prev;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

int	st_in_stack(t_stack *stack, void *content, size_t size)
{
	if (!stack)
		return (0);
	while (stack->prev)
		stack = stack->prev;
	while (stack)
	{
		if (!ft_memcmp(content, stack->content, size))
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	st_is_ordered(t_stack *stack)
{
	void	*prev;

	prev = NULL;
	if (!stack)
		return (0);
	while (stack->prev)
		stack = stack->prev;
	while (stack)
	{
		if (prev && *(int *)prev > *(int *)stack->content)
			return (0);
		prev = stack->content;
		stack = stack->next;
	}
	return (1);
}

void	*st_min(t_stack *stack)
{
	void	*min;

	min = NULL;
	if (!stack)
		return (min);
	while (stack->prev)
		stack = stack->prev;
	while (stack)
	{
		if (!min || *(int *)min > *(int *)stack->content)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

void	*st_max(t_stack *stack)
{
	void	*max;

	max = NULL;
	if (!stack)
		return (max);
	while (stack->prev)
		stack = stack->prev;
	while (stack)
	{
		if (!max || *(int *)max < *(int *)stack->content)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}
