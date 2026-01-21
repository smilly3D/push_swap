/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilly <smilly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:31:41 by smilly            #+#    #+#             */
/*   Updated: 2026/01/21 16:45:50 by smilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	*stack_to_array(t_stack *stack, int size)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		error_exit();
	i = 0;
	while (stack)
	{
		arr[i++] = stack->value;
		stack = stack->next;
	}
	return (arr);
}

static void	insertion_sort(int *arr, int size)
{
	int	i;
	int	key;
	int	j;

	i = 1;
	while (i < size)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}

static int	binary_search_int(const int *arr, int size, int target)
{
	int	low;
	int	high;
	int	mid;

	low = 0;
	high = size - 1;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (arr[mid] == target)
			return (mid);
		if (arr[mid] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (-1);
}

void	index_stack(t_stack *stack_a)
{
	int	size;
	int	*sorted;
	int	idx;
	int	original;

	size = list_size(stack_a);
	if (size <= 1)
		return ;
	sorted = stack_to_array(stack_a, size);
	insertion_sort(sorted, size);
	while (stack_a)
	{
		original = stack_a->value;
		idx = binary_search_int(sorted, size, original);
		if (idx < 0)
		{
			free(sorted);
			error_exit();
		}
		stack_a->value = idx;
		stack_a = stack_a->next;
	}
	free(sorted);
}
