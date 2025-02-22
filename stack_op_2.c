/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagodim <aagodim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:56:47 by aagodim           #+#    #+#             */
/*   Updated: 2025/02/21 16:15:30 by aagodim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list **stack_src, t_list **stack_dest)
{
	swap_top_stack(stack_src, 'x');
	swap_top_stack(stack_dest, 'x');
	write(1, "ss\n", 3);
}

void	rr(t_list **stack_src, t_list **stack_dest)
{
	rotate_stack(stack_src, 'x');
	rotate_stack(stack_dest, 'x');
	write(1, "rr\n", 3);
}

void	rrr(t_list **stack_src, t_list **stack_dest)
{
	reverse_rotate_stack(stack_src, 'x');
	reverse_rotate_stack(stack_dest, 'x');
	write(1, "rrr\n", 3);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new -> next = *lst;
	*lst = new;
}

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		count++;
		lst = lst -> next;
	}
	return (count);
}
