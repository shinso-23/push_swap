/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagodim <aagodim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 06:48:33 by aagodim           #+#    #+#             */
/*   Updated: 2025/02/22 02:01:46 by aagodim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stddef.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

typedef struct s_sort
{
	int	start;
	int	end;
	int	count;
	int	max;
	int	index_max;
	int	current_index;
}	t_sort;

int		is_empty(t_list *stack);
void	swap_top_stack(t_list **stack, char stack_move);
void	push_element(t_list **stack_src, t_list **stack_dest, char stack_move);
void	rotate_stack(t_list **stack, char stack_move);
void	reverse_rotate_stack(t_list **stack, char stack_move);
void	ss(t_list **stack_src, t_list **stack_dest);
void	rr(t_list **stack_src, t_list **stack_dest);
void	rrr(t_list **stack_src, t_list **stack_dest);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	sort_five(t_list **head, t_list **stack_b);
void	sort_four(t_list **head, t_list **stack_b);
void	sort_three(t_list **head);
void	do_operations(t_list **head, t_list	**stack_b, t_sort p);
int		ft_lstsize(t_list *lst);
void	algo_sort(t_list **head, t_list **stack_b, t_sort p);
void	free_all(char **s);
int		*arr_push(t_list **head, t_sort p);
int		*arr_sort(t_sort p, int *arr);
void	push_to_b(t_list **head, t_list **stack_b, int *arr, t_sort p);
void	push_to_a(t_list **head, t_list **stack_b, t_sort p);
void	do_this(t_sort p, t_list **stack_b, t_list **head);
void	list_remove(t_list **lst);

#endif