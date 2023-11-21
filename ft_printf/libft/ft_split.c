/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:24:52 by lmicheli          #+#    #+#             */
/*   Updated: 2023/11/21 15:59:36 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	**free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (0);
}

static int	ft_clines(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_putword(char *nword, char const *s, int i, int cchar)
{
	int	j;

	j = 0;
	while (cchar > 0)
	{
		nword[j] = s[i - cchar];
		j++;
		cchar--;
	}
	nword[j] = '\0';
	return (nword);
}

static char	**ft_enter(char const *s, char c, char **s2, int clines)
{
	int	i;
	int	nword;
	int	cchar;

	i = 0;
	nword = 0;
	cchar = 0;
	while (nword < clines)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			cchar++;
		}
		s2[nword] = (char *)malloc(sizeof(char) * (cchar + 1));
		if (!s2)
			return (free_array(s2, nword));
		ft_putword(s2[nword], s, i, cchar);
		cchar = 0;
		nword++;
	}
	s2[nword] = 0;
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	char			**s2;
	unsigned int	clines;

	if (!s)
		return (0);
	clines = ft_clines(s, c);
	s2 = (char **)malloc(sizeof(char *) * (clines + 1));
	if (!s2)
		return (0);
	s2 = ft_enter(s, c, s2, clines);
	return (s2);
}
/*
static char	*create_sub_str(int start, char const *s, char c)
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

/*int main()
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