/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:46:15 by roberto           #+#    #+#             */
/*   Updated: 2024/01/18 18:52:39 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_bzero(void *s, size_t n)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < (int)n)
	{
		str[i] = 0;
		i++;
	}
	return (s);
}
