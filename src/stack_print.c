/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 11:12:19 by aperez-b          #+#    #+#             */
/*   Updated: 2021/09/27 20:23:33 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

t_list	*st_printstack(t_list *stack, char *base, int max_value)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (stack)
	{
		if (*(int *)stack->content >= 0)
			ft_putnchar_fd('0', 1, ft_nbrlen(max_value, base_len) - \
				ft_nbrlen(*(int *)stack->content, base_len));
		ft_putnbr_base_fd(*(int *)stack->content, base, 1);
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

int	st_printstack_ab(t_list *a, t_list *b, char *base)
{
	t_list	*max_a;
	t_list	*max_b;

	if (!a && !b)
		return (ft_putstr_fd("Error\n", 2));
	write(1, "\n", 1);
	max_a = st_max(a);
	max_b = st_max(b);
	while (a || b)
	{
		if (max_a)
			a = st_printstack(a, base, *(int *)max_a->content);
		else
			a = st_printstack(a, base, 0);
		if (max_b)
			b = st_printstack(b, base, *(int *)max_b->content);
		else
			b = st_printstack(b, base, 0);
		ft_putchar_fd('\n', 1);
	}
	ft_putnchar_fd('-', 1, 10);
	ft_putstr_fd("\t", 1);
	ft_putnchar_fd('-', 1, 10);
	ft_putstr_fd("\na\t\tb\n\n", 1);
	return (0);
}
