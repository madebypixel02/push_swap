/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 16:26:30 by aperez-b          #+#    #+#             */
/*   Updated: 2021/09/27 20:22:31 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/stack.h"
#include <stddef.h>

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

t_list	*st_min(t_list *stack)
{
	t_list	*min;

	min = NULL;
	while (stack)
	{
		if (!min || *(int *)min->content > *(int *)stack->content)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_list	*st_max(t_list *stack)
{
	t_list	*max;

	max = NULL;
	while (stack)
	{
		if (!max || *(int *)max->content < *(int *)stack->content)
			max = stack;
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

void	st_replace_at(t_list **stack, int index, void *nw, int size)
{
	int		i;
	t_list	*start;

	i = 0;
	start = *stack;
	while (start)
	{
		if (i == index)
		{
			free(start->content);
			start->content = NULL;
			start->content = malloc(size);
			ft_memcpy(start->content, nw, size);
			break ;
		}
		i++;
		start = start->next;
	}
}
