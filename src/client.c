/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 00:48:59 by rtaboada          #+#    #+#             */
/*   Updated: 2024/07/20 00:52:33 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_msg	g_msg;

static void	send_next_char_bit(pid_t server_pid)
{
	static int	bit_i = 0;
	static int	str_i = 0;
	int			signal;

	if (str_i > g_msg.len)
		exit(0);
	if (g_msg.str[str_i] & (1 << bit_i++))
		signal = SIGUSR1;
	else
		signal = SIGUSR2;
	if (kill(server_pid, signal) == -1)
	{
		ft_printf("Error on send signal %d", signal);
		exit(EXIT_FAILURE);
	}
	if (bit_i == 8)
	{
		g_msg.last_sent = str_i;
		str_i++;
		bit_i = 0;
	}
}

static void	handle_signal(int sig, siginfo_t *info, void *context)
{
	if (sig == SIGUSR1)
		send_next_char_bit(info->si_pid);
	(void)context;
}

int	main(int argc, char *argv[])
{
	pid_t				server_pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("Client must have 2 arguments (server p_id and message)\n");
		exit(EXIT_FAILURE);
	}
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Error on sigaction with SIGUSR1 signal.\n");
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	g_msg.len = ft_strlen(argv[2]);
	g_msg.str = argv[2];
	g_msg.last_sent = -1;
	send_next_char_bit(server_pid);
	while (1)
		pause();
	return (0);
}
