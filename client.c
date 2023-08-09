/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvina <alvina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:05:31 by alvina            #+#    #+#             */
/*   Updated: 2023/02/12 18:36:04 by alvina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
int     g_msg_received;

void	char_sender(char c, int pid)
{
	int	i;

	i = 7;
	g_msg_received = 0;
	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(EXIT_FAILURE);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(EXIT_FAILURE);
		}
		while (!g_msg_received)
			pause();
		i--;
		g_msg_received = 0;
	}
}

void	test(int signum, siginfo_t *client, void *context)
{
	(void)client;
	(void)context;
	if (signum == SIGUSR1)
		g_msg_received = 1;
	if (signum == SIGUSR2)
		exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	int					pid;
	int					i;
	char				*str;
	struct sigaction	sa;

	i = 0;
	if (ac != 3)
	{
		ft_putstr("Usage : ./client <server PID> <message>\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(av[1]);
	str = av[2];
	sa.sa_sigaction = &test;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	if (str[i])
	{
		while (str[i])
		{
			char_sender(str[i], pid);
			i++;
		}
		char_sender('\n', pid);
	}
	char_sender('\0', pid);
}