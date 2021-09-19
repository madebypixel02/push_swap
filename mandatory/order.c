/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 10:50:03 by aperez-b          #+#    #+#             */
/*   Updated: 2021/09/19 17:11:13 by aperez-b         ###   ########.fr       */
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
		st_to_top(a, st_min(*a)->content, 'a');
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
	int	limit;

	if (right_shift > max_len || st_is_ordered(*a))
	{
		while (ft_lstsize(*b))
			st_push_ab(a, b, 'a');
		return (0);
	}
	i = -1;
	len = ft_lstsize(*a);
	limit = st_get_ordered(*a, *b, 'a');
	while (++i < len)
	{
		if (!(*(int *)(*a)->content >> right_shift & 1) && i < len - limit)
			st_push_ab(b, a, 'b');
		else
			st_rotate_ab(a, 'a');
	}
	i = -1;
	limit = st_get_ordered(*a, *b, 'b');
	while (++i < len - limit)
		st_push_ab(a, b, 'a');
	return (st_radix_sort(a, b, max_len, right_shift + 1));
}
