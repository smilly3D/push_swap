/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilly <smilly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:35:49 by smilly            #+#    #+#             */
/*   Updated: 2026/01/21 14:43:56 by smilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

static void	push_stack(t_stack **top_src, t_stack **top_dest)
{
	t_stack	*node;
	t_stack	*next_top;

	if (!top_src || !*top_src || !top_dest)
		return ;

	node = *top_src;
	next_top = node->next;

	node->next = *top_dest;
	*top_dest = node;
	*top_src = next_top;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push_stack(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push_stack(stack_a, stack_b);
	write(1, "pb\n", 3);
}
