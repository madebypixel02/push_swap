/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 16:26:30 by aperez-b          #+#    #+#             */
/*   Updated: 2021/09/08 21:07:37 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/stack.h"
#include <stddef.h>

int	st_in_stack(t_list *stack, void *content, size_t size)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (!ft_memcmp(content, stack->content, size))
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	st_find(t_list *stack, void *content, size_t size)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (!ft_memcmp(stack->content, content, size))
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

void	*st_min(t_list *stack)
{
	void	*min;

	min = NULL;
	if (!stack)
		return (min);
	while (stack)
	{
		if (!min || *(int *)min > *(int *)stack->content)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

void	*st_max(t_list *stack)
{
	void	*max;

	max = NULL;
	if (!stack)
		return (max);
	while (stack)
	{
		if (!max || *(int *)max < *(int *)stack->content)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}

t_list	*st_get_at(t_list *stack, int index)
{
	int		i;

	i = 0;
	while (stack)
	{
		if (i == index)
			return (stack);
		i++;
		stack = stack->next;
	}
	return (NULL);
}
