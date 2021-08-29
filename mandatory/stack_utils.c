/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 16:26:30 by aperez-b          #+#    #+#             */
/*   Updated: 2021/08/29 20:16:21 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/stack.h"

t_stack	*st_printstack(t_stack *stack)
{
	if (stack)
	{
		ft_putnbr_fd(*(int *)stack->content, 1);
		stack = stack->next;
	}
	else
		ft_putchar_fd('.', 1);
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
		ft_putchar_fd('\t', 1);
		b = st_printstack(b);
		ft_putchar_fd('\n', 1);
	}
	ft_putstr_fd("-\t-\na\tb\n\n\n", 1);
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
