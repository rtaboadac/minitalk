/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:32:50 by rtaboada          #+#    #+#             */
/*   Updated: 2024/02/08 21:21:16 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>

static void	ft_freearr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr[i]);
	free(arr);
}

static size_t	ft_arrlen(char **arr)
{
	if (!arr || !*arr)
		return (0);
	return (1 + ft_arrlen(&arr[1]));
}

static char	*ft_getword(char const *str, char wordend, char ***arr)
{
	size_t	i;
	char	*word;

	i = 0;
	while (str[i] && (unsigned char)str[i] != (unsigned char)wordend)
		i++;
	if (i == 0)
		return (NULL);
	word = ft_substr(str, 0, i);
	if (!word)
	{
		ft_freearr(*arr);
		*arr = NULL;
		return (NULL);
	}
	return (word);
}

static char	**ft_arradd(char **arr, char *str)
{
	char	**aux;
	int		new_size;
	int		i;

	new_size = ft_arrlen(arr) + 2;
	aux = (char **)malloc(sizeof(char *) * new_size);
	if (!aux)
	{
		free(str);
		ft_freearr(arr);
		return (NULL);
	}
	i = 0;
	while (arr[i])
	{
		aux[i] = arr[i];
		i++;
	}
	aux[new_size - 2] = str;
	aux[new_size - 1] = NULL;
	free(arr);
	arr = aux;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	size_t	s_l;
	char	*word;

	i = 0;
	res = (char **)malloc(sizeof(char *));
	if (!res)
		return (NULL);
	*res = NULL;
	s_l = ft_strlen(s);
	while (i < (int)s_l && s[i] && res)
	{
		word = ft_getword(&s[i], c, &res);
		if (!res)
			return (NULL);
		i++;
		if (!word)
			continue ;
		res = ft_arradd(res, word);
		if (!res)
			return (NULL);
		i += ft_strlen(word);
	}
	return (res);
}
