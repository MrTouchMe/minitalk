/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:55:33 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/04/25 16:13:09 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	server_sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	t_server*	data;

	data = get_client_data(true, (t_server *)NULL);
	if (!data->client_pid || data->client_pid == info->si_pid)
	{
		if (!data->client_pid)
			data->client_pid = info->si_pid;
		if (sig == BIT_ONE)
		{
			data->byte;
		}
		else if (sig == BIT_ZERO)
		{

		}
	}
}

static t_server*	get_client_data(bool read, t_server* write)
{
	static t_server	data;

	if (read)
		return (&data);
	else
		data = *write;
	return (&data);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("server PID: %d\n", getpid());
	ft_bzero(&sa, (sizeof sa));
	sa.sa_sigaction = &server_sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pause();
	return (0);
}
