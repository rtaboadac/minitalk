/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:42:18 by rtaboada          #+#    #+#             */
/*   Updated: 2024/06/23 17:27:32 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_flags(const char **format, t_modifier *modifier)
{
	int		count;
	t_flag	*flag;

	count = 0;
	flag = get_flag(modifier->flags, **format);
	while (flag)
	{
		flag->is_checked++;
		(*format)++;
		count++;
		flag = get_flag(modifier->flags, **format);
	}
	return (count);
}

int	parse_length(const char **format, va_list *args)
{
	int	len;

	len = 0;
	if (**format == '*')
		return ((*format)++, va_arg(*args, int));
	while (ft_isdigit(**format))
	{
		len = len * 10 + (**format - '0');
		(*format)++;
	}
	return (len);
}

int	parse_precision(const char **format, va_list *args)
{
	int	precision;

	precision = -1;
	if (**format == '.')
	{
		(*format)++;
		precision = 0;
		if (**format == '*')
			return ((*format)++, va_arg(*args, int));
		while (ft_isdigit(**format))
		{
			precision = precision * 10 + (**format - '0');
			(*format)++;
		}
	}
	return (precision);
}

void	set_modifier(const char **format, t_modifier *modifier, va_list *args)
{
	modifier->length = parse_length(format, args);
	modifier->precision = parse_precision(format, args);
}

void	print_element(char element, va_list *args, t_modifier modifier,
		int *printed_chars)
{
	int	len;

	len = -1;
	if (element == 'c')
		len = ft_putchar((char)va_arg(*args, int));
	else if (element == 's')
		len = ft_putstr(va_arg(*args, char *));
	else if (element == 'd' || element == 'i')
		len = ft_putnbr(va_arg(*args, int), modifier);
	else if (element == 'u')
		len = ft_putnbru(va_arg(*args, unsigned int), modifier);
	else if (element == 'x' || element == 'X')
		len = ft_puthex((unsigned int)va_arg(*args, unsigned int),
				element == 'X', modifier);
	else if (element == 'p')
		len = ft_putptr((uintptr_t)va_arg(*args, void *));
	else if (element == '%')
		len = ft_putchar('%');
	if (len > -1)
		*printed_chars += len;
	else
		*printed_chars = -1;
}
