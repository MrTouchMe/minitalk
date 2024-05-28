/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:55:35 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/05/28 02:59:00 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/minitalk_bonus.h"

void	server_sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	static int	bit_count = 0;
	static char	c = 0;

	(void)ucontext;
	(void)info;
	if (sig == SIGUSR1)
		c |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &c, 1);
		bit_count = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = server_sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (true)
		pause();
	return (0);
}
