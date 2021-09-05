/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <aperez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 22:43:00 by aperez-b          #+#    #+#             */
/*   Updated: 2021/09/05 22:43:02 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/stack.h"

void	*st_pop(t_list **stack)
{
	void	*out;
	t_list	*head;

	out = NULL;
	if (!stack || !stack[0])
		return (NULL);
	head = *stack;
	if (head->next)
	{
		*stack = head->next;
		out = head->content;
		free(head);
		return (out);
	}
	out = head->content;
	free(head);
	*stack = NULL;
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
