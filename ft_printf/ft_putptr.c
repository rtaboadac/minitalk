/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:06:45 by rtaboada          #+#    #+#             */
/*   Updated: 2024/06/24 19:01:30 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putptr(uintptr_t ptr)
{
	char	buffer[16];
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	if (ft_putstr("0x") < 0)
		return (-1);
	len += 2;
	while (ptr)
	{
		buffer[i] = "0123456789abcdef"[ptr % 16];
		ptr /= 16;
		i++;
	}
	while (i-- > 0)
	{
		if (write(1, &buffer[i], 1) > -1)
			len++;
		else
			return (-1);
	}
	return (len);
}
