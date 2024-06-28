/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:47:53 by rtaboada          #+#    #+#             */
/*   Updated: 2024/06/21 19:53:26 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flag
{
	char			type;
	int				is_checked;
	struct s_flag	*next;
}					t_flag;

typedef struct s_modifier
{
	t_flag			*flags;
	int				length;
	int				precision;
}					t_modifier;
t_flag				*get_flag(t_flag *flags, char type);
void				free_flags(t_flag **flags);
t_modifier			*create_modifier(void);
t_flag				*create_flag(char type);
void				add_flag(t_modifier *modifier, t_flag *new_flag);
void				set_modifier(const char **format, t_modifier *modifier,
						va_list *args);
int					parse_flags(const char **format, t_modifier *modifier);
int					parse_length(const char **format, va_list *args);
int					parse_precision(const char **format, va_list *args);
void				print_element(char element, va_list *args,
						t_modifier modifier, int *printed_chars);
int					ft_printf(const char *format, ...);
ssize_t				ft_putstr(char *s);
ssize_t				ft_putptr(uintptr_t ptr);
int					ft_putnchar(char c, int n);
int					ft_putnbr(int n, t_modifier modifier);
int					ft_putnbru(unsigned int n, t_modifier modifier);
int					ft_puthex(unsigned int num, short int upper,
						t_modifier modifier);
int					ft_putchar(char c);

#endif
