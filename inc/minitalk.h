#ifndef MINITALK_H
# define MINITALK_H
# include "ft_printf.h"
# include "libft.h"
# include <limits.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_msg
{
	char	*str;
	int		len;
	int		last_sent;
}			t_msg;

#endif
