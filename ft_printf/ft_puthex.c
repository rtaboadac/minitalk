/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:00:58 by rtaboada          #+#    #+#             */
/*   Updated: 2024/06/23 17:44:17 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fill_hex_buffer(unsigned int num, char *buffer, int upper)
{
	char	*digits;
	int		i;
	char	val;

	digits = "0123456789abcdef";
	i = 0;
	if (num == 0)
		buffer[i++] = '0';
	else
	{
		while (num)
		{
			val = digits[num % 16];
			if (upper && ft_isalpha(val))
				val = ft_toupper(val);
			buffer[i++] = val;
			num /= 16;
		}
	}
	buffer[i] = '\0';
	return (i);
}

int	ft_puthex(unsigned int num, short int upper, t_modifier modifier)
{
	int		len;
	int		i;
	char	buffer[16];

	len = 0;
	i = fill_hex_buffer(num, buffer, upper);
	if (modifier.precision > i)
	{
		if (ft_putnchar('0', modifier.precision - i) < 0)
			return (-1);
		len += modifier.precision - i;
	}
	while (i-- > 0)
	{
		if (ft_putchar(buffer[i]) > -1)
			len++;
		else
			return (-1);
	}
	return (len);
}
