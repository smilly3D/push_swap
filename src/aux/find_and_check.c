/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilly <smilly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:49:15 by smilly            #+#    #+#             */
/*   Updated: 2026/01/22 12:14:19 by smilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

int	find_min(t_stack *head)
{
	int	min;

	if (!head)
		return (-1);
	min = head->value;
	while (head != NULL)
	{
		if (min > head->value)
			min = head->value;
		head = head->next;
	}
	return (min);
}

int	find_max(t_stack *head)
{
	int	max;

	if (!head)
		return (0);
	max = head->value;
	while (head != NULL)
	{
		if (max < head->value)
			max = head->value;
		head = head->next;
	}
	return (max);
}

int	find_min_index(t_stack *head)
{
	int	min;
	int	min_index;
	int	i;

	if (!head)
		return (-1);
	min = head->value;
	min_index = 0;
	i = 0;
	while (head != NULL)
	{
		if (head->value < min)
		{
			min = head->value;
			min_index = i;
		}
		head = head->next;
		i++;
	}
	return (min_index);
}

int	is_sorted(t_stack *head)
{
	if (!head)
		return (1);
	while (head->next != NULL)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}
