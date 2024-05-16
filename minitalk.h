#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <bits/sigaction.h>
# include "Libft/Headers/libft.h"

typedef struct vars
{
	int	c;
	int	bit;
}		t_vars;

void	send_sig(pid_t pid, char c);
void	sig_user1(int sig);
void	sig_user2(int sig);

#endif