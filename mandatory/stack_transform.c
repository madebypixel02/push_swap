/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 16:30:04 by aperez-b          #+#    #+#             */
/*   Updated: 2021/09/02 21:10:24 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/stack.h"

void	st_swap_ab(t_list **stack, char c)
{
	void	*temp;

	if (ft_lstsize(*stack) > 1)
	{
		temp = stack[0]->content;
		stack[0]->content = stack[0]->next->content;
		stack[0]->next->content = temp;
	}
	if (c == 'a')
		ft_putstr_fd("sa\n", 1);
	if (c == 'b')
		ft_putstr_fd("sb\n", 1);
}

void	st_push_ab(t_list **a, t_list **b, char c)
{
	void	*temp;

	if (ft_lstsize(*b))
	{
		temp = st_pop(b, sizeof(int));
		st_push(a, temp, sizeof(int));
		free(temp);
	}
	if (c == 'a')
		ft_putstr_fd("pa\n", 1);
	if (c == 'b')
		ft_putstr_fd("pb\n", 1);
}

int	st_rotate_ab(t_list **stack, char c)
{
	void	*content;

	if (ft_lstsize(*stack) > 1)
	{
		content = st_pop(stack, sizeof(int));
		ft_lstadd_back(stack, ft_lstnew(content));
	}
	if (c == 'a')
		ft_putstr_fd("ra\n", 1);
	if (c == 'b')
		ft_putstr_fd("rb\n", 1);
	return (0);
}

int	st_rrotate_ab(t_list **stack, char c)
{
	void	*content;
	t_list	*temp;

	if (!stack[0])
		return (-1);
	temp = *stack;
	if (ft_lstsize(temp) > 1)
	{
		while (temp->next)
			temp = temp->next;
		content = temp->content;
		free(temp);
		temp = NULL;
		st_push(stack, content, sizeof(int));
		free(content);
	}
	if (c == 'a')
		ft_putstr_fd("rra\n", 1);
	if (c == 'b')
		ft_putstr_fd("rrb\n", 1);

	return (0);
}
