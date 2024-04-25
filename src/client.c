/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:45:10 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/04/25 16:19:37 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	send_bit(pid_t pid, char bit)
{
	if (bit % 2)
		kill(pid, BIT_ONE);
	else
		kill(pid, BIT_ZERO);
}

static bool	server_respond(bool read, bool write)
{
	static bool	respond;

	if (read)
		return (respond);
	else
		respond = write;
	return (respond);
}
// foo 00001010		client

// send_bit(foo >> 7) 0000000 0	0
// send_bit(foo >> 6) 0000000 0	0
// send_bit(foo >> 5) 0000000 0	0
// send_bit(foo >> 4) 0000000 0	0
// send_bit(foo >> 3) 0000000 1	1
// send_bit(foo >> 2) 0000001 0	2
// send_bit(foo >> 1) 0000010 1	5
// send_bit(foo >> 0) 0000101 0	10


// 		   |      |
// foo >> 3 = 00000001

// i = 7;

// send foo >> i;

// server:



int	send_message(char* message, size_t len, int pid)
{
	int			i;
	int			j;
	char		bit;

	i = 0;
	while (i < len)
	{
		j = 7;
		while (j >= 0)
		{
			send_bit(pid, message[i] << j);
			// while (/*timeout < 100 && !server_respond(true, false)*/)
			// {

			// }
			// if timeout
			// 	return (1)
			j++;
			server_respond(false, false);
		}
		i ++;
	}
	return (0);
}

void	signal_handler(void)
{
	if (SIGUSR1)
		server_respond(false, true);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	t_client			data;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	if (argc != 3)
		ft_printf("argc != 3\n");
	data.server_pid = ft_atoi(argv[1]);
	ft_printf("%d", data.server_pid);
	data.message = argv[2];
	data.size = ft_itoa(ft_strlen(data.message));
	sigaction(SIGUSR1, &sa, NULL);
	if (!send_message((char*)data.size, (sizeof data.size), data.server_pid))
		return (send_message(data.message, data.size, data.server_pid));
	return(1);
}
