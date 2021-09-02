/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 09:58:17 by aperez-b          #+#    #+#             */
/*   Updated: 2021/09/01 21:59:36 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/stack.h"

void	*st_pop(t_list **stack, int size)
{
	void	*out;
	t_list	*temp;

	out = NULL;
	if (!stack[0])
		return (NULL);
	temp = stack[0]->next;
	out = malloc(size);
	if (!out)
		return (NULL);
	ft_memcpy(out, stack[0]->content, size);
	ft_lstdelone(stack[0], free);
	*stack = temp->next;
	return (out);
}

int	st_push(t_list **stack, void *newcontent, size_t size)
{
	t_list	*new;

	new = st_newstack(newcontent, size);
	if (!new)
		return (0);
	ft_lstadd_front(stack, new);
	return (1);
}

t_list	*st_newstack(void *newcontent, size_t size)
{
	t_list	*new;
	void	*content;

	new = malloc(sizeof(t_list));
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
	return (new);
}

void	st_freestack(t_list **stack)
{
	t_list	*temp;

	temp = NULL;
	if (*stack)
	{
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
