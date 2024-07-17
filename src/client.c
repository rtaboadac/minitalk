#include "minitalk.h"

static int	g_msg_i = 0;

void	handle_signal(int sig)
{
	static int	bits_received = 0;

	if (sig == SIGUSR1)
	{
		;
		bits_received++;
	}
}

void	send_char(pid_t server_pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		i++;
	}
}

void	send_msg(char *msg)
{
	static int	msg_i = 0;
	static int	bit_i = 0;

	while ()
}

int	main(int argc, char *argv[])
{
	pid_t				server_pid;
	char				*message;
	size_t				i;
	size_t				len;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	sa.sa_handler = handle_signal;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(2);
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	len = ft_strlen(message);
	while (i <= len)
	{
		send_char(server_pid, message[i]);
		i++;
	}
	return (0);
}
