#include "minitalk.h"


static char	*g_msg = NULL;

void	message_received(void)
{
	ft_printf("Received: %s\n", g_msg);
	free(g_msg);
	g_msg = ft_strdup("");
}

void	concat_char(char c)
{
	char *new_message;
	char str[2];

	str[0] = c;
	str[1] = '\0';
	if (ft_strlen(g_msg) == 0)
	{
		g_msg = str;
		return ;
	}
	new_message = ft_strjoin(g_msg, str);
	free(g_msg);
	g_msg = new_message;
}

void	handle_signal(int sig)
{
	static int byte = 0;
	static int bit_index = 0;

	if (sig == SIGUSR1)
		byte |= (1 << bit_index);
	bit_index++;
	if (bit_index == 8)
	{
		concat_char(byte);
		if (byte == '\0')
			message_received();
		bit_index = 0;
		byte = 0;
	}
}

int	main(void)
{
	struct sigaction sa;
	pid_t pid;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = handle_signal;
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) ==
		-1)
	{
		ft_putstr_fd("sigaction error\n", 2);
		exit(EXIT_FAILURE);
	}
	pid = getpid();
	ft_printf("%d\n", pid);
	g_msg = ft_strdup("");
	while (1)
		pause();
	free(g_msg);
	return (0);
}