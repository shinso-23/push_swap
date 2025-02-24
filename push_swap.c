/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagodim <aagodim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:40:08 by aagodim           #+#    #+#             */
/*   Updated: 2025/02/24 13:10:06 by aagodim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_validity(char *s)
{
	if (!s || !*s)
		return (0);
	if ((*s == '+' || *s == '-') && *(s + 1))
		s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int	check_duplication(t_list **head, int num)
{
	t_list	*current;

	current = *head;
	while (current)
	{
		if (current->content == num)
			return (1);
		current = current->next;
	}
	return (0);
}

t_list	*add_to_list(t_list **head, int num)
{
	t_list	*newnode;
	t_list	*current;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->content = num;
	newnode->next = NULL;
	if (!*head)
	{
		*head = newnode;
		return (newnode);
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = newnode;
	return (*head);
}

int	splitting_ag(t_list **head, char *s, t_sort *p)
{
	char	**result;
	int		i;
	int		num;

	i = 0;
	result = ft_split(s, ' ');
	if (!result || !*result)
		return (free_all(result), ft_putstr_fd("Error!", 2), -1);
	while (result[i])
	{
		if (ft_atoi_error(result[i]))
			return (free_all(result), ft_putstr_fd("Overflow!", 2), -1);
		if (!check_validity(result[i]))
			return (free_all(result), ft_putstr_fd("Invalid input!", 2), -1);
		num = ft_atoi(result[i]);
		if (check_duplication(head, num))
			return (free_all(result), ft_putstr_fd("Duplication!", 2), -1);
		(*head) = add_to_list(head, num);
		p->count++;
		i++;
	}
	free_all(result);
	return (p->count);
}

int	main(int ac, char **av)
{
	t_list	*head;
	t_list	*stack_b;
	t_sort	p;
	int		i;

	head = NULL;
	stack_b = NULL;
	i = 1;
	p.count = 0;
	if (ac < 2)
		return ((ft_putstr_fd("Short ON Arguments", 2)), 1);
	while (av[i])
	{
		p.count = splitting_ag(&head, av[i], &p);
		if (p.count == -1)
			return (list_remove(&head), 1);
		i++;
	}
	if (stack_sorted(&head))
		return (list_remove(&head), 0);
	do_operations(&head, &stack_b, p);
	list_remove(&head);
	return (0);
}
