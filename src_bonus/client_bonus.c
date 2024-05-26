/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:55:34 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/05/24 18:06:52 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/minitalk_bonus.h"

#include "../include/minitalk.h"

void	send_bit(pid_t pid, char bit)
{
	if (bit % 2)
		kill(pid, BIT_ONE);
	else
		kill(pid, BIT_ZERO);
}

int	send_message(char* message, int pid)
{
	int	pos;
	int	bit;

	while(*message)
	{
		pos = 0;
		bit = 7;
		while (bit >= 0)
		{
			send_bit(pid, (*message/*[pos]*/ << bit) & 1);
			bit--;
			// pause();
		}
		pos++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	int server_pid;

	server_pid = ft_atoi(argv[1]);
	if (argc != 3)
		return (1);
	send_message((argv[2]), server_pid);
	return (0);
}
