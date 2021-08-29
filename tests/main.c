/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 10:45:14 by aperez-b          #+#    #+#             */
/*   Updated: 2021/08/29 14:57:05 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/stack.h"

int	main(void)
{
	t_stack	*test;
	int		i;
	int		a;

	test = NULL;
	i = 1;
	while (i < 11)
	{
		a = 8 * i;
		if (!st_push(&test, (void *)&a, sizeof(int)))
		{
			ft_putstr_fd("Memory Allocation Error!\n", 1);
			return (1);
		}
		i++;
	}
	st_print(test);
	free(st_pop(&test));
	free(st_pop(&test));
	free(st_pop(&test));
	free(st_pop(&test));
	st_print(test);
	st_free(test);
	return (0);
}
