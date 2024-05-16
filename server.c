#include "minitalk.h"

static t_vars	g_vars = {0, 0};

void	sig_user1(int sig)
{
	(void)sig;
	g_vars.c |= (1 << g_vars.bit);
	g_vars.bit++;
	if (g_vars.bit == 8)
	{
		write(1, &g_vars.c, 1);
		g_vars.c = 0;
		g_vars.bit = 0;
	}
}

void	sig_user2(int sig)
{
	(void)sig;
	g_vars.bit++;
	if (g_vars.bit == 8)
	{
		write(1, &g_vars.c, 1);
		g_vars.c = 0;
		g_vars.bit = 0;
	}
}

void	setup_signal_handlers(void)
{
	struct sigaction	sa1;
	struct sigaction	sa2;

	sa1.sa_handler = sig_user1;
	sigemptyset(&sa1.sa_mask);
	sa1.sa_flags = 0;
	sa2.sa_handler = sig_user2;
	sigemptyset(&sa2.sa_mask);
	sa2.sa_flags = 0;
	sigaction(SIGUSR1, &sa1, NULL);
	sigaction(SIGUSR2, &sa2, NULL);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Your PID: %d\n", pid);
	setup_signal_handlers();
	while (1)
	{
	}
	return (0);
}
