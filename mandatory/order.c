/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 10:50:03 by aperez-b          #+#    #+#             */
/*   Updated: 2021/09/19 12:43:46 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"
#include <stdio.h>

int	st_order(t_list **a, t_list **b)
{
	int	max_value;

	max_value = ft_lstsize(*a) - 1;
	if (st_is_ordered(*a))
		return (0);
	if (max_value + 1 == 2)
		return (st_swap_ab(a, 'a'));
	st_translate(a);
	while (ft_lstsize(*a) > 3 && ft_lstsize(*a) < 7)
	{
		st_to_top(a, b, st_min(*a)->content, 'a');
		st_push_ab(b, a, 'b');
	}
	st_sort_small(a, b);
	if (!st_is_ordered(*a))
		st_radix_sort(a, b, ft_nbrlen(max_value, 2), 0);
	return (0);
}

void	st_sort_small(t_list **a, t_list **b)
{
	if (*(int *)st_get_at(*a, 1)->content == *(int *)st_min(*a)->content && \
		*(int *)st_get_at(*a, 2)->content == *(int *)st_max(*a)->content)
		st_swap_ab(a, 'a');
	if (*(int *)st_get_at(*a, 1)->content == *(int *)st_min(*a)->content && \
		*(int *)st_get_at(*a, 0)->content == *(int *)st_max(*a)->content)
		st_rotate_ab(a, 'a');
	if (*(int *)st_get_at(*a, 2)->content == *(int *)st_min(*a)->content && \
		*(int *)st_get_at(*a, 1)->content == *(int *)st_max(*a)->content)
		st_rrotate_ab(a, 'a');
	if (*(int *)st_get_at(*a, 0)->content == *(int *)st_min(*a)->content && \
		*(int *)st_get_at(*a, 1)->content == *(int *)st_max(*a)->content)
	{
		st_swap_ab(a, 'a');
		st_rotate_ab(a, 'a');
	}
	if (*(int *)st_get_at(*a, 2)->content == *(int *)st_min(*a)->content && \
		*(int *)st_get_at(*a, 0)->content == *(int *)st_max(*a)->content)
	{
		st_swap_ab(a, 'a');
		st_rrotate_ab(a, 'a');
	}
	while (ft_lstsize(*b))
		st_push_ab(a, b, 'a');
}

int	st_radix_sort(t_list **a, t_list **b, int max_len, int right_shift)
{
	int	i;
	int	len;

	if (right_shift > max_len || st_is_ordered(*a))
		return (0);
	i = 0;
	len = ft_lstsize(*a);
	while (i < len)
	{
		if (!(*(int *)(*a)->content >> right_shift & 1))
			st_push_ab(b, a, 'b');
		else
			st_rotate_ab(a, 'a');
		i++;
	}
	i = 0;
	len = ft_lstsize(*b);
	while (i < len)
	{
		st_push_ab(a, b, 'a');
		i++;
	}
	return (st_radix_sort(a, b, max_len, right_shift + 1));
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
	while (*(int *)st_min(*a)->content < mid && ft_lstsize(*a) > 2)
	{
		while (*(int *)a[0]->content != *(int *)st_min(*a)->content)
			*count += st_rotate_ab(a, 'a');
		if (a[0]->next && *(int *)a[0]->next->content < *(int *)(a[0]->content))
			*count += st_swap_ab(a, 'a');
		*count += st_push_ab(b, a, 'b');
	}
}
