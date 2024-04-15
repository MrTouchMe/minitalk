/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:45:10 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/04/15 20:00:17 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	send_bit(pid_t pid, char bit)
{
	kill(pid, SIGUSR1);
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

		}
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
	pid_t				process_id;
	char				*message;
	char				*message_len;

	sa1.sa_sigaction = signal_handler();
	if (argc != 3)
		ft_printf("argc != 3\n");
	process_id = ft_atoi(argv[1]);
	ft_printf("%d", process_id);
	message = argv[2];
	message_len = ft_itoa(ft_strlen(argv[2]));
	return (0);
	sigaction(SIGUSR1, &sa1, NULL);
	sigaction(SIGUSR2, &sa2, NULL);
}
