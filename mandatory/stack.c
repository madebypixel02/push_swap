/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 09:58:17 by aperez-b          #+#    #+#             */
/*   Updated: 2021/08/29 14:24:10 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/stack.h"

void	*st_pop(t_stack **stack)
{
	void	*out;
	t_stack	*temp;

	temp = *stack;
	if (!temp)
		return (NULL);
	out = temp->content;
	if (temp->next)
		temp = temp->next;
	temp->prev = NULL;
	free(*stack);
	*stack = temp;
	return (out);
}

int	st_push(t_stack **stack, void *newcontent, size_t size)
{
	t_stack	*new;

	new = st_newstack(newcontent, size);
	if (!new)
		return (0);
	new->next = *stack;
	if (*stack)
		stack[0]->prev = new;
	*stack = new;
	return (1);
}

t_stack	*st_newstack(void *newcontent, size_t size)
{
	t_stack	*new;
	void	*content;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	content = malloc(size);
	if (!content)
	{
		free(new);
		return (NULL);
	}
	ft_memcpy(content, newcontent, size);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	st_free(t_stack *stack)
{
	t_stack	*temp;

	temp = NULL;
	if (stack)
	{
		while (stack->prev)
			stack = stack->prev;
		while (stack)
		{
			temp = stack;
			stack = stack->next;
			free(temp->content);
			free(temp);
			temp = NULL;
		}
	}
}

int	st_print(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
	{
		ft_putstr_fd("Empty or Missing Stack supplied!\n", 1);
		return (0);
	}
	temp = stack;
	while (temp->prev)
		temp = temp->prev;
	while (temp)
	{
		ft_putnbr_fd(*(int *)temp->content, 1);
		write(1, "\n", 1);
		temp = temp->next;
	}
	write(1, "\n", 1);
	return (0);
}
