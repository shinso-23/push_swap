/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagodim <aagodim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 06:54:04 by aagodim           #+#    #+#             */
/*   Updated: 2025/02/16 16:30:04 by aagodim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_list *stack)
{
	if (stack == NULL)
		return (1);
	if (!stack)
		return (1);
	else
		return (0);
}

void	swap_top_stack(t_list **stack, char stack_move)
{
	t_list	*current;
	t_list	*next_current;
	int		temp;

	if (is_empty(*stack) || !((*stack)->next))
		return ;
	current = *stack;
	next_current = (*stack)->next;
	temp = current->content;
	current->content = next_current->content;
	next_current->content = temp;
	if (stack_move == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	push_element(t_list **stack_src, t_list **stack_dest, char stack_move)
{
	t_list	*current;

	if (is_empty(*stack_src))
		return ;
	current = *stack_src;
	*stack_src = (*stack_src)->next;
	current->next = *stack_dest;
	*stack_dest = current;
	if (stack_move == 'b')
		write(1, "pb\n", 3);
	else
		write(1, "pa\n", 3);
}

void	rotate_stack(t_list **stack, char stack_move)
{
	t_list	*current;
	t_list	*temp;

	if (is_empty(*stack) || !(*stack)->next)
		return ;
	current = *stack;
	temp = *stack;
	while (current->next)
		current = current->next;
	current->next = temp;
	(*stack) = (*stack)->next;
	temp->next = NULL;
	if (stack_move == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	reverse_rotate_stack(t_list **stack, char stack_move)
{
	t_list	*current;
	t_list	*temp;

	if (is_empty(*stack) || !(*stack)->next)
		return ;
	current = *stack;
	temp = *stack;
	while (current->next)
		current = current->next;
	while (temp->next->next)
		temp = temp->next;
	current->next = *stack;
	*stack = current;
	temp->next = NULL;
	if (stack_move == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}
