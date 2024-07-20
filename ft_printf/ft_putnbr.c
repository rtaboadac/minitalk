/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:27:21 by rtaboada          #+#    #+#             */
/*   Updated: 2024/06/21 22:26:59 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_negative(int *n, t_modifier modifier)
{
	int	len;

	len = 0;
	if (*n < 0)
	{
		if (modifier.precision < 0)
			len = write(1, "-", 1);
		*n = -*n;
	}
	return (len);
}

static void	fill_buffer(int n, char *buffer, int *i)
{
	if (n == 0)
	{
		buffer[(*i)++] = '0';
	}
	else
	{
		while (n)
		{
			buffer[(*i)++] = (n % 10) + '0';
			n /= 10;
		}
	}
}

int	ft_putnbr(int n, t_modifier modifier)
{
	char	buffer[11];
	int		len;
	int		i;

	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	len = handle_negative(&n, modifier);
	i = 0;
	fill_buffer(n, buffer, &i);
	if (modifier.precision > i && len > -1 && ft_putnchar('0',
			modifier.precision - i) > -1)
		len += modifier.precision - i;
	while (i-- && len > -1)
	{
		if (write(1, &buffer[i], 1) > -1)
			len++;
		else
			return (-1);
	}
	return (len);
}
