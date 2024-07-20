/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:49:23 by rtaboada          #+#    #+#             */
/*   Updated: 2024/02/07 19:51:41 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int				i;
	unsigned int	end;
	char			*sub;

	end = ft_strlen(s);
	if (start > end || (int)start < 0)
		end = start;
	if ((int)start >= 0 && start + len < (size_t)end)
		end = start + len;
	sub = (char *)malloc(((end - start) + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while ((size_t)i < len && (i + start) < end)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
