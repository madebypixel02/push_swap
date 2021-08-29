/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 16:26:30 by aperez-b          #+#    #+#             */
/*   Updated: 2021/08/29 22:16:05 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/stack.h"
#include <stddef.h>

t_stack	*st_printstack(t_stack *stack)
{
	if (stack)
	{
		ft_putnbr_fd(*(int *)stack->content, 1);
		if (ft_nbrlen(*(int *)stack->content, 10) > 7)
			ft_putnchar_fd('\t', 1, 1);
		else
			ft_putnchar_fd('\t', 1, 2);
		stack = stack->next;
	}
	else
	{
		ft_putchar_fd('.', 1);
		ft_putnchar_fd('\t', 1, 2);
	}
	return (stack);
}

int	st_printstack_ab(t_stack *a, t_stack *b)
{
	if (!a && !b)
		return (ft_putstr_fd("Error\n", 2));
	while (a && a->prev)
		a = a->prev;
	while (b && b->prev)
		b = b->prev;
	while (a || b)
	{
		a = st_printstack(a);
		b = st_printstack(b);
		ft_putchar_fd('\n', 1);
	}
	ft_putstr_fd("-\t\t-\na\t\tb\n\n\n", 1);
	return (0);
}

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
