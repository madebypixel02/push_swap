/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 10:45:14 by aperez-b          #+#    #+#             */
/*   Updated: 2021/09/01 13:55:08 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

static t_stack	*st_parse(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		content;

	a = NULL;
	i = 1;
	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 1);
		return (NULL);
	}
	while (i < argc)
	{
		if (ft_atoi2(argv[i++], &content) == -1 || \
			st_in_stack(a, (void *)&content, sizeof(int)))
		{
			st_freestack(&a);
			ft_putstr_fd("Error\n", 1);
			return (NULL);
		}
		st_push(&a, (void *)&content, sizeof(int));
		st_rotate_ab(&a);
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = st_parse(argc, argv);
	if (!a)
		return (0);
	st_printstack_ab(a, b);
	ft_putstr_fd("Stack ordered: ", 1);
	ft_putnbr_fd(st_is_ordered(a), 1);
	ft_putstr_fd("\n\n", 1);
	st_order(a, b);
	st_printstack_ab(a, b);
	st_freestack(&a);
	st_freestack(&b);
	return (0);
}
