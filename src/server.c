/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:55:33 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/05/24 17:28:22 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void server_sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)info;
	(void)ucontext;

	static int bit_count;
	static char c;

	if(sig == BIT_ONE)
	{
		c |= (1 << bit_count);
	}
	bit_count++;
	if(bit_count == 8)
	{
		write(1, &c, 1);
	}
	bit_count = 0;
	c = 0;
}

int	main(void)
{
	struct sigaction	sa;
	// t_server*			data;

	// data = get_client_data();
	ft_printf("server PID: %d\n", getpid());
	sa.sa_sigaction = /*&*/server_sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	sigemptyset(&sa.sa_mask);
	// sigaddset(&sa.sa_mask, SIGUSR1);
	// sigaddset(&sa.sa_mask, SIGUSR2);
	while (true)
	{
		pause();
	}
	return (0);
}

// void	sigint_handler(void)
// {
// 	t_server*	data;

// 	// data = get_client_data();
// 	if (data->message)
// 	free(data->message);
// 	exit(SIGINT);
// }

// static t_server*	get_client_data(void)
// {
// 	static t_server	data;

// 	return (&data);
// }

// static t_server* get_client_data();

// void	server_sig_handler(int sig, siginfo_t *info, void *ucontext)
// {
// 	t_server	*data = get_client_data();
// 	static int byte = 0;
// 	static int byte_index = 0;
// 	static int message_index = 0;

// 	(void)ucontext;
// 	// data = get_client_data();
// 	if (!data->client_pid || data->client_pid == info->si_pid)
// 	{
// 		if (!data->client_pid)
// 		{
// 			data->client_pid = info->si_pid;
// 			// data->size = sizeof(int);
// 			data->message = ft_calloc(sizeof(int), 1);
// 			data->init = false;
// 		}
// 		// else
// 		// {

// 		// }
// 		if (sig == BIT_ONE)
// 		{
// 			byte = (byte << 1) | 1;
// 			byte_index++;
// 		}
// 		else if (sig == BIT_ZERO)
// 		{
// 			byte = byte << 1;
// 			byte_index++;
// 		}
// 		if (byte_index == 7)
// 		{
// 			data->message[message_index++] = byte;
// 			byte_index = 0;
// 		}
// 		if ((size_t)message_index == data->size-1)
// 		{
// 			if (!data->init)
// 			{
// 				int i = data->size - 1;
// 				while (i >= 0)
// 				{
// 					((char*)data->size)[i] = data->message[i];
// 					i--;
// 				}
// 				free(data->message);
// 				data->message = ft_calloc(data->size + 1, 1);
// 				message_index = 0;
// 				data->init = true;
// 			}
// 			else
// 			{
// 				int i = 0;
// 				while (message_index < data->size)
// 				{

// 				}
// 				ft_printf("%s\n", data->message);
// 				free(data->message);
// 				message_index = 0;
// 			}
// 		}
// 	}
// }
