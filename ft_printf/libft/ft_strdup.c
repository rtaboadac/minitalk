/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:43:58 by rtaboada          #+#    #+#             */
/*   Updated: 2024/01/21 20:44:05 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <errno.h>

char	*ft_strdup(const char *s1)
{
	int		s1_l;
	int		i;
	char	*dup;

	s1_l = ft_strlen(s1);
	dup = (char *)malloc(sizeof(char) * (s1_l + 1));
	if (!dup)
	{
		errno = ENOMEM;
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
