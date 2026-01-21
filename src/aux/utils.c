/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilly <smilly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:02:06 by smilly            #+#    #+#             */
/*   Updated: 2026/01/21 17:06:29 by smilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

t_stack	*create_node(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;

	return (new_node);
}

int	list_size(t_stack *head)
{
	int		count;
	t_stack	*current;

	count = 0;
	current = head;
	while (current != NULL)
	{
		current = current->next;
		count++;
	}

	return (count);
}

void	free_list(t_stack *head)
{
	t_stack	*next_point;

	while (head != NULL)
	{
		next_point = head->next;
		free(head);
		head = next_point;
	}

}

void	push_back(t_stack **head, int value)
{
	t_stack	*new_node;
	t_stack	*current;

	current = *head;

	new_node = create_node(value);
	if (!new_node)
		return ;

	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}

	while (current->next != NULL)
	{
		current = current->next;
	}

	current->next = new_node;
}
