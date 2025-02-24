/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagodim <aagodim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:40:10 by aagodim           #+#    #+#             */
/*   Updated: 2025/02/23 21:32:13 by aagodim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_operations(t_list **head, t_list	**stack_b, t_sort p)
{
	t_list	*current;
	int		first;
	int		second;

	current = *head;
	if (p.count == 2)
	{
		first = current->content;
		second = current->next->content;
		if (first > second)
			swap_top_stack(head, 'a');
	}
	else if (p.count == 3)
		sort_three(head);
	else if (p.count == 4)
		sort_four(head, stack_b);
	else if (p.count == 5)
		sort_five(head, stack_b);
	else
		algo_sort(head, stack_b, p);
	current = *head;
}

void	sort_three(t_list **head)
{
	int	first;
	int	second;
	int	three;

	first = (*head)->content;
	second = (*head)->next->content;
	three = (*head)->next->next->content;
	if (first < second && second > three)
	{
		reverse_rotate_stack(head, 'a');
		if ((*head)->content > (*head)->next->content)
			swap_top_stack(head, 'a');
	}
	else if (first < three && first > second)
		swap_top_stack(head, 'a');
	else if (first > second && second < three)
		rotate_stack(head, 'a');
	else if (first > three)
	{
		swap_top_stack(head, 'a');
		reverse_rotate_stack(head, 'a');
	}
}

void	sort_four(t_list **head, t_list **stack_b)
{
	t_list	*current;
	int		min;

	current = *head;
	min = current->content;
	while (current)
	{
		if (current->content <= min)
			min = current->content;
		current = current->next;
	}
	while ((*head)->content != min)
		rotate_stack(head, 'a');
	push_element(head, stack_b, 'b');
	sort_three(head);
	push_element(stack_b, head, 'a');
}

void	sort_five(t_list **head, t_list **stack_b)
{
	t_list	*current;
	int		min;

	current = *head;
	min = current->content;
	while (current)
	{
		if (current->content < min)
			min = current->content;
		else
			current = current->next;
	}
	while ((*head)->content != min)
		rotate_stack(head, 'a');
	push_element(head, stack_b, 'b');
	sort_four(head, stack_b);
	push_element(stack_b, head, 'a');
}

void	algo_sort(t_list **head, t_list **stack_b, t_sort p)
{
	int		*arr;

	p.start = 0;
	if (p.count > 5 && p.count <= 100)
	{
		p.end = p.count / 6;
		arr = arr_push(head, p);
		arr = arr_sort(p, arr);
	}
	else
	{
		p.end = p.count / 11;
		arr = arr_push(head, p);
		arr = arr_sort(p, arr);
	}
	push_to_b(head, stack_b, arr, p);
	push_to_a(head, stack_b, p);
}
