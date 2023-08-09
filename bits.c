#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int nb = atoi(av[1]);
    int i = 7;
    while (i >= 0)
    {
        printf("%d", (nb >> i) & 1);
        i--;
    }
}


// CLIENT
void	char_sender(char c, int pid)
{
	int	i;

	i = 0;
	g_msg_received = 0;
	while (i <= 7)
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
		i++;
		g_msg_received = 0;
	}

    f (str[i])
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

// SERVER

void	char_receiver(int signum, siginfo_t *client, void *context)
{
	int			pid;
	(void)		context;
	static int	bit;
	static char letter;

	pid = client->si_pid;
	if (signum == SIGUSR2)
		letter |= (0x01 << bit);
	kill(pid, SIGUSR1);
	bit++;
	if (bit == 8)
	{
		bit = 0;
		ft_putchar(letter);
		letter = 0;
	}
}