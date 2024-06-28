/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 20:25:25 by rtaboada          #+#    #+#             */
/*   Updated: 2024/06/21 19:55:30 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printer(const char *format, va_list *args)
{
	int			printed_chars;
	t_modifier	*modifier;

	printed_chars = 0;
	while (*format && printed_chars > -1)
	{
		if (*format == '%')
		{
			format++;
			modifier = create_modifier();
			if (!modifier)
				return (-1);
			format += parse_flags(&format, modifier);
			set_modifier(&format, modifier, args);
			print_element(*format, args, *modifier, &printed_chars);
			free_flags(&(modifier->flags));
			free(modifier);
		}
		else if (ft_putchar(*format) == -1)
			return (-1);
		else
			printed_chars++;
		format++;
	}
	return (printed_chars);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed_chars;

	va_start(args, format);
	printed_chars = ft_printer(format, &args);
	va_end(args);
	return (printed_chars);
}
