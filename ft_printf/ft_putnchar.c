/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:59:36 by rtaboada          #+#    #+#             */
/*   Updated: 2024/06/23 17:37:53 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnchar(char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (write(1, &c, 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}
