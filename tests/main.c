/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 10:45:14 by aperez-b          #+#    #+#             */
/*   Updated: 2021/08/29 20:01:52 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/stack.h"

int	main(void)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	a = NULL;
	b = NULL;
	i = 1;
	while (i < 5)
	{
		if (!st_push(&a, (void *)&i, sizeof(int)))
			return (ft_putstr_fd("Memory Allocation Error!\n", 2));
		i++;
	}
	st_swap_ss(&a, &b);
	st_printstack_ab(a, b);
	while (st_stacklen(a))
	{
		st_push_ab(&b, &a);
		st_printstack_ab(a, b);
	}
	st_rrotate_rrr(&a, &b);
	st_printstack_ab(a, b);
	st_freestack(&a);
	st_freestack(&b);
	return (0);
}
