/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 10:45:14 by aperez-b          #+#    #+#             */
/*   Updated: 2021/09/19 17:04:10 by aperez-b         ###   ########.fr       */
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
			st_find(*a, (void *)&content, sizeof(int)) != -1)
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

	b = NULL;
	a = st_parse(argc, argv);
	if (!a)
		return (0);
	st_order(&a, &b);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
