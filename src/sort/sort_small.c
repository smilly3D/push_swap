/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilly <smilly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:14:13 by smilly            #+#    #+#             */
/*   Updated: 2026/01/22 12:22:13 by smilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c && a > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	return ;
}

static void	aux_sort_five(t_stack **stack_a, t_stack **stack_b, int push_count)
{
	int	size;
	int	min_idx;
	int	i;

	i = 0;
	while (i < push_count)
	{
		size = list_size(*stack_a);
		min_idx = find_min_index(*stack_a);
		if (min_idx <= size / 2)
		{
			while (min_idx-- > 0)
				ra(stack_a);
		}
		else
		{
			min_idx = size - min_idx;
			while (min_idx-- > 0)
				rra (stack_a);
		}
		pb(stack_a, stack_b);
		i++;
	}
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	push_count;

	push_count = list_size(*stack_a) - 3;
	if (push_count <= 0)
		push_count = 0;
	aux_sort_five(stack_a, stack_b, push_count);
	sort_three(stack_a);
	i = 0;
	while (i < push_count)
	{
		pa(stack_a, stack_b);
		i++;
	}
}
