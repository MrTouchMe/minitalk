/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:45:10 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/04/19 18:32:29 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	send_bit(pid_t pid, char bit)
{
	if (bit == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
}

void	send_message(pid_t pid, char *message)
{
	int		i;
	int		j;
	char	bit;

	i = 0;
	while (message[i])
	{
		j = 0;
		while (j < 8)
		{
			j++;
		}
		i ++;
	}
}

void	signal_handler(void)
{
	if (SIGUSR1)
	{
	}
	else if (SIGUSR2)
	{
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa1;
	struct sigaction	sa2;
	pid_t				pid;
	char				*message;
	char				*message_len;

	sa1.sa_sigaction = signal_handler;
	sa1.sa_flags = SA_SIGINFO;
	sa2.sa_sigaction = signal_handler;
	sa2.sa_flags = SA_SIGINFO;
	if (argc != 3)
		ft_printf("argc != 3\n");
	pid = ft_atoi(argv[1]);
	ft_printf("%d", pid);
	message = argv[2];
	message_len = ft_itoa(ft_strlen(argv[2]));
	sigaction(SIGUSR1, &sa1, NULL);
	sigaction(SIGUSR2, &sa2, NULL);
	return (0);
}
