/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <aperez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 20:37:34 by aperez-b          #+#    #+#             */
/*   Updated: 2021/09/17 17:06:34 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"
#include <stddef.h>

int	st_is_ordered(t_list *a, t_list *b)
{
	void	*prev;

	prev = NULL;
	if (!a || b)
		return (0);
	while (a)
	{
		if (prev && *(int *)prev > *(int *)a->content)
			return (0);
		prev = a->content;
		a = a->next;
	}
	return (1);
}

int	st_to_top(t_list **a, t_list **b, void *content, char c)
{
	int		pos;
	void	*aux;

	aux = malloc(sizeof(int));
	if (!aux)
		return (0);
	ft_memcpy(aux, content, sizeof(int));
	pos = st_find(*a, content, sizeof(int));
	if (*(int *)a[0]->content != *(int *)aux && pos != -1)
	{
		while (ft_memcmp(aux, a[0]->content, sizeof(int)))
		{
			if (pos > (ft_lstsize(*a) - 1) / 2)
				st_rrotate_ab(a, b, c);
			else
				st_rotate_ab(a, b, c);
		}
	}
	free(aux);
	return (0);
}

void	st_translate(t_list **stack)
{
	t_list	*aux;
	int		len;
	int		i;
	int		content;

	i = 0;
	content = 0;
	aux = NULL;
	len = ft_lstsize(*stack);
	while (i++ < len)
		ft_lstadd_front(&aux, st_newstack((void *)&content, sizeof(int)));
	i = 0;
	content = *(int *)st_max(*stack)->content + 1;
	while (i < len)
	{
		st_replace_at(&aux, st_find(*stack, st_min(*stack)->content, \
			sizeof(int)), (void *)&i, sizeof(int));
		st_replace_at(stack, st_find(*stack, st_min(*stack)->content, \
			sizeof(int)), (void *)&content, sizeof(int));
		i++;
		content++;
	}
	ft_lstclear(stack, free);
	st_printstack_ab(aux, NULL, "0123456789");
	*stack = aux;
}
