/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:44:36 by rtaboada          #+#    #+#             */
/*   Updated: 2024/01/21 21:37:47 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	size_t	s1_l;
	size_t	s2_l;
	size_t	res_l;
	char	*res;

	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	res_l = s1_l + s2_l;
	res = malloc(sizeof(char) * (res_l + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < (int)res_l)
	{
		if (i < (int)s1_l)
			res[i] = s1[i];
		else
			res[i] = s2[i - s1_l];
		i++;
	}
	res[i] = '\0';
	return (res);
}
