/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 10:45:14 by aperez-b          #+#    #+#             */
/*   Updated: 2021/09/08 18:08:12 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"
#include <stdio.h>

static int	st_check_value(char *argv, t_list **a)
{
	int		j;
	long	content;

	j = 0;
	while (argv[j])
	{
		if (ft_atoi2(&argv[j], &content) == -1 || \
			st_in_stack(*a, (void *)&content, sizeof(int)))
		{
			ft_lstclear(a, free);
			ft_putstr_fd("Error\n", 1);
			return (-1);
		}
		ft_lstadd_back(a, st_newstack((void *)&content, sizeof(int)));
		while (ft_isspace(argv[j]))
			j++;
		j += ft_strchr("+-", argv[j]) != 0;
		while (ft_isdigit(argv[j]))
			j++;
	}
	return (0);
}

static t_list	*st_parse(int argc, char **argv)
{
	t_list	*a;
	int		i;

	a = NULL;
	i = 0;
	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 1);
		return (NULL);
	}
	while (++i < argc)
	{
		if (st_check_value(argv[i], &a) == -1)
			return (NULL);
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		count;

	count = 0;
	b = NULL;
	a = st_parse(argc, argv);
	if (!a)
		return (0);
	st_printstack_ab(a, b);
	ft_putstr_fd("Stack ordered: ", 1);
	ft_putnbr_fd(st_is_ordered(a, b), 1);
	ft_putstr_fd("\n\n", 1);
	st_order(&a, &b, &count);
	ft_putstr_fd("\n", 1);
	st_printstack_ab(a, b);
	ft_putstr_fd("Stack ordered: ", 1);
	ft_putnbr_fd(st_is_ordered(a, b), 1);
	printf("\n\nSteps: %d\n", count);
	ft_putstr_fd("\n\n", 1);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
