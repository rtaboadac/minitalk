/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modifier_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:21:47 by rtaboada          #+#    #+#             */
/*   Updated: 2024/06/21 19:52:23 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	*create_flag(char type)
{
	t_flag	*new_flag;

	new_flag = (t_flag *)malloc(sizeof(t_flag));
	if (!new_flag)
		return (NULL);
	new_flag->type = type;
	new_flag->is_checked = 0;
	new_flag->next = NULL;
	return (new_flag);
}

void	add_flag(t_modifier *modifier, t_flag *new_flag)
{
	t_flag	*current_flag;

	if (!modifier->flags)
		modifier->flags = new_flag;
	else
	{
		current_flag = modifier->flags;
		while (current_flag->next)
			current_flag = current_flag->next;
		current_flag->next = new_flag;
	}
}

t_flag	*get_flag(t_flag *flags, char type)
{
	t_flag	*curr;

	curr = flags;
	while (curr && curr->type != type)
		curr = curr->next;
	return (curr);
}

void	free_flags(t_flag **flags)
{
	t_flag	*curr;
	t_flag	*tmp;

	curr = *flags;
	while (curr)
	{
		tmp = curr;
		curr = tmp->next;
		free(tmp);
	}
	*flags = NULL;
}

t_modifier	*create_modifier(void)
{
	char		*flags_str;
	t_modifier	*modifier;
	t_flag		*new_flag;

	flags_str = "'-0.# +";
	modifier = (t_modifier *)malloc(sizeof(t_modifier));
	if (!modifier)
		return (NULL);
	modifier->length = -1;
	modifier->precision = -1;
	modifier->flags = NULL;
	while (*flags_str)
	{
		new_flag = create_flag(*flags_str);
		if (!new_flag)
		{
			free_flags(&(modifier->flags));
			free(modifier);
			return (NULL);
		}
		add_flag(modifier, new_flag);
		flags_str++;
	}
	return (modifier);
}
