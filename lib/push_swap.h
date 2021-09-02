/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 10:55:09 by aperez-b          #+#    #+#             */
/*   Updated: 2021/09/01 21:19:04 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "stack.h"

/* Starts ordering stack */
int		st_order(t_list **a, t_list **b);

/* Returns middle number in a stack (to split numbers) */
int		st_get_mid(t_list *stack);

/* moves elements up to mid to stack b, ordering if necessary */
void	st_split(t_list **a, t_list **b, int mid);

#endif
