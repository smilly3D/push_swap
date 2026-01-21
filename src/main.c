/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilly <smilly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:08:57 by smilly            #+#    #+#             */
/*   Updated: 2026/01/21 17:06:27 by smilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = parse_args(argc, argv);
	if (!stack_a)
		return (1);

	stack_b = NULL;


	if (is_sorted(stack_a))
	{
		free_list(stack_a);
		return (0);
	}

	sort_stack(&stack_a, &stack_b);
	free_list(stack_a);
	free_list(stack_b);

	return (0);
}
