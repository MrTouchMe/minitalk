/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:55:33 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/04/25 17:48:16 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	server_sig_handler(int sig, siginfo_t *info/* ,void *ucontext*/)
{
	t_server*	data;

	// (void)ucontext;
	data = get_client_data();
	if (!data->client_pid || data->client_pid == info->si_pid)
	{
		data->timeout = 0;
		if (!data->client_pid)
		{
			data->client_pid = info->si_pid;
			data->size = sizeof(size_t);
			data->message = ft_calloc(sizeof(size_t), 1);
			data->init = false;
		}
		// else
		// {

		// }
		if (sig == BIT_ONE)
		{
			// add 1 bit on right side (byte << 1 | 1)
			// byte_index++
		}
		else if (sig == BIT_ZERO)
		{
			// add 1 bit on right side (byte << 1 | 0)
			// byte_index++
		}
		// if byte_index == 7
			// save full byte at message[message_index++] and byte_index = 0
		// if message_index == size
		// {
			// if !init
			// {
				// int i = size - 1;
				// while (i >= 0)
				// (char*)size[i] = message[i];
				// write the size nummber of bytes from message in size, message_index = 0 and free ,message pointer
					// ft_calloc(size + 1, 1);
			// }
		// }
		// else
		// print message and free | bzero data struct
		// }
	}
}

void	sigint_handler(int sig, siginfo_t* info, void* ucontext)
{
	t_server*	data;

	data = get_client_data(true, (t_server *)NULL);
	if (data->message)
		free(data->message);
	exit(SIGINT);
}

static t_server*	get_client_data()
{
	static t_server	data;

	return (&data);
}

int	main(void)
{
	struct sigaction	sa;
	struct sigaction	sa_int;
	t_server*			data;

	data = get_client_data();
	ft_printf("server PID: %d\n", getpid());
	ft_bzero(&sa, sizeof(sa));
	ft_bzero(&sa, sizeof(sa_int));
	sa_int.sa_sigaction = &sigint_handler;
	sa.sa_sigaction = &server_sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGINT, &sa_int, NULL);

	while(true)
	{
		usleep(100);
		if (data->client_pid)
			data->timeout += 100;
		// if (data->timeout > 2000)
			// delete data
	}
	return (0);
}
