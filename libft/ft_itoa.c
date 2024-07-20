/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:50:04 by rtaboada          #+#    #+#             */
/*   Updated: 2024/01/21 21:23:05 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_numlen(long n)
{
	int	l;

	if (n == 0)
		return (1);
	l = 0;
	if (n < 0)
	{
		n = -n;
		l++;
	}
	while (n > 0)
	{
		n /= 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	int		len;
	long	ln;
	char	*res;

	ln = (long)n;
	len = ft_numlen(ln);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len--] = '\0';
	if (ln == 0)
		res[len] = '0';
	if (ln < 0)
	{
		res[0] = '-';
		ln = -ln;
	}
	while (ln)
	{
		res[len--] = (ln % 10) + '0';
		ln = ln / 10;
	}
	return (res);
}
