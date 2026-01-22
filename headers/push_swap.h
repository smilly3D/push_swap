/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilly <smilly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:35:56 by smilly            #+#    #+#             */
/*   Updated: 2026/01/22 12:20:51 by smilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

//parse_data
int		is_number(char *str);
int		ft_atoi_overlow(char *str);
int		has_duplicates(t_stack *stack);
t_stack	*parse_args(int argc, char **argv);
void	error_exit(void);

//utils
t_stack	*create_node(int value);
void	push_back(t_stack **head, int value);
// void	print_list(t_stack *head);
int		list_size(t_stack *head);
void	free_list(t_stack *head);

//moves functions
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

//find & check
int		find_min(t_stack *head);
int		find_max(t_stack *head);
int		find_min_index(t_stack *head);
int		is_sorted(t_stack *head);

//sort_small
void	sort_three(t_stack **stack_a);
void	sort_five(t_stack **stack_a, t_stack **stack_b);

//subject07_radix.c
void	index_stack(t_stack *stack_a);
void	sort_radix(t_stack **stack_a, t_stack **stack_b);

//subject07_chunks.c
void	sort_chunks(t_stack **stack_a, t_stack **stack_b);

//sort
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
#endif
