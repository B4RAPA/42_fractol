/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:12:59 by lfabel            #+#    #+#             */
/*   Updated: 2024/06/19 13:47:52 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c);
static void	*ft_free(char **str, int count);
static char	*fill_word(const char *s, int start, int end);

static void	ft_vars(size_t *i, int *j, int *start)
{
	*j = 0;
	*start = -1;
	*i = 0;
}

char	**ft_split(const char *s, char c)
{
	char	**dest;
	size_t	i;
	int		start;
	int		j;

	ft_vars(&i, &j, &start);
	dest = ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!dest)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			dest[j] = fill_word(s, start, i);
			if (!dest[j])
				return (ft_free(dest, j));
			start = -1;
			j++;
		}
		i++;
	}
	return (dest);
}

static int	word_count(const char *s, char c)
{
	int	i;
	int	k;
	int	count;

	i = 0;
	k = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && k == 0)
		{
			k = 1;
			count++;
		}
		if (s[i] == c)
			k = 0;
		i++;
	}
	return (count);
}

static void	*ft_free(char **str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static char	*fill_word(const char *s, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc (sizeof(char) * end - start + 1);
	if (!word)
		return (0);
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}
