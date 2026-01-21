/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilly <smilly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:32:53 by smilly            #+#    #+#             */
/*   Updated: 2026/01/21 14:33:52 by smilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

static void	swap_stack(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	curr = *stack;
	tmp = curr->next;
	curr->next = tmp->next;
	tmp->next = curr;
	*stack = tmp;
}

void	sa(t_stack **stack_a)
{
	swap_stack(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	swap_stack(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
	write(1, "ss\n", 3);
}
