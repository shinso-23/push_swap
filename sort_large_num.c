/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagodim <aagodim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:19:25 by aagodim           #+#    #+#             */
/*   Updated: 2025/02/22 01:53:18 by aagodim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*arr_push(t_list **head, t_sort p)
{
	t_list	*tmp;	
	int		*arr;
	int		i;

	i = 0;
	arr = malloc(sizeof(int) * p.count);
	if (!arr)
		return (NULL);
	tmp = *head;
	while (tmp)
	{
		arr[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	return (arr);
}

int	*arr_sort(t_sort p, int *arr)
{
	int	i;
	int	j;
	int	swap;

	i = 0;
	j = 0;
	while (i < p.count - 1)
	{
		j = i + 1;
		while (j < p.count)
		{
			if (arr[i] > arr[j])
			{
				swap = arr[i];
				arr[i] = arr[j];
				arr[j] = swap;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

void	push_to_b(t_list **head, t_list **stack_b, int *arr, t_sort p)
{
	while ((*head))
	{
		if ((*head)->content <= arr[p.start])
		{
			push_element(head, stack_b, 'b');
			rotate_stack(stack_b, 'b');
			if (p.start < p.count - 1)
				p.start++;
			if (p.end < p.count - 1)
				p.end++;
		}
		else if ((*head)->content <= arr[p.end])
		{
			push_element(head, stack_b, 'b');
			if ((*head)->content < (*stack_b)->content)
				swap_top_stack(stack_b, 'b');
			if (p.start < p.count - 1)
				p.start++;
			if (p.end < p.count - 1)
				p.end++;
		}
		else
			rotate_stack(head, 'a');
	}
	free(arr);
}

void	push_to_a(t_list **head, t_list **stack_b, t_sort p)
{
	t_list	*new;

	p.current_index = 0;
	p.index_max = 0;
	while (*stack_b)
	{
		new = *stack_b;
		p.max = (*stack_b)->content;
		while (new)
		{
			if (p.max < new->content)
			{
				p.max = new->content;
				p.index_max = p.current_index;
			}
			p.current_index++;
			new = new->next;
		}
		do_this(p, stack_b, head);
		p.current_index = 0;
		p.index_max = 0;
		p.count--;
	}
}

void	do_this(t_sort p, t_list **stack_b, t_list **head)
{
	if (p.index_max > p.count / 2)
	{
		p.index_max = p.count - p.index_max;
		while (p.index_max--)
			reverse_rotate_stack(stack_b, 'b');
		p.index_max = 0;
		p.current_index = 0;
	}
	else
	{
		while (p.index_max--)
			rotate_stack(stack_b, 'b');
		p.index_max = 0;
		p.current_index = 0;
	}
	push_element(stack_b, head, 'a');
}
