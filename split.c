/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagodim <aagodim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:55:32 by aagodim           #+#    #+#             */
/*   Updated: 2025/02/15 20:58:14 by aagodim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	checkalloc(char **t, int i, int size)
{
	int	j;

	j = 0;
	t[i] = malloc(size);
	if (t[i] == NULL)
	{
		while (j < i)
			free(t[j++]);
		free(t);
		return (1);
	}
	return (0);
}

static int	allocate(char **t, char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			s++;
			len++;
		}
		if (len)
		{
			if (checkalloc(t, i, len + 1))
				return (1);
			ft_strlcpy(t[i], s - len, len + 1);
		}
		i++;
	}
	return (0);
}

static int	ft_countw(char const *s, char c)
{
	int	w;
	int	d;

	w = 0;
	while (*s)
	{
		d = 1;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			if (d)
			{
				d = 0;
				w++;
			}
			s++;
		}
	}
	return (w);
}

char	**ft_split(char const *s, char c)
{
	char	**t;
	int		w;

	if (!s)
		return (NULL);
	w = ft_countw(s, c);
	t = malloc(sizeof(char *) * (w + 1));
	if (!t)
		return (NULL);
	t[w] = NULL;
	if (allocate(t, s, c))
		return (NULL);
	return (t);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (size)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}
