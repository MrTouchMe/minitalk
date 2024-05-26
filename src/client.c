/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:45:10 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/05/26 17:24:10 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void send_bit(pid_t pid, char bit)
{
	if (bit)
	{
		kill(pid, SIGUSR1);
		ft_printf("Sending SIGUSR1 to %d\n", pid);
	}
	else
	{
		kill(pid, SIGUSR2);
		ft_printf("Sending SIGUSR2 to %d\n", pid);
	}
	usleep(500);
}

int send_message(char* message, int pid)
{
	int bit;

	while (*message)
	{
		bit = 7;
		while (bit >= 0)
		{
			send_bit(pid, (*message >> bit) & 1);
			bit--;
		}
		message++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	int server_pid;

	server_pid = ft_atoi(argv[1]);
	if (argc != 3)
	{
		ft_printf(stderr, "Usage: %s <server_pid> <message>\n", argv[0]);
		return 1;
	}
	send_message(argv[2], server_pid);
	return 0;
}
