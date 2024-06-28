/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:09:18 by rtaboada          #+#    #+#             */
/*   Updated: 2024/01/30 21:55:47 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*us1;
	unsigned char	*us2;

	if ((int)n < 0)
		return (-1);
	i = 0;
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (i < (int)n && us1[i] && us1[i] == us2[i])
		i++;
	if (i == (int)n)
		return (0);
	return (us1[i] - us2[i]);
}
