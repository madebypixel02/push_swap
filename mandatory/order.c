/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 10:50:03 by aperez-b          #+#    #+#             */
/*   Updated: 2021/09/05 15:07:29 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"
#include <stdio.h>

int	st_order(t_list **a, t_list **b, int *count)
{
	int	mid;

	if (st_is_ordered(*a, *b))
		return (0);
	while (ft_lstsize(*a) > 2)
	{
		mid = st_get_mid(*a);
		st_split(a, b, mid, count);
	}
	if (*(int *)a[0]->content > *(int *)a[0]->next->content)
		*count += st_swap_ab(a, 'a');
	while (ft_lstsize(*b))
		*count += st_push_ab(a, b, 'a');
	return (0);
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
			*count += st_rotate_ab(a, 'a');
		if (a[0]->next && *(int *)a[0]->next->content < *(int *)(a[0]->content))
			*count += st_swap_ab(a, 'a');
		*count += st_push_ab(b, a, 'b');
	}
}
