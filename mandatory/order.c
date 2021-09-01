/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 10:50:03 by aperez-b          #+#    #+#             */
/*   Updated: 2021/09/01 20:22:16 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

int	st_order(t_stack **a, t_stack **b)
{
	int	mid;

	if (st_is_ordered(*a))
		return (0);
	while (st_stacklen(*a) > 2)
	{
		mid = st_get_mid(*a);
		st_split(a, b, mid);
	}
	if (!st_is_ordered(*a))
	{
		ft_putstr_fd("sa\n", 1);
		st_swap_ab(a);
	}
	while (st_stacklen(*b))
	{
		ft_putstr_fd("pa\n", 1);
		st_push_ab(a, b);
	}
	return (0);
}

int	st_get_mid(t_stack *stack)
{
	int	mid;
	int	len;

	len = 0;
	mid = 0;
	while (stack->prev)
		stack = stack->prev;
	while (stack)
	{
		mid += *(int *)stack->content;
		len++;
		stack = stack->next;
	}
	/*ft_putstr_fd("Middle point: ", 1);
	ft_putnbr_fd(mid / len, 1);
	ft_putnchar_fd('\n', 1, 2);*/
	return (mid / len);
}

void	st_split(t_stack **a, t_stack **b, int mid)
{
	while (*(int *)st_min(*a) < mid && st_stacklen(*a) > 2)
	{
		while (*(int *)a[0]->content != *(int *)st_min(*a))
		{
			ft_putstr_fd("ra\n", 1);
			st_rotate_ab(a);
		}
		if (a[0]->next && *(int *)a[0]->next->content < *(int *)(a[0]->content))
		{
			ft_putstr_fd("sa\n", 1);
			st_swap_ab(a);
		}
		ft_putstr_fd("pb\n", 1);
		st_push_ab(b, a);
	}
}
