/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 10:50:03 by aperez-b          #+#    #+#             */
/*   Updated: 2021/09/01 13:55:44 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

void	st_order(t_stack *a, t_stack *b)
{
	int	mid;

	mid = 0;
	if (!st_stacklen(b))
		mid = st_get_mid(a);
	st_split(a, b, mid);
}

int	st_get_mid(t_stack *stack)
{
	int	mid;

	mid = (*(int *)st_min(stack) + *(int *)st_max(stack)) / 2;
	return (mid);
}

void	st_split(t_stack *a, t_stack *b, int mid)
{
	//while (*(int *)st_min(a) < mid)
	st_findswap(a, b, mid);
}

void	st_findswap(t_stack *a, t_stack *b, int mid)
{
	while (*(int *)a->content > mid)
	{
		ft_putstr_fd("ra\n", 1);
		st_rotate_ab(&a);
	}
	ft_putstr_fd("pb\n", 1);
	st_push_ab(&b, &a);
}
