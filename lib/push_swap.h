/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 10:55:09 by aperez-b          #+#    #+#             */
/*   Updated: 2021/09/19 12:18:52 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "stack.h"

/* Translates elements from a stack such that the min element is 0 */
void	st_translate(t_list **stack);

/* Starts ordering stack */
int		st_order(t_list **a, t_list **b);

/* Sorts in least moves for three numbers */
void	st_sort_small(t_list **a, t_list **b);

/* Returns middle number in a stack (to split numbers) */
int		st_get_mid(t_list *stack);

/* moves elements up to mid to stack b, ordering if necessary */
void	st_split(t_list **a, t_list **b, int mid, int *count);

/* Recursively uses bitwise radix sort algorithm to sort a */
int		st_radix_sort(t_list **a, t_list **b, int max_len, int right_shift);

#endif
