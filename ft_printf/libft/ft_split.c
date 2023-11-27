/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:24:52 by lmicheli          #+#    #+#             */
/*   Updated: 2023/11/27 12:01:39 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static int	count_split_words(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
		{
			i++;
		}
		if (s[i] != c && s[i])
		{
			words++;
			i++;
			while (s[i] != c && s[i])
			{
				i++;
			}
		}
	}
	return (words);
}

static int	ft_chkrow(char **mtx, char *row)
{
	int	i;

	i = 0;
	if (!row)
	{
		while (mtx[i])
		{
			free(mtx[i]);
			i++;
		}
		free(mtx);
		return (0);
	}
	return (1);
}

static size_t	ft_lencalc(char *s, char c)
{
	size_t	len;

	if (!ft_strchr(s, c))
		len = ft_strlen(s);
	else
		len = ft_strchr(s, c) - s;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	len;
	size_t	i;

	i = 0;
	array = (char **)malloc(sizeof(char *) * (count_split_words(s, c) + 1));
	if (!array)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			len = ft_lencalc((char *)s, c);
			array[i] = ft_substr(s, 0, len);
			if (ft_chkrow(array, array[i++]) == 0)
				return (NULL);
			s += len;
		}
	}
	array[i] = NULL;
	return (array);
}
/*
static char	*create_sub_str(int start, char const *s, cha#define NULL ((void*)0)
r c)
{
	size_t		sub_str_len;
	size_t		i;
	char		*new_string;

	sub_str_len = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[start + sub_str_len] != c && s[start + sub_str_len] != '\0')
		sub_str_len++;
	new_string = (char *)malloc((sub_str_len + 1) * sizeof(char));
	if (new_string == NULL)
		return (NULL);
	while (i < sub_str_len)
	{
		new_string[i] = s[start + i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

static int	str_count(const char *s, char c)
{
	int		number_of_strings;
	int		start;

	start = 0;
	number_of_strings = 0;
	if (s == NULL)
		return (0);
	while (s[start])
	{
		if (s[start] != c)
		{
			number_of_strings++;
			while (s[start] != c && s[start])
				start++;
			start--;
		}
		if (s[start] == '\0')
			return (number_of_strings);
		start++;
	}
	return (number_of_strings);
}

char	**ft_split(char const *s, char c)
{
	int		number_of_str;
	int		pos_matrix;
	int		start;
	char	**matrix;

	number_of_str = str_count(s, c);
	pos_matrix = 0;
	start = 0;
	matrix = (char **)malloc((number_of_str + 1) * sizeof(char *));
	if (matrix == NULL)
		return (NULL);
	while (pos_matrix < number_of_str)
	{
		while (s[start] == c)
			start++;
		matrix[pos_matrix] = create_sub_str(start, s, c);
		if (matrix[pos_matrix] == NULL)
			return (NULL);
		while (s[start] != c && s[start] != '\0')
			start++;
		pos_matrix++;
	}
	matrix[pos_matrix] = NULL;
	return (matrix);
}

int main()
{
	char	*input = "   lorem\""
	char	**result = ft_split(input, 32);

	if (result)
	{
		for (int i = 0; result[i] != NULL; i++)
		{
			printf("Part %d: %s\n", i, result[i]);
		}
	}
	return (0);
}*/