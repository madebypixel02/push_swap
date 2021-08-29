/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 09:58:17 by aperez-b          #+#    #+#             */
/*   Updated: 2021/08/29 18:33:00 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/stack.h"

void	*st_pop(t_stack **stack)
{
	void	*out;

	if (!stack[0])
		return (NULL);
	out = stack[0]->content;
	if (stack[0]->next)
	{
		stack[0] = stack[0]->next;
		free(stack[0]->prev);
		stack[0]->prev = NULL;
	}
	else
	{
		free(stack[0]);
		stack[0] = NULL;
	}
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

void	st_freestack(t_stack **stack)
{
	t_stack	*temp;

	temp = NULL;
	if (*stack)
	{
		while (stack[0]->prev)
			stack[0] = stack[0]->prev;
		while (*stack)
		{
			temp = *stack;
			stack[0] = stack[0]->next;
			free(temp->content);
			free(temp);
			temp = NULL;
		}
	}
	*stack = NULL;
}
