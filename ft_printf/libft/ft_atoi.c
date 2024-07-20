/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:06:08 by rtaboada          #+#    #+#             */
/*   Updated: 2024/01/21 20:41:56 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>

static int	ft_numlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (i);
		i++;
	}
	return (i);
}

static int	ft_isblank(int c)
{
	return (c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
	);
}

static int	ft_issymbol(int c)
{
	return (c == '+' || c == '-');
}

static int	ft_isvalid(const char *str)
{
	int		i;
	char	prev;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (1);
		if ((ft_isblank(str[i]) || ft_issymbol(str[i]))
			&& i > 0
			&& ft_issymbol(prev))
			return (0);
		prev = str[i];
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	n;
	int	zeros;

	if (!ft_isvalid(str))
		return (0);
	if (ft_isblank(*str) || *str == '+')
		return (ft_atoi(&str[1]));
	if (*str == '-')
		return (-ft_atoi(&str[1]));
	if (!ft_isdigit(*str))
		return (0);
	zeros = ft_numlen(str) - 1;
	n = *str - 48;
	if (zeros == 0)
		return (n);
	while (zeros > 0 && n > 0)
	{
		n *= 10;
		zeros--;
	}
	return (n + ft_atoi(&str[1]));
}
