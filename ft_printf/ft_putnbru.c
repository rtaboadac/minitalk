/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:31:16 by rtaboada          #+#    #+#             */
/*   Updated: 2024/06/21 22:26:52 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fill_unsigned_buffer(unsigned int num, char *buffer)
{
	int	i;

	i = 0;
	if (num == 0)
	{
		buffer[i++] = '0';
	}
	else
	{
		while (num)
		{
			buffer[i++] = (num % 10) + '0';
			num /= 10;
		}
	}
	buffer[i] = '\0';
	return (i);
}

int	ft_putnbru(unsigned int num, t_modifier modifier)
{
	char	buffer[11];
	int		len;
	int		i;

	len = 0;
	i = fill_unsigned_buffer(num, buffer);
	if (modifier.precision > i && ft_putnchar('0', modifier.precision - i) > -1)
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
