/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 11:12:19 by aperez-b          #+#    #+#             */
/*   Updated: 2021/09/01 11:12:55 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

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

