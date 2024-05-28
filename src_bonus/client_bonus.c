/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:55:34 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/05/28 02:59:51 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/minitalk_bonus.h"

void	send_bit(pid_t pid, char bit)
{
	if (bit)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(100);
}

int	send_message(char *message, int pid)
{
	int	bit;

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

int	main(int argc, char **argv)
{
	int	server_pid;

	server_pid = ft_atoi(argv[1]);
	if (argc != 3)
		return (1);
	send_message(argv[2], server_pid);
	return (0);
}
