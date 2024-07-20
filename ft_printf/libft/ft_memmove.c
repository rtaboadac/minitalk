/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:28:59 by rtaboada          #+#    #+#             */
/*   Updated: 2024/01/21 21:28:05 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	if ((char *)dest > (char *)src)
	{
		while (len--)
			((char *)dest)[len] = ((char *)src)[len];
		return (dest);
	}
	return (ft_memcpy(dest, src, len));
}
