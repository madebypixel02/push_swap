/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_multi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 19:51:14 by aperez-b          #+#    #+#             */
/*   Updated: 2021/09/02 21:13:19 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/stack.h"

void	st_swap_ss(t_list **a, t_list **b)
{
	st_swap_ab(a, 0);
	st_swap_ab(b, 0);
	ft_putstr_fd("ss\n", 1);
}

int	st_rotate_rr(t_list **a, t_list **b)
{
	if (st_rotate_ab(a, 0) == -1)
		return (-1);
	if (st_rotate_ab(b, 0) == -1)
		return (-1);
	ft_putstr_fd("rr\n", 1);
	return (0);
}

int	st_rrotate_rrr(t_list **a, t_list **b)
{
	if (st_rrotate_ab(a, 0) == -1)
		return (-1);
	if (st_rrotate_ab(b, 0) == -1)
		return (-1);
	ft_putstr_fd("rrr\n", 1);
	return (0);
}
