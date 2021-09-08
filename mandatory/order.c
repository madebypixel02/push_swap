/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 10:50:03 by aperez-b          #+#    #+#             */
/*   Updated: 2021/09/08 23:03:29 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"
#include <stdio.h>

int	st_order(t_list **a, t_list **b)
{
	if (st_is_ordered(*a, *b))
		return (0);
	while (ft_lstsize(*a) > 3)
	{
		st_to_top(a, b, st_max(*a), 'a');
		st_push_ab(b, a, 'b');
	}
	st_sort_small(a, b);
	return (0);
}

void	st_sort_small(t_list **a, t_list **b)
{
	if (*(int *)st_get_at(*a, 1)->content == *(int *)st_min(*a) && \
		*(int *)st_get_at(*a, 2)->content == *(int *)st_max(*a))
		st_swap_ab(a, b, 'a');
	if (*(int *)st_get_at(*a, 1)->content == *(int *)st_min(*a) && \
		*(int *)st_get_at(*a, 0)->content == *(int *)st_max(*a))
		st_rotate_ab(a, b, 'a');
	if (*(int *)st_get_at(*a, 2)->content == *(int *)st_min(*a) && \
		*(int *)st_get_at(*a, 1)->content == *(int *)st_max(*a))
		st_rrotate_ab(a, b, 'a');
	if (*(int *)st_get_at(*a, 0)->content == *(int *)st_min(*a) && \
		*(int *)st_get_at(*a, 1)->content == *(int *)st_max(*a))
	{
		st_swap_ab(a, b, 'a');
		st_rotate_ab(a, b, 'a');
	}
	if (*(int *)st_get_at(*a, 2)->content == *(int *)st_min(*a) && \
		*(int *)st_get_at(*a, 0)->content == *(int *)st_max(*a))
	{
		st_swap_ab(a, b, 'a');
		st_rrotate_ab(a, b, 'a');
	}
	st_to_top(a, b, st_min(*a), 'a');
	while (ft_lstsize(*b))
		st_push_ab(a, b, 'a');
	st_to_top(a, b, st_min(*a), 'a');
}

int	st_get_mid(t_list *stack)
{
	int	mid;
	int	len;

	len = ft_lstsize(stack);
	mid = 0;
	while (stack)
	{
		mid += *(int *)stack->content;
		stack = stack->next;
	}
	return (mid / len);
}

void	st_split(t_list **a, t_list **b, int mid, int *count)
{
	while (*(int *)st_min(*a) < mid && ft_lstsize(*a) > 2)
	{
		while (*(int *)a[0]->content != *(int *)st_min(*a))
			*count += st_rotate_ab(a, b, 'a');
		if (a[0]->next && *(int *)a[0]->next->content < *(int *)(a[0]->content))
			*count += st_swap_ab(a, b, 'a');
		*count += st_push_ab(b, a, 'b');
	}
}
