/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 10:45:14 by aperez-b          #+#    #+#             */
/*   Updated: 2021/09/02 21:03:33 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

static t_list	*st_parse(int argc, char **argv)
{
	t_list	*a;
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
			ft_lstclear(&a, free);
			ft_putstr_fd("Error\n", 1);
			return (NULL);
		}
		ft_lstadd_back(&a, st_newstack((void *)&content, sizeof(int)));
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	a = st_parse(argc, argv);
	if (!a)
		return (0);
	st_printstack_ab(a, b);
	ft_putstr_fd("Stack ordered: ", 1);
	ft_putnbr_fd(st_is_ordered(a), 1);
	ft_putstr_fd("\n\n", 1);
	st_order(&a, &b);
	ft_putstr_fd("\n\n", 1);
	st_printstack_ab(a, b);
	ft_putstr_fd("Stack ordered: ", 1);
	ft_putnbr_fd(st_is_ordered(a), 1);
	ft_putstr_fd("\n\n", 1);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
