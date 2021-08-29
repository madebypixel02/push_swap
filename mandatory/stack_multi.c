/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_multi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 19:51:14 by aperez-b          #+#    #+#             */
/*   Updated: 2021/08/29 19:57:13 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/stack.h"

void	st_swap_ss(t_stack **a, t_stack **b)
{
	st_swap_ab(a);
	st_swap_ab(b);
}

int	st_rotate_rr(t_stack **a, t_stack **b)
{
	if (st_rotate_ab(a))
		return (1);
	if (st_rotate_ab(b))
		return (1);
	return (0);
}

int	st_rrotate_rrr(t_stack **a, t_stack **b)
{
	if (st_rrotate_ab(a))
		return (1);
	if (st_rrotate_ab(b))
		return (1);
	return (0);
}
