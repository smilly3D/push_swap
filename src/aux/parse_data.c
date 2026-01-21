/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilly <smilly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:11:41 by smilly            #+#    #+#             */
/*   Updated: 2026/01/21 14:27:47 by smilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	is_number(char *str)
{
	int	i;

	if (!str || str[0] == '\0')
		return (0);

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);

	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi_overlow(char *str)
{
	long	result;
	int		i;
	int		sign;

	result = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');

		if ((sign == 1 && result > 2147483647)
			|| (sign == -1 && result > 2147483648))
			error_exit();
		i++;
	}
	return ((int)(result * sign));
}

int	has_duplicates(t_stack *stack)
{
	t_stack	*curr;
	t_stack	*follow;

	if (!stack)
		return (0);
	curr = stack;
	while (curr != NULL)
	{
		follow = curr->next;
		while (follow != NULL)
		{
			if (curr->value == follow->value)
				return (1);
			follow = follow->next;
		}
		curr = curr->next;
	}
	return (0);
}

t_stack	*parse_args(int argc, char **argv)
{
	int		i;
	t_stack	*output;

	i = 1;
	output = NULL;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			error_exit();
		push_back(&output, ft_atoi_overlow(argv[i]));
		i++;
	}
	if (has_duplicates(output))
		error_exit();

	return (output);
}
