#include "minitalk.h"

void	send_sig(pid_t pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (((c >> i) & 1) == 1)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		usleep(100);
		i++;
	}
}

int	main(int ac, char *av[])
{
	pid_t	pid;
	char	*str;
	int		i;

	i = -1;
	if (ac != 3)
	{
		ft_printf("Example: %s PID MESSAGE\n", av[0]);
		return (1);
	}
	while (av[1][++i])
	{
		if (!ft_isdigit(av[1][i]))
			return (ft_printf("Nice try!"), 0);
	}
	i = -1;
	pid = ft_atoi(av[1]);
	str = av[2];
	while (str[++i])
		send_sig(pid, str[i]);
	send_sig(pid, '\n');
	return (0);
}
