/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:41:18 by rtaboada          #+#    #+#             */
/*   Updated: 2024/01/30 22:01:52 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	size_t	needle_l;

	needle_l = ft_strlen(needle);
	if (needle_l == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && needle_l <= len--)
	{
		if (!ft_strncmp(&haystack[i], needle, needle_l))
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
