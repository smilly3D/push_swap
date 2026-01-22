/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilly <smilly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:15:45 by smilly            #+#    #+#             */
/*   Updated: 2026/01/22 12:15:15 by smilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	index_of_value(t_stack *stack, int value)
{
	int	idx;

	idx = 0;
	while (stack)
	{
		if (stack->value == value)
			return (idx);
		idx++;
		stack = stack->next;
	}
	return (-1);
}

static int	chunk_size_for(int n)
{
	if (n <= 20)
		return (5);
	if (n <= 100)
		return (20);
	if (n <= 500)
		return (45);
	return (60);
}

static void	pre_order_stack_b(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	low;
	int	high;
	int	top;

	low = 0;
	high = chunk_size_for(size);
	while (*stack_a)
	{
		top = (*stack_a)->value;
		if (top < low)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			low++;
			high++;
		}
		else if (top < high)
		{
			pb(stack_a, stack_b);
			low++;
			high++;
		}
		else
			ra(stack_a);
	}
}

static void	order_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	int	max;
	int	pos;
	int	size;

	while (*stack_b)
	{
		size = list_size(*stack_b);
		max = find_max(*stack_b);
		pos = index_of_value(*stack_b, max);
		if (pos < 0)
			error_exit();
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				rb(stack_b);
		}
		else
		{
			pos = size - pos;
			while (pos-- > 0)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}

void	sort_chunks(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (!stack_a || !*stack_a)
		return ;
	if (is_sorted(*stack_a))
		return ;
	size = list_size(*stack_a);
	pre_order_stack_b(stack_a, stack_b, size);
	order_stack_a(stack_a, stack_b);
}
