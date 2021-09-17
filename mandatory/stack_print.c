/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 11:12:19 by aperez-b          #+#    #+#             */
/*   Updated: 2021/09/17 17:31:52 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

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
	int	max_value;

	if (!a && !b)
		return (ft_putstr_fd("Error\n", 2));
	max_value = ft_lstsize(a) - 1;
	if (ft_lstsize(b) - 1 > max_value)
		max_value = ft_lstsize(b) - 1;
	write(1, "\n", 1);
	while (a || b)
	{
		a = st_printstack(a, base, max_value);
		b = st_printstack(b, base, max_value);
		ft_putchar_fd('\n', 1);
	}
	ft_putnchar_fd('-', 1, 10);
	ft_putstr_fd("\t", 1);
	ft_putnchar_fd('-', 1, 10);
	ft_putstr_fd("\na\t\tb\n\n", 1);
	return (0);
}
